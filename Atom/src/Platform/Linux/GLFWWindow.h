#pragma once
#include "Window.h"

#include <GLFW/glfw3.h>

namespace atom
{

class GLFWWindow : public Window
{
public:
    GLFWWindow(uint32_t width, uint32_t height, const char* title);
    ~GLFWWindow();

    virtual void OnUpdate() override;

    virtual bool ShouldClose() const override;

private:
GLFWwindow* m_Window;

bool m_ShouldClose;
};

}