#ifndef _MIA_EVENT_MANAGER_H
#define _MIA_EVENT_MANAGER_H

#include <string_view>
#include <functional>
#include <unordered_map>
#include <list>

#include "util/singleton.hpp"

namespace mia
{
    // TODO: Rework this
    class EventManager
    {
    public:
        // Block contructor
        EventManager() = delete;

        static void RegisterEvent(const std::string_view& event, std::function<void()>&& callback);
        // static void UnregisterEvent(const std::string_view& event, std::function<void()>& callback);

        static void RaiseEvent(const std::string_view& event);
    
    private:
        static std::unordered_map<std::string_view, std::list<std::function<void()>>> _eventsMap;
    };
}

#endif