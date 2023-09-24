#include "Vector3D.h"

Vector3D::Vector3D() : x(0.0f), y(0.0f), z(0.0f) {
}

Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {
}

float& Vector3D::operator[](int i) {
    return ((&x)[i]);
}

const float& Vector3D::operator[](int i) const {
    return ((&x)[i]);
}

Vector3D& Vector3D::operator *=(float s) {
    x *= s;
    y *= s;
    z *= s;
    return (*this);
}

Vector3D& Vector3D::operator /=(float s) {
    s = 1.0F / s;
    x *= s;
    y *= s;
    z *= s;
    return (*this);
}

Vector3D& Vector3D::operator +=(const Vector3D& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return (*this);
}

Vector3D& Vector3D::operator -=(const Vector3D& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return (*this);
}