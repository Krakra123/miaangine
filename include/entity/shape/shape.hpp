#ifndef _MIA_SHAPE_H
#define _MIA_SHAPE_H

#include "entity/world/transform.hpp"
#include "util/struct.hpp"

namespace mia
{
    class Shape
    {
    public:
        Color color;

        virtual void Render(const transform& transform) = 0;
    };
}

#endif