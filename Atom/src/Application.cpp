#include "Application.h"

#include <glfw/glfw3.h>

#include "Window.h"

namespace atom
{
	Application& Application::GetInstance()
	{
		static Application instance;
		return instance;
	}
	void Application::Init(const Properties& props)
	{
		m_Window.reset(new Window(props.width, props.height, props.name));
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