#include "matrix.h"

namespace mia
{
    Matrix3::Matrix3(const std::array<float, 9>& values = std::array<float, 9>()): values(values) {}

    inline float& Matrix3::operator()(int row, int col) 
    {
        return values[row * 3 + col];
    }
    inline const float& Matrix3::operator()(int row, int col) const 
    {
        return values[row * 3 + col];
    }

    Matrix3 Matrix3::operator+(const Matrix3& other) const 
    {
        Matrix3 result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result(i, j) = (*this)(i, j) + other(i, j);
            }
        }
        return result;
    }

    Matrix3 Matrix3::operator*(const Matrix3& other) const 
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

    Matrix3 Matrix3::operator*(float value) const 
    {
        Matrix3 result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result(i, j) += value;
            }
        }
        return result;
    }

    Matrix3 Matrix3::Transpose() const 
    {
        Matrix3 result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result(i, j) = (*this)(j, i);
            }
        }
        return result;
    }

    const Matrix3& Matrix3::Identity() noexcept 
    {
        static const Matrix3 result 
            = Matrix3({ 1, 0, 0, 
                        0, 1, 0,
                        0, 0, 1,});
        return result;
    }

    const Matrix3& Matrix3::TranslationMatrix(float x, float y, float z) noexcept
    {
        static const Matrix3 result 
            = Matrix3({ 1, 0, x, 
                        0, 1, y,
                        0, 0, 1,});
        return result;
    }

    const Matrix3& Matrix3::ScaleMatrix(float x, float y, float z) noexcept
    {
        static const Matrix3 result 
            = Matrix3({ x, 0, 0, 
                        0, y, 0,
                        0, 0, 1,});
        return result;
    }

    const Matrix3& Matrix3::RotationMatrix(float angle) noexcept 
    {
        float c = std::cos(angle);
        float s = std::sin(angle);
        static const Matrix3 result 
            = Matrix3({ c, -s, 0, 
                        s,  c, 0,
                        0,  0, 1,});
        return result;
    }
    
    const Matrix3& Matrix3::ShearMatrix(float x, float y) noexcept
    {
        static const Matrix3 result 
            = Matrix3({ 1, x, 0, 
                        y, 1, 0,
                        0, 0, 1,});
        return result;
    }
};
