#ifndef _MIA_ENTITY_HPP
#define _MIA_ENTITY_HPP

#include <typeindex>
#include <list>

namespace mia
{
    class Entity
    {
    public:
        // Constructor Destructor
        Entity(bool initActive = true);
        virtual ~Entity();

        // Public methods
        bool IsActive() const;
        bool SetActive(bool newState);

        template <class T>
        T& AddComponent(T* component);

        template <class T>
        void RemoveComponent(T* component);

        template <class T>
        T& GetComponent();
        Entity& GetComponent(std::type_index typeID);

        template <class T>
        bool ContainComponent() const;
        bool ContainComponent(Entity* component) const;

        Entity& GetMaster();

        void SetParent(Entity* parent);
        void AddChild(Entity* child);

        Entity& GetParent();
        Entity& GetChild(int index = 0);
        std::list<Entity*> GetChilds();

        Entity& GetParentComponent();

    private:
        // Data
        bool _localActive;
        bool _parentActive;

        Entity* _master;
        std::list<Entity*> _components;
        
        Entity* _parent;
        std::list<Entity*> _childs;

        Entity* _parentComponent;

        // Private methods
        void UpdateActivationStateToChildren(bool state);
    };
}

#include "entity.inl"

#endif