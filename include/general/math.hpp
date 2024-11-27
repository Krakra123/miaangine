#ifndef _MIA_MATH_H
#define _MIA_MATH_H

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <numbers>

namespace mia
{
    class Math
    {
    public:
        Math() = delete;

        static const float EPSILON;
        static const float PI;

        static bool Approximately(float a, float b, float epsilon = EPSILON);
        static int Sign(float x);
    };
}

#endif