#include "entity.h"

#include <stdexcept>

#include "entity-manager.h"

namespace mia
{
    // Constructor Destructor
    Entity::Entity(bool initActive):
        _localActive(initActive),
        _parentActive(true),
        _master(nullptr),
        _components(std::list<Entity*>()),
        _parent(nullptr),
        _childs(std::list<Entity*>()),
        _parentComponent(nullptr)
    {}
    Entity::~Entity() = default;

    // Public methods
    bool Entity::IsActive() const
    {
        return _parentActive | _localActive;
    }
    bool Entity::SetActive(bool newState)
    {
        _localActive = newState;

        UpdateActivationStateToChildren(newState);

        return _parentActive | _localActive;
    }

    Entity& Entity::GetComponent(std::type_index typeID)
    {
        for (auto& component : _components) {
            if (std::type_index(typeid(*component)) == typeID) {
                return *component;
            }
        }

        throw std::invalid_argument("Entity does not contain target component");
    }

    Entity& Entity::GetMaster()
    {
        if (!_master) {
            throw std::invalid_argument("Entity does not has master");
        }

        return *_master;
    }

    bool Entity::ContainComponent(Entity* component) const
    {
        return std::find_if(
            _components.begin(), _components.end(),
            [&component](Entity* ent) {
                return ent == component;
        }) != _components.end();
    }

    void Entity::SetParent(Entity* parent)
    {
        _parent = parent;
        _parentActive = parent->_localActive;

        for (Entity* component : _components) {
            try {
                component->_parentComponent = &parent->GetComponent(typeid(*component));
            }
            catch (std::invalid_argument& expection) {
                component->_parentComponent = nullptr;
            }
        }
    }
    void Entity::AddChild(Entity* child)
    {
        _childs.push_back(child);

        child->SetParent(this);
    }

    Entity& Entity::GetParent()
    {
        if (!_parent) {
            throw std::invalid_argument("Entity does not have parent");
        }

        return *_parent;
    }
    Entity& Entity::GetChild(int index)
    {
        if (index < 0 || index >= static_cast<int>(_childs.size())) {
            throw std::out_of_range(0);
        }

        auto iterator = _childs.begin();
        std::advance(iterator, index);
        return **iterator;
    }
    std::list<Entity*> Entity::GetChilds()
    {
        return _childs;
    }

    Entity& Entity::GetParentComponent()
    {
        if (!_parentComponent) {
            throw std::invalid_argument("Entity does not have corresponding parent component");
        }

        return *_parentComponent;
    }

    // Private methods
    void Entity::UpdateActivationStateToChildren(bool state)
    {
        for (auto& child : _childs)
        {
            child->_parentActive = state;
        }
    }
}