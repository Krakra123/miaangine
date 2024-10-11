#include "point.h"

namespace mia
{
    Point::Point(Vector2 position, Vector2 pivot):
        position(position),
        pivot(pivot)
    {}

    Point::Point(float x, float y, float px, float py):
        position(Vector2(x, y)),
        pivot(Vector2(px, py))
    {}

    Vector2 Point::GetLocalPosition() const
    {
        return position - pivot;
    }
    void Point::SetLocalPosition(Vector2 localPos)
    {
        Vector2 delta = localPos - GetLocalPosition();
        position += delta;
    }

    void Point::Translate(float x, float y)
    {
        Matrix3 transform = Matrix3::Translation(x, y) * GetLocalMatrix();
        Vector2 delta = Vector2(transform(0, 0), transform(1, 0)) - GetLocalPosition();
        position += delta;
    }
    void Point::Translate(Vector2 value)
    {
        Translate(value.x, value.y);
    }
    void Point::Scale(float x, float y)
    {
        Matrix3 transform = Matrix3::Scale(x, y) * GetLocalMatrix();
        Vector2 delta = Vector2(transform(0, 0), transform(1, 0)) - GetLocalPosition();
        position += delta;
    }
    void Point::Scale(Vector2 value)
    {
        Scale(value.x, value.y);
    }
    void Point::Rotate(float angle)
    {
        Matrix3 x = Matrix3::Rotation(angle) * GetLocalMatrix();
        Vector2 delta = Vector2(x(0, 0), x(1, 0)) - GetLocalPosition();
        position += delta;
    }

    Matrix3 Point::GetLocalMatrix()
    {
        Vector2 local = GetLocalPosition();
        return Matrix3({local.x, 0, 0,
                        local.y, 0, 0,
                        1      , 0, 0});
    }
}