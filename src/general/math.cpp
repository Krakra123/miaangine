#include "general/math.hpp"

namespace mia
{
    bool approximately(float a, float b, float epsilon)
    {
        return a >= b - epsilon && a <= b + epsilon;
    }

    int sign(float x)
    {
        return (x > 0) - (x < 0);
    }
}