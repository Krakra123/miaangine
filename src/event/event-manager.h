#ifndef _MIA_EVENT_MANAGER_H
#define _MIA_EVENT_MANAGER_H

#include <string_view>
#include <functional>
#include <unordered_map>
#include <list>

#include "util/singleton.hpp"

namespace mia
{
    class EventManager : public Singleton<EventManager>
    {
        friend class Singleton<EventManager>;
    public:
        void RegisterEvent(const std::string_view& event, std::function<void()>&& callback);
        // TODO Make unregister real
        // void UnregisterEvent(const std::string_view& event, std::function<void()>& callback);

        void RaiseEvent(const std::string_view& event);
    
    private:
        std::unordered_map<std::string_view, std::list<std::function<void()>>> _eventsMap;
    };
}

#endif