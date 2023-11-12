#include "Vector3D.h"

struct Matrix3D {
    float n[3][3];

    Matrix3D();
    Matrix3D(float n00, float n01, float n02,
             float n10, float n11, float n12,
             float n20, float n21, float n22);
    Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c);

    float& operator()(int i, int j);
    const float& operator()(int i, int j) const;
    Vector3D& operator[](int j);
    const Vector3D& operator[](int j) const;

    float Determinant() const;

    friend Matrix3D operator *(const Matrix3D& M, const Matrix3D& B) {
        return (
            Matrix3D(
                M(0,0) * B(0,0) + M(0, 1) * B(1, 0) + M(0, 2) * B(2, 0),
                M(0,0) * B(0,1) + M(0, 1) * B(1, 1) + M(0, 2) * B(2, 1),
                M(0,0) * B(0,2) + M(0, 1) * B(1, 2) + M(0, 2) * B(2, 2),
                M(1,0) * B(0,0) + M(1, 1) * B(1, 0) + M(1, 2) * B(2, 0),
                M(1,0) * B(0,1) + M(1, 1) * B(1, 1) + M(1, 2) * B(2, 1),
                M(1,0) * B(0,2) + M(1, 1) * B(1, 2) + M(1, 2) * B(2, 2),
                M(2,0) * B(0,0) + M(2, 1) * B(1, 0) + M(2, 2) * B(2, 0),
                M(2,0) * B(0,1) + M(2, 1) * B(1, 1) + M(2, 2) * B(2, 1),
                M(2,0) * B(0,2) + M(2, 1) * B(1, 2) + M(2, 2) * B(2, 2)
            )
        );
    }
    
    friend Vector3D operator *(const Matrix3D& M, const Vector3D v) {
        return (
            Vector3D(
                M(0,0) * v.x + M(0, 1) * v.y + M(0, 2) * v.z,
                M(1,0) * v.x + M(1, 1) * v.y + M(1, 2) * v.z,
                M(2,0) * v.x + M(2, 1) * v.y + M(2, 2) * v.z
            )
        );
    }
};
