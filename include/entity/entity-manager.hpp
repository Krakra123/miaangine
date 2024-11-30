#ifndef _MIA_ENTITY_MANAGER_HPP
#define _MIA_ENTITY_MANAGER_HPP

#include <map>
#include <vector>
#include <typeindex>
#include <functional>
#include <concepts>
#include <memory>

#include "entity/entity.hpp"
#include "core/debug/log-system.hpp"

namespace mia
{
    template <std::derived_from<entity> T, std::invocable<T&> F>
    void iterate_entities(F method);

#ifdef _MIA__INTERNAL
    void register_entity(std::type_index type, entity* entity);
    void unregister_entity(std::type_index type, entity* entity);

    extern std::multimap<std::type_index, entity*> entities_map;
#endif
}

#include "entity-manager.inl"

#endif