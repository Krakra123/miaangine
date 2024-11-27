#include "core/input/input-manager.hpp"

#include "core/engine.hpp"
#include <stdio.h>
#include <string.h>

namespace mia
{
    char InputManager::KeysState[GLFW_KEY_LAST + 1];

    void HandleGLFWInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (action == GLFW_PRESS) {
            InputManager::KeysState[key] = MIA_KEY_PRESSED; 
        }
        if (action == GLFW_RELEASE) {
            InputManager::KeysState[key] = MIA_KEY_RELEASED; 
        }
    }

    void InputManager::Init()
    {
        memset(KeysState, -1, sizeof(KeysState));
        glfwSetKeyCallback(mainWindow, HandleGLFWInputCallback);
    }

    void InputManager::Update()
    {
        for (int i = 0; i <= GLFW_KEY_LAST; i++) {
            if (KeysState[i] == MIA_KEY_PRESSED) {
                KeysState[i] = MIA_KEY_HOLDING;
            }
            if (KeysState[i] == MIA_KEY_RELEASED) {
                KeysState[i] = -1;
            }
        }

        glfwPollEvents();
    }

    bool InputManager::GetKey(int keycode)
    {
        return KeysState[keycode] == MIA_KEY_PRESSED || KeysState[keycode] == MIA_KEY_HOLDING;
    }
    bool InputManager::GetKeyDown(int keycode)
    {
        return KeysState[keycode] == MIA_KEY_PRESSED;
    }
    bool InputManager::GetKeyUp(int keycode)
    {
        return KeysState[keycode] == MIA_KEY_RELEASED;
    }
}