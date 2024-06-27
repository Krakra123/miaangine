#include <iostream>

#include "mia.h"
#include <glfw3.h>

int main()
{
    mia::InitEngine();
    mia::MakeWindow(1280, 720);

    mia::InputManager::Instance().Init();

    while (mia::IsRunning()) {
        mia::InputManager::Instance().Update();
    }

    mia::TerminateEngine();
}