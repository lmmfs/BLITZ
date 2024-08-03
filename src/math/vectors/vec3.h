#pragma once

#include "vec2.h"
#include <iostream>

namespace blitz {
    struct Vec3 {

        float x;
        float y;
        float z;

        //vector constructors
        Vec3() = default;
        Vec3(const float& value);
        Vec3(const float& x, const float& y);
        Vec3(const float& x, const float& y, const float& z);
        Vec3(const Vec2& vector);
        Vec3(const Vec3& vector);

        //operators
        
        friend Vec3 operator+(Vec3 left, const Vec3& right);
        friend Vec3 operator-(Vec3 left, const Vec3& right);
        friend Vec3 operator*(Vec3 left, const Vec3& right);
        friend Vec3 operator*(Vec3 left, const float& scalar);
        friend Vec3 operator*(const float& scalar, Vec3 right);
        friend Vec3 operator/(Vec3 left, const Vec3& right);

        Vec3& operator+=(const Vec3& vec);
        Vec3& operator-=(const Vec3& vec);
        Vec3& operator*=(const Vec3& vec);
        Vec3& operator/=(const Vec3& vec);
        
        bool operator==(const Vec3& vec);
        bool operator!=(const Vec3& vec);
        
        friend std::ostream& operator<<(std::ostream& stream, const Vec3& vec);

        float magnitude();
        Vec3& normalize();
        float dot(const Vec3& vec);
        Vec3& add(const Vec3& vec);
        Vec3& subtract(const Vec3& vec);
        Vec3& multiply(const Vec3& vec);
        Vec3& multiply(const float& scalar);
        Vec3& divide(const Vec3& vec);
    };
}

