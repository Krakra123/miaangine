#include "entity/world/point.hpp"

namespace mia
{
    Point::Point(glm::vec2 position, glm::vec2 pivot):
        position(position),
        pivot(pivot)
    {}

    Point::Point(float x, float y, float px, float py):
        position(glm::vec2(x, y)),
        pivot(glm::vec2(px, py))
    {}

    glm::vec2 Point::GetLocalPosition() const
    {
        return position - pivot;
    }
    void Point::SetLocalPosition(glm::vec2 localPos)
    {
        glm::vec2 delta = localPos - GetLocalPosition();
        position += delta;
    }

    void Point::Translate(float x, float y)
    {
        // Matrix3 transform = Matrix3::Translation(x, y) * GetLocalMatrix();
        // glm::vec2 delta = glm::vec2(transform(0, 0), transform(1, 0)) - GetLocalPosition();
        // position += delta;
    }
    void Point::Translate(glm::vec2 value)
    {
        Translate(value.x, value.y);
    }
    void Point::Scale(float x, float y)
    {
        // Matrix3 transform = Matrix3::Scale(x, y) * GetLocalMatrix();
        // glm::vec2 delta = glm::vec2(transform(0, 0), transform(1, 0)) - GetLocalPosition();
        // position += delta;
    }
    void Point::Scale(glm::vec2 value)
    {
        Scale(value.x, value.y);
    }
    void Point::Rotate(float angle)
    {
        // Matrix3 x = Matrix3::Rotation(angle) * GetLocalMatrix();
        // glm::vec2 delta = glm::vec2(x(0, 0), x(1, 0)) - GetLocalPosition();
        // position += delta;
    }

    glm::mat3 Point::GetLocalMatrix()
    {
        glm::vec2 local = GetLocalPosition();
        return glm::mat3(
            local.x, 0, 0,
            local.y, 0, 0,
            1      , 0, 0
        );
    }
}