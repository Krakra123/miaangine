#ifndef _MIA_ENTITY_MANAGER_HPP
#define _MIA_ENTITY_MANAGER_HPP

#include <map>
#include <vector>
#include <typeindex>
#include <functional>
#include <concepts>

#include "entity/entity.hpp"
#include "core/debug/log-system.hpp"

namespace mia
{
    class EntityManager
    {
    public:
        // Block constructor
        EntityManager() = delete;

        // Public method
        template <std::derived_from<Entity> T, std::invocable<T&> F>
        static void IterateEntities(F method);
    
    #ifdef _MIA__INTERNAL
        static void RegisterEntity(std::type_index type, Entity* entity);

        static void UnregisterEntity(std::type_index type, Entity* entity);
    #endif

        // Data
        static std::multimap<std::type_index, Entity*> EntitiesMap;
    };
}

#include "entity-manager.inl"

#endif