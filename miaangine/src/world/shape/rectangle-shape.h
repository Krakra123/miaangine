#ifndef _MIA_RECTANGLE_SHAPE_H
#define _MIA_RECTANGLE_SHAPE_H

#include "shape.h"

namespace mia
{
    class RectangleShape : public Shape
    {
    public:
        RectangleShape(float w = 1.0f, float h = 1.0f);

        float width, height;

        void Render(const Transform& transform) override;
    };
}

#endif