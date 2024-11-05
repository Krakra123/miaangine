#include "math.h"

namespace mia
{
    const float Math::EPSILON = 2.0e-7;
    const float Math::PI = 3.1415926536;

    bool Math::Approximately(float a, float b, float epsilon)
    {
        return a >= b - epsilon && a <= b + epsilon;
    }

    int Math::Sign(float x)
    {
        return (x > 0) - (x < 0);
    }
}