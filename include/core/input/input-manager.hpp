#ifndef _MIA_INPUT_MANAGER_H
#define _MIA_INPUT_MANAGER_H

#include <memory>
#include <vector>
#include "core/libinclude.hpp"

#define MIA_KEY_PRESSED 0 
#define MIA_KEY_HOLDING 1 
#define MIA_KEY_RELEASED 2

namespace mia
{
    // TODO maybe set all keycode
    enum KeyCode 
    {

    };

    class InputManager
    {
    public:
        // Block constructor
        InputManager() = delete;

        // Public methods
        static void Init();
        static void Update();

        static bool GetKey(int keycode);
        static bool GetKeyDown(int keycode);
        static bool GetKeyUp(int keycode);
    
    public:
        // Data 
        static char KeysState[GLFW_KEY_LAST + 1];
    };
}

#endif