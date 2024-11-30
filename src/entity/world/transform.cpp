#include "entity/world/transform.hpp"

namespace mia
{
    transform::transform() :
        position(mia::VEC2_ZERO),
        rotation(0),
        scale(mia::VEC2_ONE)
    {}

    transform::~transform() 
    {}

    // glm::vec2 transform::get_forward()
    // {
        
    // }

    // void transform::translate(glm::vec2 value) 
    // {
    //     position += value;
    // }

    // void transform::rotate(float value)
    // {
    //     scale += value;
    // }

    // void transform::stretch(glm::vec2 value) 
    // {
    //     scale.x *= value.x;
    //     scale.y *= value.y;
    // }

    // void transform::look_at(glm::vec2 target) 
    // {

    // }
}