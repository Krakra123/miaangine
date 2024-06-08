#include "engine.h"

#include <stdexcept>
#include <glfw3.h>

#include <debug/log-system.h>

GLFWwindow* _engine_window;

void mia::InitEngine()
{
    if (!glfwInit()) {
        throw std::runtime_error("Failed to init GLFW");
    }
}

void mia::MakeWindow(int w, int h)
{
    if (w <= 0 || h <= 0) {
        LogError("Window height and width must be positive");
        throw std::logic_error("Window height and width must be positive");
    }

    _engine_window = glfwCreateWindow(
        w, h, 
        "", 
        NULL, 
        NULL
    );

    glfwMakeContextCurrent(_engine_window);
}

void mia::TerminateEngine()
{
    glfwDestroyWindow(_engine_window);
    glfwTerminate();
}

bool mia::IsRunning()
{
    return !glfwWindowShouldClose(_engine_window);
}