#include "Win32Window.h"

#include <iostream>
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_win32.h"
//#include <imgui/backends/imgui_impl_win32.h>
//#include <imgui/backends/imgui_impl_dx12.h>

namespace atom
{
	Win32Window::Win32Window(uint32_t width, uint32_t height, const char* title)
		: Window(width, height, title), m_ShouldClose(false), m_WindowHandle(nullptr), 
		  m_Instance(GetModuleHandle(nullptr))
	{
		LPCSTR classTitle = "AtomClass";

		WNDCLASSEX wc = {};
		wc.cbSize = sizeof(wc);
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = (WNDPROC)Win32Window::WndProc;
		wc.hInstance = m_Instance;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hCursor = LoadCursor(0, IDC_ARROW);
		wc.hbrBackground = 0;
		wc.lpszMenuName = nullptr;
		wc.lpszClassName = classTitle;

		if (!RegisterClassEx(&wc))
		{
			std::clog << "Failed to register window class!" << std::endl;
			return;
		}

		DWORD style = WS_OVERLAPPEDWINDOW | WS_CAPTION;
		DWORD styleEx = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

		RECT rect{};
		rect.left =		static_cast<long>(0);
		rect.top =		static_cast<long>(0);
		rect.right =	static_cast<long>(width);
		rect.bottom =	static_cast<long>(height);

		AdjustWindowRectEx(&rect, style, false, styleEx);

		m_WindowHandle = CreateWindowEx(styleEx, classTitle, title, style,
						 0,0, static_cast<int>(rect.right - rect.left),
						 static_cast<int>(rect.bottom - rect.top),
						 nullptr, nullptr, m_Instance, static_cast<void*>(this));

		if (m_WindowHandle == nullptr)
		{
			std::clog << "Failed to create Win32 window!" << std::endl;
			return;
		}

		ShowWindow(m_WindowHandle, SW_SHOWNORMAL);

		ImGui::CreateContext();
		auto& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

	}
	Win32Window::~Win32Window()
	{
		if (!DestroyWindow(m_WindowHandle))
		{
			std::clog << "Failed to destroy window!" << std::endl;
		}
	}
	void Win32Window::OnUpdate()
	{
		MSG msg;
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				m_ShouldClose = true;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}
	bool Win32Window::ShouldClose() const
	{
		return m_ShouldClose;
	}
	LRESULT Win32Window::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		Win32Window* pWindow = reinterpret_cast<Win32Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
		switch (msg)
		{
		case WM_NCCREATE:
		{
			CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
			Win32Window* pWindow = static_cast<Win32Window*>(pCreate->lpCreateParams);
			SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWindow));

			if (pWindow)
			{
				pWindow->m_WindowHandle = hwnd;
			}
		}
		break;

		case WM_CLOSE:
		{
			PostQuitMessage(0);
		}
		break;
		}

		return DefWindowProc(hwnd,msg,wParam,lParam);
	}
}
