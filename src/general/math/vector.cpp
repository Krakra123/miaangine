#include "vector.h"

#include <cmath>
#include "math.h"

namespace mia
{
#pragma region Vector2 float
    Vector2::Vector2(float x, float y): 
        x(x), y(y)
    {}

    inline Vector2& Vector2::operator+=(const Vector2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    inline Vector2& Vector2::operator-=(const Vector2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    inline Vector2& Vector2::operator*=(const float value)
    {
        x = x * value;
        y = y * value;
        return *this;
    }
    inline Vector2& Vector2::operator/=(const float value)
    {
        x = x / value;
        y = y / value;
        return *this;
    }
    
    inline bool Vector2::operator==(const Vector2& other) const
    {
        return Math::Approximately(x, other.x) && Math::Approximately(y, other.y); 
    }
    inline bool Vector2::operator!=(const Vector2& other) const
    {
        return !(*this == other);
    }

    inline Vector2 Vector2::operator+(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }
    inline Vector2 Vector2::operator-(const Vector2& other) const
    {
        return Vector2(x - other.x, y - other.y);
    }
    inline Vector2 Vector2::operator*(const float value) const
    {
        return Vector2(x * value, y * value); 
    }
    inline Vector2 Vector2::operator/(const float value) const
    {
        return Vector2(x / value, y / value); 
    }
    inline Vector2 operator*(float left, Vector2 right)
    {
        return right * left;
    }

    inline float Vector2::Dot(const Vector2& other) const
    {
        return (x * other.x) + (y * other.y);
    }
    inline float Vector2::Cross(const Vector2& other) const
    {
        return (x * other.y) - (y * other.x);
    }

    inline float Vector2::Magnitude() const
    {
        return sqrt(x * x + y * y);
    }
    inline Vector2 Vector2::Normalize() const
    {
        float mag = Magnitude();
        if (mag == 0) return Vector2();
        return *this / mag;
    }
    inline Vector2 Vector2::Round() const
    {
        return Vector2(std::round(x), std::round(y));
    }

    inline Vector2::operator Vector2Int() const
    {
        return Vector2Int(static_cast<int>(x), static_cast<int>(y));
    }

    const Vector2& Vector2::Up() noexcept
    {
        static const Vector2 result(0, 1);
        return result;
    }
    const Vector2& Vector2::Down() noexcept
    {
        static const Vector2 result(0, -1);
        return result;
    }
    const Vector2& Vector2::Right() noexcept
    {
        static const Vector2 result(1, 0);
        return result;
    }
    const Vector2& Vector2::Left() noexcept
    {
        static const Vector2 result(-1, 0);
        return result;
    }
    const Vector2& Vector2::Zero() noexcept
    {
        static const Vector2 result(0, 0);
        return result;
    }
    const Vector2& Vector2::One() noexcept
    {
        static const Vector2 result(1, 1);
        return result;
    }
    const Vector2& Vector2::Infinity() noexcept
    {
        static const Vector2 result(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity());
        return result;
    }
#pragma endregion

#pragma region Vector2 int
    Vector2Int::Vector2Int(int x, int y): 
        x(x), y(y)
    {}

    inline Vector2Int& Vector2Int::operator+=(const Vector2Int& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    inline Vector2Int& Vector2Int::operator-=(const Vector2Int& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    inline Vector2Int& Vector2Int::operator*=(const int value)
    {
        x = x * value;
        y = y * value;
        return *this;
    }
    inline Vector2Int& Vector2Int::operator/=(const int value)
    {
        x = x / value;
        y = y / value;
        return *this;
    }

    inline bool Vector2Int::operator==(const Vector2Int& other) const
    {
        return (x == other.x) && (y == other.y);
    }
    inline bool Vector2Int::operator!=(const Vector2Int& other) const
    {
        return !(*this == other);
    }

    inline Vector2Int Vector2Int::operator+(const Vector2Int& other) const
    {
        return Vector2Int(x + other.x, y + other.y);
    }
    inline Vector2Int Vector2Int::operator-(const Vector2Int& other) const
    {
        return Vector2Int(x - other.x, y - other.y);
    }
    inline Vector2Int Vector2Int::operator*(const int value) const
    {
        return Vector2Int(x * value, y * value); 
    }
    inline Vector2Int Vector2Int::operator/(const int value) const
    {
        return Vector2Int(x / value, y / value); 
    }

    const Vector2Int& Vector2Int::Up() noexcept
    {
        static const Vector2Int result(0, 1);
        return result;
    }
    const Vector2Int& Vector2Int::Down() noexcept
    {
        static const Vector2Int result(0, -1);
        return result;
    }
    const Vector2Int& Vector2Int::Right() noexcept
    {
        static const Vector2Int result(1, 0);
        return result;
    }
    const Vector2Int& Vector2Int::Left() noexcept
    {
        static const Vector2Int result(-1, 0);
        return result;
    }
    const Vector2Int& Vector2Int::Zero() noexcept
    {
        static const Vector2Int result(0, 0);
        return result;
    }
    const Vector2Int& Vector2Int::One() noexcept
    {
        static const Vector2Int result(1, 1);
        return result;
    }
    const Vector2Int& Vector2Int::Infinity() noexcept
    {
        static const Vector2Int result(std::numeric_limits<int>::infinity(), std::numeric_limits<int>::infinity());
        return result;
    }

    inline Vector2Int::operator Vector2() const
    {
        return Vector2(static_cast<float>(x), static_cast<float>(y));
    }
    inline Vector2Int operator*(int left, Vector2Int right)
    {
        return right * left;
    }
#pragma endregion
}