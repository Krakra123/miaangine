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

    class InputManager : public Singleton<InputManager>
    {
        friend class Singleton<InputManager>;
    public:
        void Init();
        void Update();

        bool GetKey(int keycode);
        bool GetKeyDown(int keycode);
        bool GetKeyUp(int keycode);

        std::shared_ptr<Event> MakeInputEvent(std::vector<int> keyCodeList);
        void AddKeyInputToEvent(std::shared_ptr<Event>& event, int keycode);
    };
}

#endif