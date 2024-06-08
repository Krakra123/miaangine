#ifndef _MIA_ENTITY_INL
#define _MIA_ENTITY_INL

#include <stdexcept>

#include "entity.h"
#include "entity-manager.h"

namespace mia
{
    // Public methods
    template <class T>
    T& Entity::AddComponent(T* component)
    {
        static_assert(std::is_base_of<Entity, T>::value, "T must be derived from Entity");

        _components.push_back(dynamic_cast<Entity*>(component));

        RegisterComponent(component);
        component->_master = this;

        return *component;
    }

    template <class T>
    void Entity::RemoveComponent(T* component)
    {
        static_assert(std::is_base_of<Entity, T>::value, "T must be derived from Entity");

        _components.remove_if([&component](std::reference_wrapper<Entity> const& ref) {
            return &ref.get() == &component;
        });

        UnregisterComponent(component);
        component._master.reset();
    }

    template <class T>
    T& Entity::GetComponent()
    {
        static_assert(std::is_base_of<Entity, T>::value, "T must be derived from Entity");

        for (auto component : _components) {
            if (T* targetComponent = dynamic_cast<T*>(component)) {
                return *targetComponent;
            }
        }

        throw std::invalid_argument("Entity does not contain target component");
    }

    template <class T>
    bool Entity::ContainComponent() const
    {
        static_assert(std::is_base_of<Entity, T>::value, "T must be derived from Entity");

        for (auto component : _components) {
            if (dynamic_cast<T*>(component)) {
                return true;
            }
        }
        return false;
    }
}

#endif