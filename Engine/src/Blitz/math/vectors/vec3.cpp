#include "blpch.h"
#include "vec3.h"


namespace blitz {

    Vec3::Vec3(const float& value) {
        x = value;
        y = value;
        z = value;
    }

    Vec3::Vec3(const float& x, const float& y) {
        this->x = x;
        this->y = y;
        z = 0.0f;
    }

    Vec3::Vec3(const float& x, const float& y, const float& z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vec3::Vec3(const Vec2& vector){
        x = vector.x;
        y = vector.y;
        z = 0.0f;
    }

    Vec3::Vec3(const Vec3& vector) {
        x = vector.x;
        y = vector.y;
        z = vector.z;
    }

    
    Vec3& Vec3::add(const Vec3& vec) {
        x += vec.x;
        y += vec.y;
        z += vec.z;

        return *this;
    }

    Vec3& Vec3::subtract(const Vec3& vec) {
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;

        return *this;
    }

    Vec3& Vec3::multiply(const Vec3& vec) {
        x *= vec.x;
        y *= vec.y;
        z *= vec.z;

        return *this;
    }

    Vec3& Vec3::divide(const Vec3& vec) {
        x /= vec.x;
        y /= vec.y;
        z /= vec.z;

        return *this;
    }

    Vec3& Vec3::multiply(const float& scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;

        return *this;
    }

    Vec3 operator+(Vec3 left, const Vec3& right) {
        return left.add(right);
    }

    Vec3 operator-(Vec3 left, const Vec3& right) {
        return left.subtract(right);
    }

    Vec3 operator*(Vec3 left, const Vec3& right) {
        return left.multiply(right);
    }

    Vec3 operator*(Vec3 left, const float& scalar) {
        return left.multiply(scalar);
    }

    Vec3 operator*(const float& scalar, Vec3 right) {
        return right.multiply(scalar);
    }

    Vec3 operator/(Vec3 left, const Vec3& right) {
        return left.divide(right);
    }

    Vec3& Vec3::operator+=(const Vec3& vec) {
        add(vec);
        return *this;
    }

    Vec3& Vec3::operator-=(const Vec3& vec) {
        subtract(vec);
        return *this;
    }

    Vec3& Vec3::operator*=(const Vec3& vec) {
        multiply(vec);
        return *this;
    }

    Vec3& Vec3::operator/=(const Vec3& vec) {
        divide(vec);
        return *this;
    }

    bool Vec3::operator==(const Vec3& vec) {
        return x == vec.x && y == vec.y && z == vec.z;
    }

    bool Vec3::operator!=(const Vec3& vec) {
        return !(*this == vec);
    }

    float Vec3::magnitude() {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vec3& Vec3::normalize() {
        float mag = magnitude();
        multiply(1 / mag);
        return *this;
    }

    Vec3 Vec3::cross(const Vec3& vec) {
        return Vec3((y * vec.z) - (z * vec.y), (z * vec.x) - (x * vec.z), (x * vec.y) - (y * vec.x));
    }

    float Vec3::dot(const Vec3& vec) {
        return x * vec.x + y * vec.y + z * vec.z;
    }

    std::ostream& operator<<(std::ostream& stream, const Vec3& vec) {
        stream << "Vec3: (" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return stream;
    }
}
