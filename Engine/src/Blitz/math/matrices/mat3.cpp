#include "blpch.h"
#include "mat3.h"

namespace blitz {
    Mat3::Mat3() {
        for (int i = 0; i < 3 * 3; i++) {
            elements[i] = 0;
        }
    }

    Mat3::Mat3(const float& diagonal){
        for (int i = 0; i < 3 * 3; i++) {
            elements[i] = 0;
        }

        elements[0 + 0 * 3] = diagonal;
        elements[1 + 1 * 3] = diagonal;
        elements[2 + 2 * 3] = diagonal;
    }

    Mat3::Mat3(const Mat3& other) {
        std::memcpy(elements, other.elements, 3 * 3 * sizeof(float));
    }

    Mat3& Mat3::operator=(const Mat3& other) {
        if (this != &other) {
            std::memcpy(elements, other.elements, 3 * 3 * sizeof(float));
        }
        return *this;
    }

    Mat3 Mat3::identity(){
        return Mat3(1.0f);
    }

    Mat3& Mat3::multiply(const Mat3& matrix) {
        Mat3 data;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                float sum = 0.0f;
                for (int e = 0; e < 3; e++) {
                    sum += elements[c + e * 3] * matrix.elements[e + r * 3];
                }
                data.elements[c + r * 3] = sum;
            }
        }
        std::memcpy(elements, data.elements, 3 * 3 * sizeof(float));
		return *this;
    }

    Mat3& Mat3::multiply(const float& scalar) {
        for (int i = 0; i < 3 * 3; i++) {
            elements[i] *= scalar;
        }
        return *this;
    }

    Mat3 Mat3::transpose() {
        //swap 1 <-> 3
        //swap 5 <-> 7
        //swap 2 <-> 6
        Mat3 data;
        data.elements[0] = elements[0];
        data.elements[1] = elements[3];
        data.elements[2] = elements[6];
        data.elements[3] = elements[1];
        data.elements[4] = elements[4];
        data.elements[5] = elements[7];
        data.elements[6] = elements[2];
        data.elements[7] = elements[5];
        data.elements[8] = elements[8];

        return data;
    }

    Mat3 Mat3::invert() {
        float d = determinant();
        if (d == 0.0f) {
            //TODO: probably explode because divide by 0
            return *this;
        }

        Mat3 data;

        data.elements[0] = elements[4] * elements[8] - elements[5] * elements[7];
        data.elements[1] = -(elements[1] * elements[8] - elements[2] * elements[7]);
        data.elements[2] = elements[1] * elements[5] - elements[2] * elements[4];
        data.elements[3] = -(elements[3] * elements[8] - elements[5] * elements[6]);
        data.elements[4] = elements[0] * elements[8] - elements[2] * elements[6];
        data.elements[5] = -(elements[0] * elements[5] - elements[2] * elements[3]);
        data.elements[6] = elements[3] * elements[7] - elements[4] * elements[6];
        data.elements[7] = -(elements[0] * elements[7] - elements[1] * elements[6]);
        data.elements[8] = elements[0] * elements[4] - elements[1] * elements[3];

        std::cout << data << std::endl;

        data.multiply(1/d);

        return data;
    }

    float Mat3::determinant() const {
        float temp1 = elements[0] * (elements[4] * elements[8] - elements[5] * elements[7]);
        float temp2 = -elements[3] * (elements[1] * elements[8] - elements[2] * elements[7]);
        float temp3 = elements[6] * (elements[1] * elements[5] - elements[2] * elements[4]);

        return temp1 + temp2 + temp3;
    }

    Mat3& Mat3::setColumn(const int& index, const Vec3& data) {
        elements[0 + index * 3] = data.x;
        elements[1 + index * 3] = data.y;
        elements[2 + index * 3] = data.z;

        return *this;
    }

    Mat3 operator*(Mat3 left, const Mat3& right) {
        return left.multiply(right);
    }
  
    Mat3 operator*(Mat3 left, const float& scalar) {
        return left.multiply(scalar);
    }
    
    Mat3 operator*(const float& scalar, Mat3 right) {
        return right.multiply(scalar);
    }

    Mat3& Mat3::operator*=(const Mat3& matrix) {
        multiply(matrix);
        return *this;
    }

    std::ostream& operator<<(std::ostream& stream, const Mat3& matrix) {
        stream << "Mat3: [" << matrix.elements[0] << ", " << matrix.elements[3] << ", " << matrix.elements[6] << "]";
        stream << "      [" << matrix.elements[1] << ", " << matrix.elements[4] << ", " << matrix.elements[7] << "]";
        stream << "      [" << matrix.elements[2] << ", " << matrix.elements[5] << ", " << matrix.elements[8] << "]";
        return stream;
    }

}