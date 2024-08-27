#include "blpch.h"
#include "mat4.h"

namespace blitz {

    Mat4::Mat4() {
        for (int i = 0; i < 4 * 4; i++) {
            elements[i] = 0;
        }
    }

    Mat4::Mat4(const float& diagonal){
        for (int i = 0; i < 4 * 4; i++) {
            elements[i] = 0;
        }

        elements[0 + 0 * 4] = diagonal;
        elements[1 + 1 * 4] = diagonal;
        elements[2 + 2 * 4] = diagonal;
        elements[3 + 3 * 4] = diagonal;
    }

    Mat4::Mat4(const Mat4& other) {
        std::memcpy(elements, other.elements, 4 * 4 * sizeof(float));
    }

    Mat4& Mat4::operator=(const Mat4& other) {
        if (this != &other) {
            std::memcpy(elements, other.elements, 4 * 4 * sizeof(float));
        }
        return *this;
    }

    Mat4& Mat4::multiply(const Mat4& matrix) {
        Mat4 data;
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                float sum = 0.0f;
                for (int e = 0; e < 4; e++) {
                    sum += elements[c + e * 4] * matrix.elements[e + r * 4];
                }
                data.elements[c + r * 4] = sum;
            }
        }
        std::memcpy(elements, data.elements, 4 * 4 * sizeof(float));
		return *this;
    }

    Mat4& Mat4::multiply(const float& scalar) {
        for (int i = 0; i < 4 * 4; i++) {
            elements[i] *= scalar;
        }
        return *this;
    }

    Mat4 operator*(Mat4 left, const Mat4& right) {
        return left.multiply(right);
    }
  
    Mat4 operator*(Mat4 left, const float& scalar) {
        return left.multiply(scalar);
    }
    
    Mat4 operator*(const float& scalar, Mat4 right) {
        return right.multiply(scalar);
    }

    Mat4& Mat4::operator*=(const Mat4& matrix) {
        multiply(matrix);
        return *this;
    }

    Mat4& Mat4::setColumn(const int& index, const Vec4& data) {
        elements[0 + index * 4] = data.x;
        elements[1 + index * 4] = data.y;
        elements[2 + index * 4] = data.z;
        elements[3 + index * 4] = data.w;

        return *this;
    }

    std::ostream& operator<<(std::ostream& stream, const Mat4& matrix) {
        stream << "Mat4: [" << matrix.elements[0] << ", " << matrix.elements[4] << ", " << matrix.elements[8] << ", " << matrix.elements[12] << "]";
        stream << "      [" << matrix.elements[1] << ", " << matrix.elements[5] << ", " << matrix.elements[9] << ", " << matrix.elements[13] << "]";
        stream << "      [" << matrix.elements[2] << ", " << matrix.elements[6] << ", " << matrix.elements[10] << ", " << matrix.elements[14] << "]";
        stream << "      [" << matrix.elements[3] << ", " << matrix.elements[7] << ", " << matrix.elements[11] << ", " << matrix.elements[15] << "]";
        return stream;
    }

    Mat4 Mat4::identity() {
        return Mat4(1.0f);
    }

    Mat4 Mat4::orthographic(float left, float right, float bottom, float top, float near, float far) {
        Mat4 result(1.0f);

        result.elements[0 + 0 * 4] = 2.0f / (right - left);

		result.elements[1 + 1 * 4] = 2.0f / (top - bottom);

		result.elements[2 + 2 * 4] = 2.0f / (near - far);

		result.elements[0 + 3 * 4] = (left + right) / (left - right);
		result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		result.elements[2 + 3 * 4] = (far + near) / (far - near);

        return result;       
    }
    
    Mat4 Mat4::perspective(float fov, float aspectRatio, float near, float far) {
        Mat4 result;

        float q = 1.0f / std::tan(toRadians(fov) * 0.5f);

        float b = (-near - far) / (near - far);
        float c = (2.0f * near * far) / (near - far);

        result.elements[0 + 0 * 4] = q / aspectRatio;
        result.elements[1 + 1 * 4] = q;
        result.elements[2 + 2 * 4] = b;
        result.elements[3 + 2 * 4] = -1.0f;
        result.elements[2 + 3 * 4] = c;

        return result;
    }

    Mat4 Mat4::translate(const Vec3& translation) {
        Mat4 result(1.0f);
        result.elements[0 + 3 * 4] = translation.x;
        result.elements[1 + 3 * 4] = translation.y;
        result.elements[2 + 3 * 4] = translation.z;
        
        return result;
    }
  
    Mat4 Mat4::rotate(float angle, const Vec3& axis) {
        Mat4 result(1.0f);
        float rad = toRadians(angle);
        float sine = std::sin(rad);
        float cosine = std::cos(rad);
        float oc = 1.0f - cosine;

        float x = axis.x;
        float y = axis.y;
        float z = axis.z;

        if (Vec3(0, 0, 1) == axis) {
            result.elements[0 + 0 * 4] = cosine;
            result.elements[1 + 0 * 4] = sine;
            result.elements[0 + 1 * 4] = -sine;
            result.elements[1 + 1 * 4] = cosine;
        }
        if (Vec3(0, 1, 0) == axis) {
            result.elements[0 + 0 * 4] = cosine;
            result.elements[2 + 0 * 4] = -sine;
            result.elements[0 + 2 * 4] = sine;
            result.elements[2 + 2 * 4] = cosine;
        }
        if (Vec3(1, 0, 0) == axis) {
            result.elements[1 + 1 * 4] = cosine;
            result.elements[2 + 1 * 4] = sine;
            result.elements[1 + 2 * 4] = -sine;
            result.elements[2 + 2 * 4] = cosine;
        }

        std::cout << result << std::endl;

        return result;
    }
    
    Mat4 Mat4::scale(const Vec3& scale) {
        Mat4 result(1.0f);
        result.elements[0 + 0 * 4] = scale.x;
        result.elements[1 + 1 * 4] = scale.y;
        result.elements[2 + 2 * 4] = scale.z;

        return result;
    }
}
