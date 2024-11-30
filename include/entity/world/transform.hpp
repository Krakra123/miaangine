#ifndef _MIA_TRANSFORM_H
#define _MIA_TRANSFORM_H

#include "general/math.hpp"

namespace mia
{
    class transform
    {
    public:
        transform();
        virtual ~transform();

    public:
        glm::vec2 position;
        float rotation;
        glm::vec2 scale;

    public:
        glm::vec2 get_forward();

        void translate(glm::vec2 value);
        void rotate(float value);
        void stretch(glm::vec2 value);

        void look_at(glm::vec2 target);
    };
}

#endif