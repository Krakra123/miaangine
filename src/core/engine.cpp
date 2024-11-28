#include "core/engine.hpp"

#include <stdexcept>

#include "core/debug/log-system.hpp"

GLFWwindow* mia::mainWindow = nullptr;

void mia::InitWindow(int w, int h)
{
    if (!glfwInit()) {
        // LogManager::LogError("Failed to init GLFW");
    }

    if (w <= 0 || h <= 0) {
        // LogManager::LogError("Window height and width must be positive");
        throw std::logic_error("Window height and width must be positive");
    }

    mainWindow = glfwCreateWindow(
        w, h, 
        "", 
        NULL, 
        NULL
    );

	glfwMakeContextCurrent(mainWindow);

    if (glewInit() != GLEW_OK) {
        // LogManager::LogError("Failed to init Glew");
    }
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