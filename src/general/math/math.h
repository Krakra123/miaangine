#ifndef _MIA_MATH_H
#define _MIA_PATH_H

namespace mia
{
    class Math
    {
    public:
        Math() = delete;

        static const float EPSILON;

        inline static bool Approximately(float a, float b) 
        {
            return a >= b - EPSILON && a <= b + EPSILON;
        }
    };

    const float Math::EPSILON = 1.17549435e-38;
}

#endif