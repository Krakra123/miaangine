#include "engine.h"

#include <stdexcept>
#include <glfw3.h>

#include <debug/log-system.h>

GLFWwindow* mia::mainWindow = nullptr;

void mia::InitEngine()
{
    if (!glfwInit()) {
        throw std::runtime_error("Failed to init GLFW");
    }
}

void mia::MakeWindow(int w, int h)
{
    if (w <= 0 || h <= 0) {
        LogManager::LogError("Window height and width must be positive");
        throw std::logic_error("Window height and width must be positive");
    }

    mainWindow = glfwCreateWindow(
        w, h, 
        "", 
        NULL, 
        NULL
    );

    glfwMakeContextCurrent(mainWindow);
}

void mia::TerminateEngine()
{
    glfwDestroyWindow(mainWindow);
    glfwTerminate();
}

bool mia::IsRunning()
{
    return !glfwWindowShouldClose(mainWindow);
}