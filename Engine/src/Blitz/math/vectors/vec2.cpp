#include "vec2.h"


namespace blitz {

    Vec2::Vec2() {
        x = 0.0f;
        y = 0.0f;
    }

    Vec2::Vec2(const float& value) {
        x = value;
        y = value;
    }

    Vec2::Vec2(const float& x, const float& y) {
        this->x = x;
        this->y = y;
    }

    Vec2::Vec2(const Vec2& vector) {
        x = vector.x;
        y = vector.y;
    }

    
    Vec2& Vec2::add(const Vec2& vec) {
        x += vec.x;
        y += vec.y;

        return *this;
    }

    Vec2& Vec2::subtract(const Vec2& vec) {
        x -= vec.x;
        y -= vec.y;

        return *this;
    }

    Vec2& Vec2::multiply(const Vec2& vec) {
        x *= vec.x;
        y *= vec.y;

        return *this;
    }

    Vec2& Vec2::divide(const Vec2& vec) {
        x /= vec.x;
        y /= vec.y;

        return *this;
    }

    Vec2& Vec2::multiply(const float& scalar) {
        x *= scalar;
        y *= scalar;

        return *this;
    }

    Vec2 operator+(Vec2 left, const Vec2& right) {
        return left.add(right);
    }

    Vec2 operator-(Vec2 left, const Vec2& right) {
        return left.subtract(right);
    }

    Vec2 operator*(Vec2 left, const Vec2& right) {
        return left.multiply(right);
    }

    Vec2 operator*(Vec2 left, const float& scalar) {
        return left.multiply(scalar);
    }

    Vec2 operator*(const float& scalar, Vec2 right) {
        return right.multiply(scalar);
    }

    Vec2 operator/(Vec2 left, const Vec2& right) {
        return left.divide(right);
    }

    Vec2& Vec2::operator+=(const Vec2& vec) {
        add(vec);
        return *this;
    }

    Vec2& Vec2::operator-=(const Vec2& vec) {
        subtract(vec);
        return *this;
    }

    Vec2& Vec2::operator*=(const Vec2& vec) {
        multiply(vec);
        return *this;
    }

    Vec2& Vec2::operator/=(const Vec2& vec) {
        divide(vec);
        return *this;
    }

    bool Vec2::operator==(const Vec2& vec) {
        return x == vec.x && y == vec.y;
    }

    bool Vec2::operator!=(const Vec2& vec) {
        return !(*this == vec);
    }

    float Vec2::magnitude() {
        return std::sqrt(x * x + y * y);
    }

    Vec2& Vec2::normalize() {
        float mag = magnitude();
        multiply(1 / mag);
        return *this;
    }

    float Vec2::dot(const Vec2& vec) {
        return x * vec.x + y * vec.y;
    }

    std::ostream& operator<<(std::ostream& stream, const Vec2& vec) {
        stream << "Vec2: (" << vec.x << ", " << vec.y <<")";
        return stream;
    }
}
