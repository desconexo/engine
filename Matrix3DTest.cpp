#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Matrix3D.h"
#include "Vector3D.h"

TEST_CASE("Create an empty Matrix3D") {
    Matrix3D M = Matrix3D();

    CHECK(M[0][0] == 0);
    CHECK(M[0][1] == 0);
    CHECK(M[0][2] == 0);
    CHECK(M[1][0] == 0);
    CHECK(M[1][1] == 0);
    CHECK(M[1][2] == 0);
    CHECK(M[2][0] == 0);
    CHECK(M[2][1] == 0);
    CHECK(M[2][2] == 0);
}

TEST_CASE("Create Matrix3D") {
    Matrix3D M = Matrix3D(
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    );

    CHECK(M[0][0] == 1);
    CHECK(M[0][1] == 2);
    CHECK(M[0][2] == 3);
    CHECK(M[1][0] == 4);
    CHECK(M[1][1] == 5);
    CHECK(M[1][2] == 6);
    CHECK(M[2][0] == 7);
    CHECK(M[2][1] == 8);
    CHECK(M[2][2] == 9);
}

TEST_CASE("Create a Matrix3D from 3 Vector3D") {
    Vector3D a = Vector3D(1, 2, 3);
    Vector3D b = Vector3D(4, 5, 6);
    Vector3D c = Vector3D(7, 8, 9);
    Matrix3D M = Matrix3D(a, b, c);

    CHECK(M[0][0] == 1);
    CHECK(M[0][1] == 2);
    CHECK(M[0][2] == 3);
    CHECK(M[1][0] == 4);
    CHECK(M[1][1] == 5);
    CHECK(M[1][2] == 6);
    CHECK(M[2][0] == 7);
    CHECK(M[2][1] == 8);
    CHECK(M[2][2] == 9);
}

TEST_CASE("Get a value from a Matrix3D") {
    Matrix3D M = Matrix3D(
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    );

    CHECK(M(0, 0) == 1);
    CHECK(M(0, 1) == 2);
    CHECK(M(0, 2) == 3);
    CHECK(M(1, 0) == 4);
    CHECK(M(1, 1) == 5);
    CHECK(M(1, 2) == 6);
    CHECK(M(2, 0) == 7);
    CHECK(M(2, 1) == 8);
    CHECK(M(2, 2) == 9);
}

TEST_CASE("Get a value from a const Matrix3D") {
    const Matrix3D M = Matrix3D(
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    );

    CHECK(M(0, 0) == 1);
    CHECK(M(0, 1) == 2);
    CHECK(M(0, 2) == 3);
    CHECK(M(1, 0) == 4);
    CHECK(M(1, 1) == 5);
    CHECK(M(1, 2) == 6);
    CHECK(M(2, 0) == 7);
    CHECK(M(2, 1) == 8);
    CHECK(M(2, 2) == 9);
}

TEST_CASE("Get a row from a Matrix3D") {
    Matrix3D M = Matrix3D(
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    );

    Vector3D a = M[0];
    Vector3D b = M[1];
    Vector3D c = M[2];

    CHECK(a[0] == 1);
    CHECK(a[1] == 2);
    CHECK(a[2] == 3);
    CHECK(b[0] == 4);
    CHECK(b[1] == 5);
    CHECK(b[2] == 6);
    CHECK(c[0] == 7);
    CHECK(c[1] == 8);
    CHECK(c[2] == 9);
}

TEST_CASE("Get a row from a const Matrix3D") {
    const Matrix3D M = Matrix3D(
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    );

    Vector3D a = M[0];
    Vector3D b = M[1];
    Vector3D c = M[2];

    CHECK(a[0] == 1);
    CHECK(a[1] == 2);
    CHECK(a[2] == 3);
    CHECK(b[0] == 4);
    CHECK(b[1] == 5);
    CHECK(b[2] == 6);
    CHECK(c[0] == 7);
    CHECK(c[1] == 8);
    CHECK(c[2] == 9);
}

TEST_CASE("Get matrix determinant") {
    Matrix3D M = Matrix3D(
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    );

    CHECK(M.Determinant() == 0);
}
