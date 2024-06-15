#ifndef _MIA_INPUT_MANAGER_H
#define _MIA_INPUT_MANAGER_H

#include <glfw3.h>

#include "util/singleton.hpp"

namespace mia
{
    // TODO maybe set all keycode
    enum KeyCode 
    {

    };

    class Input : public Singleton<Input>
    {
    public:
        static bool GetKey(int keycode);
        static bool GetKeyDown(int keycode);
        static bool GetKeyUp(int keycode);

        static void Init();
    };
}

#endif