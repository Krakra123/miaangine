#ifndef _MIA_VECTOR_H
#define _MIA_VECTOR_H

#include "math.h"
#include <cmath>

namespace mia
{
	class Vector2Int;

    class Vector2
    {
    public:
        inline Vector2(float x = 0, float y = 0): 
            x(x), y(y)
        {}

        float x, y;

        inline Vector2& operator+=(const Vector2& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		inline Vector2& operator-=(const Vector2& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
		inline Vector2& operator*=(const float value)
		{
			x = x * value;
			y = y * value;
			return *this;
		}
		inline Vector2& operator/=(const float value)
		{
			x = x / value;
			y = y / value;
			return *this;
		}

        inline Vector2 operator+(const Vector2& other) const
		{
			return Vector2(x + other.x, y + other.y);
		}
		inline Vector2 operator-(const Vector2& other) const
		{
			return Vector2(x - other.x, y - other.y);
		}
		inline Vector2 operator*(const float value) const
		{
			return Vector2(x * value, y * value); 
		}
		inline Vector2 operator/(const float value) const
		{
			return Vector2(x / value, y / value); 
		}

        inline float Dot(const Vector2& other) const
		{
			return (x * other.x) + (y * other.y);
		}
		inline float Cross(const Vector2& other) const
        {
            return (x * other.y) - (y * other.x);
        }

		inline float Magnitude() const
		{
			return sqrt(x * x + y * y);
		}
		
        inline Vector2 Normalize() const
        {
            float mag = Magnitude();
            if (mag == 0) return Vector2();
            return *this / mag;
        }

		inline bool operator==(const Vector2& other) const
        {
			return Math::Approximately(x, other.x) && Math::Approximately(y, other.y); 
        }

        inline bool operator!=(const Vector2& other) const
        {
            return !(*this == other);
        }

        static const Vector2& Up() noexcept
		{
			static const Vector2 result(0, 1);
			return result;
		}
		static const Vector2& Down() noexcept
		{
			static const Vector2 result(0, -1);
			return result;
		}
		static const Vector2& Right() noexcept
		{
			static const Vector2 result(1, 0);
			return result;
		}
		static const Vector2& Left() noexcept
		{
			static const Vector2 result(-1, 0);
			return result;
		}
		static const Vector2& Zero() noexcept
		{
			static const Vector2 result(0, 0);
			return result;
		}
		static const Vector2& One() noexcept
		{
			static const Vector2 result(1, 1);
			return result;
		}
		static const Vector2& Infinity() noexcept
		{
			static const Vector2 result(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity());
			return result;
		}

		inline explicit operator Vector2Int() const;

		inline Vector2 Round() const;
    };
    inline Vector2 operator*(float left, Vector2 right)
	{
		return Vector2(right.x * left, right.y * left); 
	}

    class Vector2Int
    {
    public:
        inline Vector2Int(int x = 0, int y = 0): 
            x(x), y(y)
        {}

        int x, y;

        inline Vector2Int& operator+=(const Vector2Int& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		inline Vector2Int& operator-=(const Vector2Int& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
		inline Vector2Int& operator*=(const int value)
		{
			x = x * value;
			y = y * value;
			return *this;
		}
		inline Vector2Int& operator/=(const int value)
		{
			x = x / value;
			y = y / value;
			return *this;
		}

        inline Vector2Int operator+(const Vector2Int& other) const
		{
			return Vector2Int(x + other.x, y + other.y);
		}
		inline Vector2Int operator-(const Vector2Int& other) const
		{
			return Vector2Int(x - other.x, y - other.y);
		}
		inline Vector2Int operator*(const int value) const
		{
			return Vector2Int(x * value, y * value); 
		}
		inline Vector2Int operator/(const int value) const
		{
			return Vector2Int(x / value, y / value); 
		}

		inline bool operator==(const Vector2Int& other) const
        {
            return (x == other.x) && (y == other.y);
        }

        inline bool operator!=(const Vector2Int& other) const
        {
            return !(*this == other);
        }

        static const Vector2Int& Up() noexcept
		{
			static const Vector2Int result(0, 1);
			return result;
		}
		static const Vector2Int& Down() noexcept
		{
			static const Vector2Int result(0, -1);
			return result;
		}
		static const Vector2Int& Right() noexcept
		{
			static const Vector2Int result(1, 0);
			return result;
		}
		static const Vector2Int& Left() noexcept
		{
			static const Vector2Int result(-1, 0);
			return result;
		}
		static const Vector2Int& Zero() noexcept
		{
			static const Vector2Int result(0, 0);
			return result;
		}
		static const Vector2Int& One() noexcept
		{
			static const Vector2Int result(1, 1);
			return result;
		}
		static const Vector2Int& Infinity() noexcept
		{
			static const Vector2Int result(std::numeric_limits<int>::infinity(), std::numeric_limits<int>::infinity());
			return result;
		}

		inline explicit operator Vector2() const
		{
			return Vector2(static_cast<float>(x), static_cast<float>(y));
		}
    };
    inline Vector2Int operator*(int left, Vector2Int right)
	{
		return Vector2Int(right.x * left, right.y * left); 
	}

	// The rest of Vector2
	inline Vector2::operator Vector2Int() const
    {
        return Vector2Int(static_cast<int>(x), static_cast<int>(y));
    }
	inline Vector2 Vector2::Round() const
	{
		return Vector2(std::round(x), std::round(y));
	}
}

#endif