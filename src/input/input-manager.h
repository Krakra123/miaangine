#ifndef _MIA_INPUT_MANAGER_H
#define _MIA_INPUT_MANAGER_H

#include <memory>
#include <vector>
#include <glfw3.h>

#include "util/singleton.hpp"
#include "event/event.h"

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

        static std::shared_ptr<Event> MakeInputEvent(std::vector<int> keyCodeList);
        static void AddKeyInputToEvent(std::shared_ptr<Event>& event, int keycode);
    };
}

#endif