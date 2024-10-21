#ifndef _MIA_SHAPE_H
#define _MIA_SHAPE_H

#include "world/transform.h"
#include "util/struct.h"

namespace mia
{
    class Shape
    {
    public:
        Color color;

        virtual void Render(const Transform& transform) = 0;
    };
}

#endif