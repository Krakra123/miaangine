#ifndef _MIA_TRANSFORM_H
#define _MIA_TRANSFORM_H

#include "general/math/vector.h"

namespace mia
{
    class Transform
    {
    public:
        Transform();
        ~Transform();

    public:
        // Public Properties
        Vector2 position;
        float rotation;
        Vector2 scale;

    private:
        // Private Properties
        // Transform* parent;

    public:
        // Public methods
        // const Transform& GetParent();
    };
}

#endif