#pragma once

#include "../math.h"

namespace blitz {
    struct Mat4
    {
        union
        {
            float elements[4 * 4];
            Vec4 columns[4];
        };

        //column major [row + col * 4]

        Mat4();
        Mat4(const float& diagonal);
        Mat4(const Mat4& other);
        Mat4& operator=(const Mat4& other); 

        Mat4& multiply(const Mat4& matrix);
        Mat4& multiply(const float& scalar);
        Mat4 transpose();
        Mat4 invert();
        float determinant() const;
        Mat4& setColumn(const int& index, const Vec4& data);

        //static functions to create specifc matrices
        static Mat4 identity();
        static Mat4 translate(const Vec3& translation);
        static Mat4 rotate(float angle, const Vec3& axis);
        static Mat4 scale(const Vec3& scale);
        static Mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
        static Mat4 perspective(float fov, float aspectRatio, float near, float far);

        //operators
        friend Mat4 operator*(Mat4 left, const Mat4& right);
        friend Mat4 operator*(Mat4 left, const float& scalar);
        friend Mat4 operator*(const float& scalar, Mat4 right);
        Mat4& operator*=(const Mat4& matrix);
        friend std::ostream& operator<<(std::ostream& stream, const Mat4& matrix);
    };
    
}