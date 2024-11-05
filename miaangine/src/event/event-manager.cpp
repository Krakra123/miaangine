#include "event-manager.h"

namespace mia
{
    std::unordered_map<std::string_view, std::list<std::function<void()>>> EventManager::_eventsMap;

    void EventManager::RegisterEvent(const std::string_view& event, std::function<void()>&& callback)
    {
        _eventsMap[event].push_back(callback);
    }
    // void EventManager::UnregisterEvent(const std::string_view& event, std::function<void()>& callback)
    // {
    //     _eventsMap[event].remove(callback);
    // }

    void EventManager::RaiseEvent(const std::string_view& event)
    {
        std::list<std::function<void()>>& callbackList = _eventsMap[event];

        callbackList.remove_if([](std::function<void()> const& callback) {
            return (!callback);
        });

        for (std::function<void()> callback : callbackList) {
            callback();
        }
    }
}
