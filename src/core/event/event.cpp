#include "core/event/event.hpp"

namespace mia
{
    Event::Event() = default;

    void Event::AddCallback(std::function<void()>&& callback)
    {
        _callbackList.push_back(callback);
    }

    void Event::Raise()
    {
        _callbackList.remove_if([](std::function<void()> const& callback) {
            return (!callback);
        });

        for (std::function<void()> callback : _callbackList) {
            callback();
        }
    }
}