#include <iostream>

#include "mia.h"
#include <glfw3.h>

int main()
{
    std::cout << "Hello World";

    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);

    mia::Init();
}