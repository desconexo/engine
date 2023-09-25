#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <cmath>

struct Vector3D {
    float x, y, z;

    Vector3D();
    Vector3D(float x, float y, float z);

    float& operator[](int i);
    const float& operator[](int i) const;

    Vector3D& operator *=(float s);
    Vector3D& operator /=(float s);
    Vector3D& operator +=(const Vector3D& v);
    Vector3D& operator -=(const Vector3D& v);
};

inline Vector3D operator *(const Vector3D& v, float s) {
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator /(const Vector3D& v, float s) {
    s = 1.0F / s;
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator -(const Vector3D& v) {
    return (Vector3D(-v.x, -v.y, -v.z));
}

inline Vector3D operator +(const Vector3D& a, const Vector3D& b) {
    return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline Vector3D operator -(const Vector3D& a, const Vector3D& b) {
    return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline float Magnitude(const Vector3D& v) {
    return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline Vector3D Normalize(const Vector3D& v) {
    // return (v / Magnitude(v)); // original and not optimized

    // optimized
    float magnitudeSquared = v.x * v.x + v.y * v.y + v.z * v.z;

    if (magnitudeSquared > 0.0F) {
        float reciprocalMagnitude = 1.0F / sqrtf(magnitudeSquared);
        return v * reciprocalMagnitude;
    }

    return v;
}

inline float Dot(const Vector3D& a, const Vector3D& b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline Vector3D Cross(const Vector3D& a, const Vector3D& b) {
    return (Vector3D(a.y * b.z - a.z * b.y,
                     a.z * b.x - a.x * b.z,
                     a.x * b.y - a.y * b.x));
}

inline Vector3D Project(const Vector3D& a, const Vector3D& b) {
    return (b * (Dot(a, b) / Dot(b, b)));
}

inline Vector3D Reject(const Vector3D& a, const Vector3D& b) {
    return (a - Project(a, b));
}

#endif // VECTOR3D_H