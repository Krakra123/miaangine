#ifndef _MIA_ENTITY_MANAGER_INL
#define _MIA_ENTITY_MANAGER_INL

#include <algorithm>

namespace mia
{
    template <std::derived_from<entity> T, std::invocable<T&> F>
    void iterate_entities(F method)
    {
        std::type_index type = std::type_index(typeid(T));

        for (auto it = entities_map.lower_bound(type), end = entities_map.upper_bound(type); it != end; it++) {
            entity* entity = it->second;
            if (!entity->is_active()) continue;
            std::invoke(method, *dynamic_cast<T*>(entity));
        }
    }
}

#endif