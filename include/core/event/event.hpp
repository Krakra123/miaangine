#ifndef _MIA_EVENT_H
#define _MIA_EVENT_H

#include <functional>
#include <list>

namespace mia
{
    class Event
    {
    public:
        Event();

    public:
        void AddCallback(std::function<void()>&& callback);
        // TODO maybe remove callback real

        void Raise();

    private:
        std::list<std::function<void()>> _callbackList;
    };
}

#endif