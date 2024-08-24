#ifndef _MIA_ENTITY_MANAGER_INL
#define _MIA_ENTITY_MANAGER_INL

#include <algorithm>

namespace mia
{
    template <std::derived_from<Entity> T, std::invocable<T&> F>
    void EntityManager::IterateEntities(F method)
    {
        std::type_index type = std::type_index(typeid(T));

        for (auto it = EntitiesMap.lower_bound(type), end = EntitiesMap.upper_bound(type); it != end; it++) {
            Entity* entity = it->second;
            if (!entity->IsActive()) continue;
            std::invoke(method, *dynamic_cast<T*>(entity));
        }
    }
}

#endif