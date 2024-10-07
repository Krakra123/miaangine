#ifndef _MIA_VECTOR_H
#define _MIA_VECTOR_H

namespace mia
{
	class Vector2Int;

    class Vector2
    {
    public:
        Vector2(float x = 0, float y = 0);

        float x, y;

        inline Vector2& operator+=(const Vector2& other);
		inline Vector2& operator-=(const Vector2& other);
		inline Vector2& operator*=(const float value);
		inline Vector2& operator/=(const float value);

		inline bool operator==(const Vector2& other) const;
        inline bool operator!=(const Vector2& other) const;

        inline Vector2 operator+(const Vector2& other) const;
		inline Vector2 operator-(const Vector2& other) const;
		inline Vector2 operator*(const float value) const;
		inline Vector2 operator/(const float value) const;

        inline float Dot(const Vector2& other) const;
		inline float Cross(const Vector2& other) const;

		inline float Magnitude() const;
        inline Vector2 Normalize() const;
		inline Vector2 Round() const;

        static const Vector2& Up() noexcept;
		static const Vector2& Down() noexcept;
		static const Vector2& Right() noexcept;
		static const Vector2& Left() noexcept;
		static const Vector2& Zero() noexcept;
		static const Vector2& One() noexcept;
		static const Vector2& Infinity() noexcept;

		inline operator Vector2Int() const;
    };
    inline Vector2 operator*(float left, Vector2 right);

    class Vector2Int
    {
    public:
        Vector2Int(int x = 0, int y = 0);

        int x, y;

        inline Vector2Int& operator+=(const Vector2Int& other);
		inline Vector2Int& operator-=(const Vector2Int& other);
		inline Vector2Int& operator*=(const int value);
		inline Vector2Int& operator/=(const int value);

		inline bool operator==(const Vector2Int& other) const;
        inline bool operator!=(const Vector2Int& other) const;

        inline Vector2Int operator+(const Vector2Int& other) const;
		inline Vector2Int operator-(const Vector2Int& other) const;
		inline Vector2Int operator*(const int value) const;
		inline Vector2Int operator/(const int value) const;

        static const Vector2Int& Up() noexcept;
		static const Vector2Int& Down() noexcept;
		static const Vector2Int& Right() noexcept;
		static const Vector2Int& Left() noexcept;
		static const Vector2Int& Zero() noexcept;
		static const Vector2Int& One() noexcept;
		static const Vector2Int& Infinity() noexcept;

		inline explicit operator Vector2() const;
    };
    inline Vector2Int operator*(int left, Vector2Int right);
}

#endif