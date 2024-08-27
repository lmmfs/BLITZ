#pragma once

namespace blitz {
    struct Vec2 {

        float x;
        float y;

        //vector constructors
        Vec2();
        Vec2(const float& value);
        Vec2(const float& x, const float& y);
        Vec2(const Vec2& vector);

        //operators
        
        friend Vec2 operator+(Vec2 left, const Vec2& right);
        friend Vec2 operator-(Vec2 left, const Vec2& right);
        friend Vec2 operator*(Vec2 left, const Vec2& right);
        friend Vec2 operator*(Vec2 left, const float& scalar);
        friend Vec2 operator*(const float& scalar, Vec2 right);
        friend Vec2 operator/(Vec2 left, const Vec2& right);

        Vec2& operator+=(const Vec2& vec);
        Vec2& operator-=(const Vec2& vec);
        Vec2& operator*=(const Vec2& vec);
        Vec2& operator/=(const Vec2& vec);
        
        bool operator==(const Vec2& vec);
        bool operator!=(const Vec2& vec);
        
        friend std::ostream& operator<<(std::ostream& stream, const Vec2& vec);

        float magnitude();
        Vec2& normalize();
        float dot(const Vec2& vec);
        Vec2& add(const Vec2& vec);
        Vec2& subtract(const Vec2& vec);
        Vec2& multiply(const Vec2& vec);
        Vec2& multiply(const float& scalar);
        Vec2& divide(const Vec2& vec);
    };
}

