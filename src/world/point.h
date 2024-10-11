#ifndef _MIA_POINT_H
#define _MIA_POINT_H

#include "general/math/vector.h"
#include "general/math/matrix.h"

namespace mia
{
    class Point
    {
    public:
        Point(Vector2 position, Vector2 pivot = Vector2::Zero());
        Point(float x = 0.0f, float y = 0.0f, float px = 0.0f, float py = 0.0f);

        // Attributes
        Vector2 position;
        Vector2 pivot;

        // Public methods
        Vector2 GetLocalPosition() const;
        void SetLocalPosition(Vector2 localPos);
        Matrix3 GetMatrix() const;

        void Translate(float x, float y);
        void Translate(Vector2 value);
        void Scale(float x, float y);
        void Scale(Vector2 value);
        void Rotate(float angle);

    private:
        Matrix3 GetLocalMatrix();
    };
}

#endif