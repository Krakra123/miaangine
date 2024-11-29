#include "entity/entity.hpp"

#include <stdexcept>

#include "entity/entity-manager.hpp"

namespace mia
{
    entity::entity(std::type_index type) :
        _type(type), _active(true)
    {
        register_entity(_type, this);
    }
    entity::~entity()
    {
        unregister_entity(_type, this);
    }

    bool entity::is_active() const
    {
        return _active;
    }
    void entity::set_active(bool state)
    {
        _active = state;
    }
}