#pragma once

#include "vec3.h"
#include <iostream>

namespace blitz {
    struct Vec4 {

        float x;
        float y;
        float z;
        float w;

        //vector constructors
        Vec4() = default;
        Vec4(const float& value);
        Vec4(const float& x, const float& y);
        Vec4(const float& x, const float& y, const float& z);
        Vec4(const float& x, const float& y, const float& z, const float& w);
        Vec4(const Vec2& vector);
        Vec4(const Vec3& vector);
        Vec4(const Vec4& vector);

        //operators
        
        friend Vec4 operator+(Vec4 left, const Vec4& right);
        friend Vec4 operator-(Vec4 left, const Vec4& right);
        friend Vec4 operator*(Vec4 left, const Vec4& right);
        friend Vec4 operator*(Vec4 left, const float& scalar);
        friend Vec4 operator*(const float& scalar, Vec4 right);
        friend Vec4 operator/(Vec4 left, const Vec4& right);

        Vec4& operator+=(const Vec4& vec);
        Vec4& operator-=(const Vec4& vec);
        Vec4& operator*=(const Vec4& vec);
        Vec4& operator/=(const Vec4& vec);
        
        bool operator==(const Vec4& vec);
        bool operator!=(const Vec4& vec);
        
        friend std::ostream& operator<<(std::ostream& stream, const Vec4& vec);

        float magnitude();
        Vec4& normalize();
        float dot(const Vec4& vec);
        Vec4& add(const Vec4& vec);
        Vec4& subtract(const Vec4& vec);
        Vec4& multiply(const Vec4& vec);
        Vec4& multiply(const float& scalar);
        Vec4& divide(const Vec4& vec);
    };
}

