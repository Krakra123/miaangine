#include "entity/entity-manager.hpp"

namespace mia
{
    std::multimap<std::type_index, Entity*> EntityManager::EntitiesMap;

    void EntityManager::RegisterEntity(std::type_index type, Entity* entity)
    {
        EntitiesMap.insert(std::make_pair(
            type,
            entity
        ));
    }

    void EntityManager::UnregisterEntity(std::type_index type, Entity* entity)
    {
        auto range = EntitiesMap.equal_range(type);
        auto it = std::find_if(
            range.first, range.second,
            [&entity](const auto& pair) { return pair.second == entity; }
        );
        if (it != range.second) {
            EntitiesMap.erase(it);
        }
    }
}