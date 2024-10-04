#ifndef _MIA_MATRIX_H
#define _MIA_MATRIX_H

#include <array>
#include <cmath>

namespace mia
{
    class Matrix3
    {
    public:
        inline Matrix3(const std::array<float, 9>& values = std::array<float, 9>()): values(values) {}

    private:
        std::array<float, 9> values;

    public:
        inline float& operator()(int row, int col) 
        {
            return values[row * 3 + col];
        }
        inline const float& operator()(int row, int col) const 
        {
            return values[row * 3 + col];
        }

        Matrix3 operator+(const Matrix3& other) const 
        {
            Matrix3 result;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    result(i, j) = (*this)(i, j) + other(i, j);
                }
            }
            return result;
        }

        Matrix3 operator*(const Matrix3& other) const 
        {
            Matrix3 result;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    result(i, j) = 0;
                    for (int k = 0; k < 3; ++k) {
                        result(i, j) += (*this)(i, k) * other(k, j);
                    }
                }
            }
            return result;
        }

        Matrix3 operator*(float value) const 
        {
            Matrix3 result;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    result(i, j) += value;
                }
            }
            return result;
        }

        Matrix3 Transpose() const 
        {
            Matrix3 result;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    result(i, j) = (*this)(j, i);
                }
            }
            return result;
        }

        static const Matrix3& Identity() noexcept 
        {
            return Matrix3({1, 0, 0, 
                            0, 1, 0,
                            0, 0, 1,});
        }

        static const Matrix3& TranslationMatrix(float x, float y, float z) noexcept
        {
            return Matrix3({1, 0, x,
                            0, 1, y,
                            0, 0, 1});
        }

        static const Matrix3& ScaleMatrix(float x, float y, float z) noexcept
        {
            return Matrix3({x, 0, 0,
                            0, y, 0,
                            0, 0, 1});
        }

        static const Matrix3& RotationMatrix(float angle) noexcept 
        {
            float c = std::cos(angle);
            float s = std::sin(angle);
            return Matrix3({c, -s, 0,
                            s,  c, 0,
                            0,  0, 1});
        }
        
        static const Matrix3& ShearMatrix(float x, float y) noexcept
        {
            return Matrix3({1, x, 0,
                            y, 1, 0,
                            0, 0, 1});
        }

        std::pair<float, float> TransformPoint(float x, float y) const 
        {
            float nX = values[0] * x + values[1] * y + values[2];
            float nY = values[3] * x + values[4] * y + values[5];
            float w = values[6] * x + values[7] * y + values[8];
            
            if (w != 0) {
                nX /= w;
                nY /= w;
            }
            
            return {nX, nY};
        }
    };

    class Matrix4
    {
    public:
        inline Matrix4(const std::array<float, 16>& values = std::array<float, 16>()): values(values) {}

    private:
        std::array<float, 16> values;

    public:
        inline float& operator()(int row, int col) 
        {
            return values[row * 4 + col];
        }
        inline const float& operator()(int row, int col) const 
        {
            return values[row * 4 + col];
        }

        Matrix4 operator+(const Matrix4& other) const 
        {
            Matrix4 result;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    result(i, j) = (*this)(i, j) + other(i, j);
                }
            }
            return result;
        }

        Matrix4 operator*(const Matrix4& other) const 
        {
            Matrix4 result;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    result(i, j) = 0;
                    for (int k = 0; k < 4; ++k) {
                        result(i, j) += (*this)(i, k) * other(k, j);
                    }
                }
            }
            return result;
        }

        Matrix4 operator*(float value) const 
        {
            Matrix4 result;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    result(i, j) *= value;
                }
            }
            return result;
        }

        Matrix4 Transpose() const 
        {
            Matrix4 result;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    result(i, j) = (*this)(j, i);
                }
            }
            return result;
        }

        static const Matrix4& Identity() noexcept 
        {
            return Matrix4({1, 0, 0, 0, 
                            0, 1, 0, 0, 
                            0, 0, 1, 0, 
                            0, 0, 0, 1});
        }

        static const Matrix4& TranslationMatrix(float x, float y, float z) noexcept
        {
            return Matrix4({1, 0, 0, x,
                            0, 1, 0, y,
                            0, 0, 1, z,
                            0, 0, 0, 1});
        }

        static const Matrix4& ScaleMatrix(float x, float y, float z) noexcept
        {
            return Matrix4({x, 0, 0, 0,
                            0, y, 0, 0,
                            0, 0, z, 0,
                            0, 0, 0, 1});
        }

        static const Matrix4& RotationXMatrix(float angle) noexcept 
        {
            float c = std::cos(angle);
            float s = std::sin(angle);
            return Matrix4({1, 0,  0, 0,
                            0, c, -s, 0,
                            0, s,  c, 0,
                            0, 0,  0, 1});
        }

        static const Matrix4& RotationYMatrix(float angle) noexcept 
        {
            float c = std::cos(angle);
            float s = std::sin(angle);
            return Matrix4({ c, 0, s, 0,
                            0, 1, 0, 0,
                            -s, 0, c, 0,
                            0, 0, 0, 1});
        }

        static const Matrix4& RotationZMatrix(float angle) noexcept 
        {
            float c = std::cos(angle);
            float s = std::sin(angle);
            return Matrix4({c, -s, 0, 0,
                            s,  c, 0, 0,
                            0,  0, 1, 0,
                            0,  0, 0, 1});
        }
    };
}

#endif