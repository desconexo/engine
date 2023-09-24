#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Vector3D.h"

TEST_CASE("Create a Vector3D") {
    Vector3D v = Vector3D(1, 2, 3);
    
    CHECK(v[0] == 1);
    CHECK(v[1] == 2);
    CHECK(v[2] == 3);
}

TEST_CASE("Multiply a Vector3D by a scalar and save the result in a new Vector3D") {
    Vector3D v = Vector3D(1, 2, 3);
    Vector3D v2 = v * 2;

    CHECK(v2[0] == 2);
    CHECK(v2[1] == 4);
    CHECK(v2[2] == 6);
}

TEST_CASE("Multiply a Vector3D by a scalar updating the original Vector3D") {
    Vector3D v = Vector3D(1, 2, 3);
    v *= 2;

    CHECK(v[0] == 2);
    CHECK(v[1] == 4);
    CHECK(v[2] == 6);
}

TEST_CASE("Divide a Vector3D by a scalar and save the result in a new Vector3D") {
    Vector3D v = Vector3D(1, 2, 3);
    Vector3D v2 = v / 2;

    CHECK(v2[0] == 0.5);
    CHECK(v2[1] == 1);
    CHECK(v2[2] == 1.5);
}

TEST_CASE("Divide a Vector3D by a scalar updating the original Vector3D") {
    Vector3D v = Vector3D(1, 2, 3);
    v /= 2;

    CHECK(v[0] == 0.5);
    CHECK(v[1] == 1);
    CHECK(v[2] == 1.5);
}

TEST_CASE("Negate a Vector3D") {
    Vector3D v = Vector3D(1, 2, 3);
    Vector3D v2 = -v;

    CHECK(v2[0] == -1);
    CHECK(v2[1] == -2);
    CHECK(v2[2] == -3);
}

TEST_CASE("Add two Vector3Ds and save the result in a new Vector3D") {
    Vector3D v = Vector3D(1, 2, 3);
    Vector3D v2 = Vector3D(4, 5, 6);
    Vector3D v3 = v + v2;

    CHECK(v3[0] == 5);
    CHECK(v3[1] == 7);
    CHECK(v3[2] == 9);
}

TEST_CASE("Add two Vector3Ds updating the original Vector3D") {
    Vector3D v = Vector3D(1, 2, 3);
    Vector3D v2 = Vector3D(4, 5, 6);
    v += v2;

    CHECK(v[0] == 5);
    CHECK(v[1] == 7);
    CHECK(v[2] == 9);
}

TEST_CASE("Subtract two Vector3Ds and save the result in a new Vector3D") {
    Vector3D v = Vector3D(1, 2, 3);
    Vector3D v2 = Vector3D(4, 5, 6);
    Vector3D v3 = v - v2;

    CHECK(v3[0] == -3);
    CHECK(v3[1] == -3);
    CHECK(v3[2] == -3);
}

TEST_CASE("Subtract two Vector3Ds updating the original Vector3D") {
    Vector3D v = Vector3D(1, 2, 3);
    Vector3D v2 = Vector3D(4, 5, 6);
    v -= v2;

    CHECK(v[0] == -3);
    CHECK(v[1] == -3);
    CHECK(v[2] == -3);
}

TEST_CASE("Get the magnitude of a Vector3D") {
    Vector3D v = Vector3D(1, 2, 3);
    float magnitude = Magnitude(v);

    CHECK(std::to_string(magnitude) == "3.741657");
}

TEST_CASE("Normalize a Vector3D") {
    Vector3D v = Vector3D(1, 2, 3);
    Vector3D normalized = Normalize(v);

    CHECK(std::to_string(normalized[0]) == "0.267261");
    CHECK(std::to_string(normalized[1]) == "0.534522");
    CHECK(std::to_string(normalized[2]) == "0.801784");
}