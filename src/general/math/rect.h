#ifndef _MIA_RECT_H
#define _MIA_RECT_H

#include "vector.h"

namespace mia
{
    class Rect
    {
    public:
        inline Rect(Vector2 position = Vector2::Zero(), Vector2 size = Vector2::One()):
            x(position.x), y(position.y), w(size.x), h(size.y)
        {}
        inline Rect(float x, float y, float w = 1, float h = 1):
            x(x), y(y), w(w), h(h)
        {}

        float x, y, w, h;

        // Vector2 position;
        // Vector2 size;

        inline bool Contain(const Vector2& point) const
        {
            return (
                x     < point.x && 
                x + w > point.x &&
                y     < point.y && 
                y + h > point.y
            );
        }

        inline bool Contain(const Rect& other) const
        {
            return (
                x     < other.x           && 
                x + w > other.x + other.w &&
                y     < other.y           && 
                y + h > other.y + other.h
            );
        }

        inline bool Overlap(const Rect& other) const
        {
            return (
                x     < other.x + other.w && 
                x + w > other.x           &&
                y     < other.y + other.h && 
                y + h > other.y
            );
        }

        inline bool operator==(const Rect& other)
        {
            return (
                Math::Approximately(x, other.x) &&
                Math::Approximately(y, other.y) &&
                Math::Approximately(w, other.w) &&
                Math::Approximately(h, other.h) 
            );
        }
    };
}

#endif