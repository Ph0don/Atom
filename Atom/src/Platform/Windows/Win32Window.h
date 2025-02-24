#pragma once
#include "Window.h"

#include <Windows.h>

namespace atom
{

	class Win32Window : public Window
	{
	public:
		Win32Window(uint32_t width, uint32_t height, const char* title);
		~Win32Window();

		void OnUpdate() override;
		bool ShouldClose()const override;

		static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	protected:
		HWND m_WindowHandle;
		HINSTANCE m_Instance;

		bool m_ShouldClose;
	};

}
