#ifndef _MIA_ENTITY_HPP
#define _MIA_ENTITY_HPP

#define _MIA__INTERNAL

#include <typeindex>

namespace mia
{
    class Entity
    {
    public:
        // Constructor Destructor
        Entity(std::type_index type);
        virtual ~Entity();

        // Public methods
        bool IsActive() const;
        void SetActive(bool newState);

    private:
        // Data
        std::type_index _type;
        bool _active;
    };
}

#endif