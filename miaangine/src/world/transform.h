#ifndef _MIA_TRANSFORM_H
#define _MIA_TRANSFORM_H

#include "general/math/math.h"

namespace mia
{
    class Transform
    {
    public:
        Transform();
        ~Transform();

    public:
        // Public Properties
        glm::vec2 position;
        float rotation;
        glm::vec2 scale;

    private:
        // Private Properties
        // Transform* parent;

    public:
        // Public methods
        // const Transform& GetParent();
    };
}

#endif