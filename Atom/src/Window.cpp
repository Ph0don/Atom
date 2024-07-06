#include "Window.h"

#include <iostream>
#include <glfw/glfw3.h>

namespace atom
{
	Window::Window(uint32_t width, uint32_t height, const char* title)
		:m_Width(width), m_Height(height), m_Title(title), m_Window(nullptr)
	{
		if (!glfwInit())
		{
			std::clog << "Failed to initialize GLFW" << std::endl;
			return;
		}
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			glfwTerminate();
			std::clog << "Failed to create window" << std::endl;
			return;
		}
		glfwMakeContextCurrent(m_Window);

	}
	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}
	void Window::OnUpdate()
	{
		glfwPollEvents();
	}
	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_Window);
	}
}