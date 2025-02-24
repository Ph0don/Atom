#include "Window.h"

#include <iostream>

namespace atom
{
	Window::Window(uint32_t width, uint32_t height, const char* title)
		:m_Width(width), m_Height(height), m_Title(title)
	{
	}
	Window::~Window()
	{
	}
}
