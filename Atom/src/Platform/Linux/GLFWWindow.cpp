#include "GLFWWindow.h"

namespace atom
{

    GLFWWindow::GLFWWindow(uint32_t width, uint32_t height, const char* title):
        Window(width, height, title)
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods){if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);});

    }
    GLFWWindow::~GLFWWindow()
    {
        glfwDestroyWindow(m_Window);
    }

    void GLFWWindow::OnUpdate()
    {
        glfwPollEvents();

        if(glfwWindowShouldClose(m_Window))
            m_ShouldClose = true;
    }

    bool GLFWWindow::ShouldClose() const
    {
        return m_ShouldClose;
    }

}