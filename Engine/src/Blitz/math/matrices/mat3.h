#pragma once

#include "../math.h"


namespace blitz {
    struct Mat3
    {   
        union
        {
            float elements [3 * 3];
            Vec3 columns[3];
        };
        

        //column major [row + col * 3]

        Mat3();
        Mat3(const float& diagonal);
        Mat3(const Mat3& other);
        Mat3& operator=(const Mat3& other); 

        static Mat3 identity();

        Mat3& multiply(const Mat3& matrix);
        Mat3& multiply(const float& scalar);
        Mat3 transpose();
        Mat3 invert();
        float determinant() const;
        Mat3& setColumn(const int& index, const Vec3& data);

        friend Mat3 operator*(Mat3 left, const Mat3& right);
        friend Mat3 operator*(Mat3 left, const float& scalar);
        friend Mat3 operator*(const float& scalar, Mat3 right);
        Mat3& operator*=(const Mat3& matrix);
        friend std::ostream& operator<<(std::ostream& stream, const Mat3& matrix);
    };
    
}