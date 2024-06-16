#ifndef _MIA_ENTITY_MANAGER_HPP
#define _MIA_ENTITY_MANAGER_HPP

#include <typeindex>
#include <functional>
#include <list>
#include <unordered_map>

#include "entity.h"
#include "debug/log-system.h"

// TODO move error handling to the generic system
namespace mia
{
    template <class T>
    void RegisterComponent(T* component);

    template <class T>
    void UnregisterComponent(T* component);

    template <class T>
    void IterateComponents(std::function<void(T&)> method);

    template <class T>
    void IterateParentChildComponents(std::function<void(T&, T&)> method);

    // Data
    extern std::unordered_map<std::type_index, std::list<Entity*>> allComponentList;

    // Template definition
    template <class T>
    void RegisterComponent(T* component)
    {
        static_assert(std::is_base_of<Entity, T>::value, "T must be derived from Entity");
        
        if (allComponentList.find(typeid(T)) == allComponentList.end()) {
            allComponentList.insert(std::make_pair<std::type_index, std::list<Entity*>>(
                typeid(T),
                std::list<Entity*>()
            ));
        }

        allComponentList[typeid(T)].push_back(component);
    }

    template <class T>
    void UnregisterComponent(T* component)
    {
        static_assert(std::is_base_of<Entity, T>::value, "T must be derived from Entity");

        if (allComponentList.find(typeid(T)) != allComponentList.end()) {
            allComponentList[typeid(T)].remove(component);
        }
        else {
            // LogWarn("Component invalid.");
        }
    }

    template <class T>
    void IterateComponents(std::function<void(T&)> method)
    {
        static_assert(std::is_base_of<Entity, T>::value, "T must be derived from Entity");
        
        auto targetIterator = allComponentList.find(typeid(T));
        if (targetIterator != allComponentList.end()) {
            for (auto& component : targetIterator->second) {
                if (!component->IsActive()) continue;

                method(dynamic_cast<T&>(*component));
            }
        }
        else {
            // LogWarn("Component T invalid.");
        }
    }

    template <class T>
    void IterateParentChildComponents(std::function<void(T&, T&)> method)
    {
        static_assert(std::is_base_of<Entity, T>::value, "T must be derived from Entity");

        auto targetIterator = allComponentList.find(typeid(T));
        if (targetIterator != allComponentList.end()) {
            for (auto& component : targetIterator->second) {
                if (!component->IsActive()) continue;

                try {
                    method(dynamic_cast<T&>(*component), dynamic_cast<T&>(component->GetParentComponent()));
                }
                catch (std::invalid_argument& exception) {
                    // TODO add debug
                }
            }
        }
        else {
            // LogWarn("Component T invalid.");
        }
    }
}

#endif