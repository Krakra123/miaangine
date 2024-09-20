#include "engine.h"

#include <stdexcept>

#include <debug/log-system.h>

GLFWwindow* mia::mainWindow = nullptr;

void mia::InitEngine()
{
    if (!glfwInit()) {
        LogManager::LogError("Failed to init GLFW");
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

        // GLFWwindow* wwww = glfwGetCurrentContext();
        // int window_width, window_height;
        // glfwGetFramebufferSize(wwww, &window_width, &window_height);
        // printf(":: %d %d", window_width, window_height);

    // glewExperimental = GL_TRUE;
    // GLenum err = glewInit(); 

    // if (GLEW_OK != err)
    // {
    //     /* Problem: glewInit failed, something is seriously wrong. */
    //     fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

    // }
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