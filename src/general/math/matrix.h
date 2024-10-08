#ifndef _MIA_MATRIX_H
#define _MIA_MATRIX_H

#include <array>
#include <cmath>

namespace mia
{
    class Matrix3
    {
    public:
        Matrix3(const std::array<float, 9>& values = std::array<float, 9>());

        std::array<float, 9> values;

        float& operator()(int row, int col);
        const float& operator()(int row, int col) const;

        Matrix3 operator+(const Matrix3& other) const;
        Matrix3 operator*(const Matrix3& other) const;
        Matrix3 operator*(float value) const;

        Matrix3 Transpose() const;
        float Determinant() const;
        Matrix3 Adjugate() const;
        Matrix3 Inverse() const;

        static const Matrix3& Identity() noexcept;
        static const Matrix3& Stretch(float k) noexcept;
        static const Matrix3& Translation(float x, float y) noexcept;
        static const Matrix3& Scale(float x, float y) noexcept;
        static const Matrix3& Rotation(float angle) noexcept;
        static const Matrix3& Shear(float x, float y) noexcept;
    };

    // TODO this is 2d engine, maybe general matrix instead of specific matrix4
    // class Matrix4
    // {
    // public:
    //     inline Matrix4(const std::array<float, 16>& values = std::array<float, 16>()): values(values) {}

    // private:
    //     std::array<float, 16> values;

    // public:
    //     inline float& operator()(int row, int col) 
    //     {
    //         return values[row * 4 + col];
    //     }
    //     inline const float& operator()(int row, int col) const 
    //     {
    //         return values[row * 4 + col];
    //     }

    //     Matrix4 operator+(const Matrix4& other) const 
    //     {
    //         Matrix4 result;
    //         for (int i = 0; i < 4; ++i) {
    //             for (int j = 0; j < 4; ++j) {
    //                 result(i, j) = (*this)(i, j) + other(i, j);
    //             }
    //         }
    //         return result;
    //     }

    //     Matrix4 operator*(const Matrix4& other) const 
    //     {
    //         Matrix4 result;
    //         for (int i = 0; i < 4; ++i) {
    //             for (int j = 0; j < 4; ++j) {
    //                 result(i, j) = 0;
    //                 for (int k = 0; k < 4; ++k) {
    //                     result(i, j) += (*this)(i, k) * other(k, j);
    //                 }
    //             }
    //         }
    //         return result;
    //     }

    //     Matrix4 operator*(float value) const 
    //     {
    //         Matrix4 result;
    //         for (int i = 0; i < 4; ++i) {
    //             for (int j = 0; j < 4; ++j) {
    //                 result(i, j) *= value;
    //             }
    //         }
    //         return result;
    //     }

    //     Matrix4 Transpose() const 
    //     {
    //         Matrix4 result;
    //         for (int i = 0; i < 4; ++i) {
    //             for (int j = 0; j < 4; ++j) {
    //                 result(i, j) = (*this)(j, i);
    //             }
    //         }
    //         return result;
    //     }

    //     static const Matrix4& Identity() noexcept 
    //     {
    //         return Matrix4({1, 0, 0, 0, 
    //                         0, 1, 0, 0, 
    //                         0, 0, 1, 0, 
    //                         0, 0, 0, 1});
    //     }

    //     static const Matrix4& TranslationMatrix(float x, float y, float z) noexcept
    //     {
    //         return Matrix4({1, 0, 0, x,
    //                         0, 1, 0, y,
    //                         0, 0, 1, z,
    //                         0, 0, 0, 1});
    //     }

    //     static const Matrix4& ScaleMatrix(float x, float y, float z) noexcept
    //     {
    //         return Matrix4({x, 0, 0, 0,
    //                         0, y, 0, 0,
    //                         0, 0, z, 0,
    //                         0, 0, 0, 1});
    //     }

    //     static const Matrix4& RotationXMatrix(float angle) noexcept 
    //     {
    //         float c = std::cos(angle);
    //         float s = std::sin(angle);
    //         return Matrix4({1, 0,  0, 0,
    //                         0, c, -s, 0,
    //                         0, s,  c, 0,
    //                         0, 0,  0, 1});
    //     }

    //     static const Matrix4& RotationYMatrix(float angle) noexcept 
    //     {
    //         float c = std::cos(angle);
    //         float s = std::sin(angle);
    //         return Matrix4({ c, 0, s, 0,
    //                         0, 1, 0, 0,
    //                         -s, 0, c, 0,
    //                         0, 0, 0, 1});
    //     }

    //     static const Matrix4& RotationZMatrix(float angle) noexcept 
    //     {
    //         float c = std::cos(angle);
    //         float s = std::sin(angle);
    //         return Matrix4({c, -s, 0, 0,
    //                         s,  c, 0, 0,
    //                         0,  0, 1, 0,
    //                         0,  0, 0, 1});
    //     }
    // };
}

#endif