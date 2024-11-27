#include "entity/entity.hpp"

#include <stdexcept>

#include "entity/entity-manager.hpp"

namespace mia
{
    // Constructor Destructor
    Entity::Entity(std::type_index type) : _type(type)
    {
        _active = true;

        EntityManager::RegisterEntity(_type, this);
    }
    Entity::~Entity()
    {
        EntityManager::UnregisterEntity(_type, this);
    }

    // Public methods
    bool Entity::IsActive() const
    {
        return _active;
    }
    void Entity::SetActive(bool newState)
    {
        _active = newState;
    }
}