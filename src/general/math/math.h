#ifndef _MIA_MATH_H
#define _MIA_PATH_H

namespace mia
{
    class Math
    {
    public:
        Math() = delete;

        static const float EPSILON;
        static const float PI;

        inline static bool Approximately(float a, float b) 
        {
            return a >= b - EPSILON && a <= b + EPSILON;
        }
    };

    const float Math::EPSILON = 2.0e-7;
    const float Math::PI = 3.1415926536;
}

#endif