#ifndef _MIA_MATH_H
#define _MIA_MATH_H

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

        inline static int Sign(float x)
        {
            return (x > 0) - (x < 0);
        }
    };
}

#endif