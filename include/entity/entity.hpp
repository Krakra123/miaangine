#ifndef _MIA_ENTITY_HPP
#define _MIA_ENTITY_HPP

#define _MIA__INTERNAL

#include <typeindex>

namespace mia
{
    class entity
    {
    public:
        entity(std::type_index type);
        virtual ~entity();

        bool is_active() const;
        void set_active(bool state);

    private:
        std::type_index _type;
        bool _active;
    };
}

#endif