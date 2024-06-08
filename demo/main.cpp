#include <iostream>

#include "mia.h"
#include <glfw3.h>

int main()
{
    mia::InitEngine();
    mia::MakeWindow(1280, 720);

    while (mia::IsRunning()) {
        glfwPollEvents();
    }

    mia::TerminateEngine();
}