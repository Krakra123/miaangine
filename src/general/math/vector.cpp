#include "vector.h"

#include <cmath>
#include <algorithm>
#include <iostream>

#include "math.h"

namespace mia
{
#pragma region Vector2 float
    Vector2::Vector2(float x, float y): 
        x(x), y(y)
    {}

    Vector2& Vector2::operator+=(const Vector2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    Vector2& Vector2::operator-=(const Vector2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    Vector2& Vector2::operator*=(const float value)
    {
        x = x * value;
        y = y * value;
        return *this;
    }
    Vector2& Vector2::operator/=(const float value)
    {
        x = x / value;
        y = y / value;
        return *this;
    }
    
    bool Vector2::operator==(const Vector2& other) const
    {
        return Math::Approximately(x, other.x) && Math::Approximately(y, other.y); 
    }
    bool Vector2::operator!=(const Vector2& other) const
    {
        return !(*this == other);
    }

    Vector2 Vector2::operator+(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }
    Vector2 Vector2::operator-(const Vector2& other) const
    {
        return Vector2(x - other.x, y - other.y);
    }
    Vector2 Vector2::operator*(const float value) const
    {
        return Vector2(x * value, y * value); 
    }
    Vector2 Vector2::operator/(const float value) const
    {
        return Vector2(x / value, y / value); 
    }
    Vector2 operator*(float left, Vector2 right)
    {
        return right * left;
    }

    float Vector2::Magnitude() const
    {
        return sqrt(x * x + y * y);
    }
    Vector2 Vector2::Normalize() const
    {
        float mag = Magnitude();
        if (mag == 0) return Vector2();
        return *this / mag;
    }
    Vector2 Vector2::Round() const
    {
        return Vector2(std::round(x), std::round(y));
    }
    float Vector2::Dot(const Vector2& other) const
    {
        return (x * other.x) + (y * other.y);
    }
    float Vector2::Cross(const Vector2& other) const
    {
        return (x * other.y) - (y * other.x);
    }
    float Vector2::Angle(const Vector2& to) const
    {
        float x = Dot(to) / (Magnitude() * to.Magnitude());
        if (Math::Approximately(x,  1)) return 0;
        if (Math::Approximately(x, -1)) return Math::PI;

        return std::acos(x) * Math::Sign(Cross(to));
    }
    float Vector2::Distance(const Vector2& other) const
    {
        float dx = other.x - x;
        float dy = other.y - y;
        return std::sqrt(dx * dx + dy * dy);
    }

    float Vector2::Dot(const Vector2& a, const Vector2& b)
    {
        return a.Dot(b);
    }
    float Vector2::Cross(const Vector2& a, const Vector2& b)
    {
        return a.Cross(b);
    }
    float Vector2::Angle(const Vector2& from, const Vector2& to)
    {
        return from.Angle(to);
    }
    float Vector2::Distance(const Vector2& a, const Vector2& b)
    {
        return a.Distance(b);
    }
    Vector2 Vector2::ClampMagnitude(const Vector2& vector, float length)
    {
        float mag = vector.Magnitude();
        if (mag < length) return vector;
        return vector.Normalize() * length;
    }
    Vector2 Vector2::Lerp(const Vector2& a, const Vector2& b, float t)
    {
        return Vector2(a.x + t * (b.x - a.x), a.y + t * (b.y - a.y));
    }
    Vector2 Vector2::Max(const Vector2& a, const Vector2& b)
    {
        return Vector2(std::max(a.x, b.x), std::max(a.y, b.y));
    }
    Vector2 Vector2::Min(const Vector2& a, const Vector2& b)
    {
        return Vector2(std::min(a.x, b.x), std::min(a.y, b.y));
    }
    Vector2 Vector2::MoveTowards(const Vector2& from, const Vector2& to, float delta)
    {
        float actualDelta = std::min((to - from).Magnitude(), delta);
        return from + from.Normalize() * actualDelta;
    }
    Vector2 Vector2::Perpendicular(const Vector2& vector)
    {
        return Vector2(-vector.y, vector.x);
    } 
    Vector2 Vector2::Reflect(const Vector2& in, const Vector2& normal)
    {
        Vector2 nNormal = normal.Normalize();
        float dot = in.Dot(normal);
        return Vector2(in.x - 2 * dot * nNormal.x, in.y - 2 * dot * nNormal.y);
    }
    Vector2 Vector2::GetDirection(float angle)
    {
        return Vector2(std::cos(angle), std::sin(angle));
    }

    Vector2::operator Vector2Int() const
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

    Vector2Int& Vector2Int::operator+=(const Vector2Int& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    Vector2Int& Vector2Int::operator-=(const Vector2Int& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    Vector2Int& Vector2Int::operator*=(const int value)
    {
        x = x * value;
        y = y * value;
        return *this;
    }
    Vector2Int& Vector2Int::operator/=(const int value)
    {
        x = x / value;
        y = y / value;
        return *this;
    }

    bool Vector2Int::operator==(const Vector2Int& other) const
    {
        return (x == other.x) && (y == other.y);
    }
    bool Vector2Int::operator!=(const Vector2Int& other) const
    {
        return !(*this == other);
    }

    Vector2Int Vector2Int::operator+(const Vector2Int& other) const
    {
        return Vector2Int(x + other.x, y + other.y);
    }
    Vector2Int Vector2Int::operator-(const Vector2Int& other) const
    {
        return Vector2Int(x - other.x, y - other.y);
    }
    Vector2Int Vector2Int::operator*(const int value) const
    {
        return Vector2Int(x * value, y * value); 
    }
    Vector2Int Vector2Int::operator/(const int value) const
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

    Vector2Int::operator Vector2() const
    {
        return Vector2(static_cast<float>(x), static_cast<float>(y));
    }
    Vector2Int operator*(int left, Vector2Int right)
    {
        return right * left;
    }
#pragma endregion
}