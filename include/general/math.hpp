#ifndef _MIA_MATH_H
#define _MIA_MATH_H

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <numbers>

namespace mia
{
    constexpr float EPSILON = 2.0e-7;
    constexpr float PI = 3.1415926536;

    constexpr glm::vec2 VEC2_ZERO  = {  0,  0 };
    constexpr glm::vec2 VEC2_ONE   = {  1,  1 };
    constexpr glm::vec2 VEC2_UP    = {  0,  1 };
    constexpr glm::vec2 VEC2_DOWN  = {  0, -1 };
    constexpr glm::vec2 VEC2_RIGHT = {  1,  0 };
    constexpr glm::vec2 VEC2_LEFT  = { -1,  0 };

    bool approximately(float a, float b, float epsilon = EPSILON);
    int sign(float x);
}

#endif