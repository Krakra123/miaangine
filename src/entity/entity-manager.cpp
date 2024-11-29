#include "entity/entity-manager.hpp"

namespace mia
{
    void register_entity(std::type_index type, entity* entity) {
        entities_map.insert(std::make_pair(
            type,
            entity
        ));
    }

    void unregister_entity(std::type_index type, entity* entity) {
        auto range = entities_map.equal_range(type);
        auto it = std::find_if(
            range.first, range.second,
            [&entity](const auto& pair) { return pair.second == entity; }
        );
        if (it != range.second) {
            entities_map.erase(it);
        }
    }
}