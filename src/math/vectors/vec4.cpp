#include "vec4.h"


namespace blitz {

    Vec4::Vec4(const float& value) {
        x = value;
        y = value;
        z = value;
        w = 1.0f;
    }

    Vec4::Vec4(const float& x, const float& y) {
        this->x = x;
        this->y = y;
        z = 0.0f;
        w = 1.0f;
    }

    Vec4::Vec4(const float& x, const float& y, const float& z) {
        this->x = x;
        this->y = y;
        this->z = z;
        w = 1.0f;
    }

    Vec4::Vec4(const float& x, const float& y, const float& z, const float& w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    Vec4::Vec4(const Vec2& vector) {
        x = vector.x;
        y = vector.y;
        z = 0.0f;
        w = 1.0f;
    }

    Vec4::Vec4(const Vec3& vector) {
        x = vector.x;
        y = vector.y;
        z = vector.z;
        w = 1.0f;
    }

    Vec4::Vec4(const Vec4& vector) {
        x = vector.x;
        y = vector.y;
        z = vector.z;
        w = vector.w;
    }

    
    Vec4& Vec4::add(const Vec4& vec) {
        x += vec.x;
        y += vec.y;
        z += vec.z;
        w += vec.w;

        return *this;
    }

    Vec4& Vec4::subtract(const Vec4& vec) {
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;
        w -= vec.w;

        return *this;
    }

    Vec4& Vec4::multiply(const Vec4& vec) {
        x *= vec.x;
        y *= vec.y;
        z *= vec.z;
        w *= vec.w;

        return *this;
    }

    Vec4& Vec4::divide(const Vec4& vec) {
        x /= vec.x;
        y /= vec.y;
        z /= vec.z;
        w /= vec.w;

        return *this;
    }

    Vec4& Vec4::scale(const float& scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;

        return *this;
    }

    Vec4 operator+(Vec4 left, const Vec4& right) {
        return left.add(right);
    }

    Vec4 operator-(Vec4 left, const Vec4& right) {
        return left.subtract(right);
    }

    Vec4 operator*(Vec4 left, const Vec4& right) {
        return left.multiply(right);
    }

    Vec4 operator*(Vec4 left, const float& scalar) {
        return left.scale(scalar);
    }

    Vec4 operator*(const float& scalar, Vec4 right) {
        return right.scale(scalar);
    }

    Vec4 operator/(Vec4 left, const Vec4& right) {
        return left.divide(right);
    }

    Vec4& Vec4::operator+=(const Vec4& vec) {
        add(vec);
        return *this;
    }

    Vec4& Vec4::operator-=(const Vec4& vec) {
        subtract(vec);
        return *this;
    }

    Vec4& Vec4::operator*=(const Vec4& vec) {
        multiply(vec);
        return *this;
    }

    Vec4& Vec4::operator/=(const Vec4& vec) {
        divide(vec);
        return *this;
    }

    bool Vec4::operator==(const Vec4& vec) {
        return x == vec.x && y == vec.y && z == vec.z && w == vec.w;
    }

    bool Vec4::operator!=(const Vec4& vec) {
        return !(*this == vec);
    }

    std::ostream& operator<<(std::ostream& stream, const Vec4& vec) {
        stream << "Vec4: (" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w <<")";
        return stream;
    }


}
