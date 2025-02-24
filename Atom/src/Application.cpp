#include "Application.h"

#include "Window.h"
#ifdef AT_PLATFORM_WINDOWS
#include "Win32Window.h"
#elif defined(AT_PLATFORM_LINUX)
#include "GLFWWindow.h"
#endif
#include <GLFW/glfw3.h>

#include <iostream>
#include <mutex>

#include <imgui/imgui.h>

static atom::Application* s_Application = nullptr;

namespace atom
{
    Application::Application(const Properties& props)
    {
        static std::mutex mutex;
        std::unique_lock<std::mutex> lock(mutex);
        if (s_Application == nullptr)
            s_Application = this;
        lock.unlock();

#ifdef AT_PLATFORM_WINDOWS
        m_Window.reset(new Win32Window(props.width, props.height, props.name));
#elif defined(AT_PLATFORM_LINUX)
        m_Window.reset(new GLFWWindow(props.width, props.height, props.name));
#else
        std::clog << "Failed to create window! Only Windows and Linux currently supported." << std::endl;
        return;
#endif
    }
    
    Application::~Application(){}
    Application* Application::GetInstance()
    {
        if (s_Application == nullptr)
        {
            std::clog << "GetInstance called before init!";
        }

        return s_Application;
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
