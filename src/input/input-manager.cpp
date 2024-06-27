#include "input-manager.h"

#include "core/engine.h"
#include <stdio.h>

namespace mia
{
    void HandleGLFWInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        printf("PRESS: %d %d %d %d\n", key, scancode, action, mods);
        
    }

    void InputManager::Init()
    {
        glfwSetKeyCallback(mainWindow, HandleGLFWInputCallback);
    }

    void InputManager::Update()
    {
        glfwPollEvents();
    }

    bool InputManager::GetKey(int keycode)
    {

    }
    bool InputManager::GetKeyDown(int keycode)
    {

    }
    bool InputManager::GetKeyUp(int keycode)
    {

    }

    std::shared_ptr<Event> InputManager::MakeInputEvent(std::vector<int> keyCodeList)
    {

    }
    void InputManager::AddKeyInputToEvent(std::shared_ptr<Event>& event, int keycode)
    {

    }
}