#ifndef _MIA_RECT_H
#define _MIA_RECT_H

#include "vector.h"

namespace mia
{
    class Rect
    {
    public:
        inline Rect(Vector2 position = Vector2::Zero(), Vector2 size = Vector2::One()):
            position(position),
            size(size)
        {}
        inline Rect(float x, float y, float sx = 1, float sy = 1):
            position(Vector2(x, y)),
            size(Vector2(sx, sy))
        {}

        Vector2 position;
        Vector2 size;

        inline bool Contain(const Vector2& point) const
        {
            return (
                position.x          < point.x && 
                position.x + size.x > point.x &&
                position.y          < point.y && 
                position.y + size.y > point.y
            );
        }

        inline bool Contain(const Rect& other) const
        {
            return (
                position.x          < other.position.x                && 
                position.x + size.x > other.position.x + other.size.x &&
                position.y          < other.position.y                && 
                position.y + size.y > other.position.y + other.size.y
            );
        }

        inline bool Overlap(const Rect& other) const
        {
            return (
                position.x          < other.position.x + other.size.x && 
                position.x + size.x > other.position.x                &&
                position.y          < other.position.y + other.size.y && 
                position.y + size.y > other.position.y
            );
        }

        inline bool operator==(const Rect& other)
        {
            return (
                Math::Approximately(position.x, other.position.x) &&
                Math::Approximately(position.y, other.position.y) &&
                Math::Approximately(size.x, other.size.x) &&
                Math::Approximately(size.y, other.size.y) 
            );
        }
    };
}

#endif