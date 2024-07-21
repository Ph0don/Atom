#include "Application.h"

#include <glfw/glfw3.h>

#include "Win32Window.h"

namespace atom
{
	Application& Application::GetInstance()
	{
		static Application instance;
		return instance;
	}
	void Application::Init(const Properties& props)
	{
		Window* pWindow;
#ifdef AT_PLATFORM_WINDOWS
		m_Window.reset(new Win32Window(props.width, props.height, props.name));
#elif defined(AT_PLATFORM_LINUX)
#else
		std::clog << "Failed to create window! Only Windows and Linux currently supported." << std::endl;
		return;
#endif
	}
	void Application::Run()
	{
		while (true)
		{
			m_Window->OnUpdate();
			if (m_Window->ShouldClose())
				break;
			
		}
	}

}