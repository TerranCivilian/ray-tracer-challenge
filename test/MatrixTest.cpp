#include <gtest/gtest.h>
#include <Matrix.h>
#include <Util.h>

TEST(MatrixTest, ConstructMat4) {
    matrix::Mat4 M{{
        {1, 2, 3, 4},
        {5.5, 6.5, 7.5, 8.5},
        {9, 10, 11, 12},
        {13.5, 14.5, 15.5, 16.5}
    }};
    EXPECT_NEAR(M.at(0,0), 1, util::err);
    EXPECT_NEAR(M.at(0,3), 4, util::err);
    EXPECT_NEAR(M.at(1,0), 5.5, util::err);
    EXPECT_NEAR(M.at(1,2), 7.5, util::err);
    EXPECT_NEAR(M.at(2,2), 11, util::err);
    EXPECT_NEAR(M.at(3,0), 13.5, util::err);
    EXPECT_NEAR(M.at(3,2), 15.5, util::err);
}

TEST(MatrixTest, ConstructMat2) {
    matrix::Mat2 M{{
        {-3, 5},
        {1, -2}
    }};
    EXPECT_NEAR(M.at(0,0), -3, util::err);
    EXPECT_NEAR(M.at(0,1), 5, util::err);
    EXPECT_NEAR(M.at(1,0), 1, util::err);
    EXPECT_NEAR(M.at(1,1), -2, util::err);
}

TEST(MatrixTest, ConstructMat3) {
    matrix::Mat3 M{{
        {-3, 5, 0},
        {1, -2, -7},
        {0, 1, 1}
    }};
    EXPECT_NEAR(M.at(0,0), -3, util::err);
    EXPECT_NEAR(M.at(1,1), -2, util::err);
    EXPECT_NEAR(M.at(2,2), 1, util::err);
}

TEST(MatrixTest, MatEqual4) {
    matrix::Mat4 A{{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}
    }};
    matrix::Mat4 B{{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}
    }};
    EXPECT_EQ(A, B);
}

TEST(MatrixTest, MatNotEqual4) {
    matrix::Mat4 A{{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}
    }};
    matrix::Mat4 B{{
        {2, 3, 4, 5},
        {6, 7, 8, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    }};
    EXPECT_NE(A, B);
}

TEST(MatrixTest, MatEqual3) {
    matrix::Mat3 A{{
        {1, 2, 3},
        {5, 6, 7},
        {9, 8, 7}
    }};
    matrix::Mat3 B{{
        {1, 2, 3},
        {5, 6, 7},
        {9, 8, 7}
    }};
    EXPECT_EQ(A, B);
}

TEST(MatrixTest, MatNotEqual3) {
    matrix::Mat3 A{{
        {1, 2, 3},
        {5, 6, 7},
        {9, 8, 7}
    }};
    matrix::Mat3 B{{
        {2, 3, 4},
        {6, 7, 8},
        {8, 7, 6}
    }};
    EXPECT_NE(A, B);
}

TEST(MatrixTest, MatEqual2) {
    matrix::Mat2 A{{
        {1, 2},
        {3, 4}
    }};
    matrix::Mat2 B{{
        {1, 2},
        {3, 4}
    }};
    EXPECT_EQ(A, B);
}

TEST(MatrixTest, MatNotEqual2) {
    matrix::Mat2 A{{
        {1, 2},
        {3, 4}
    }};
    matrix::Mat2 B{{
        {2, 3},
        {4, 5}
    }};
    EXPECT_NE(A, B);
}

TEST(MatrixTest, Multiply) {
    matrix::Mat4 A{{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}
    }};
    matrix::Mat4 B{{
        {-2, 1, 2, 3},
        {3, 2, 1, -1},
        {4, 3, 6, 5},
        {1, 2, 7, 8}
    }};
    matrix::Mat4 expected{{
        {20, 22, 50, 48},
        {44, 54, 114, 108},
        {40, 58, 110, 102},
        {16, 26, 46, 42}
    }};
    EXPECT_EQ(A * B, expected);
}

TEST(MatrixTest, MultiplyByTuple) {
    matrix::Mat4 A{{
        {1, 2, 3, 4},
        {2, 4, 4, 2},
        {8, 6, 4, 1},
        {0, 0, 0, 1}
    }};
    tuple::Tuple b{1, 2, 3, 1};
    tuple::Tuple expected{18, 24, 33, 1};
    EXPECT_EQ(A * b, expected);
}

TEST(MatrixTest, MultiplyByIdentityMatrix) {
    matrix::Mat4 A{{
        {0, 1, 2, 4},
        {1, 2, 4, 8},
        {2, 4, 8, 16},
        {4, 8, 16, 32}
    }};
    matrix::Mat4 id = matrix::identity();
    EXPECT_EQ(A * id, A);
}

TEST(MatrixTest, MultiplyIdentityMatrixByTuple) {
    tuple::Tuple a{1, 2, 3, 4};
    EXPECT_EQ(matrix::identity() * a, a);
}

TEST(MatrixTest, Transpose) {
    matrix::Mat4 A{{
        {0, 9, 3, 0},
        {9, 8, 0, 8},
        {1, 8, 5, 3},
        {0, 0, 5, 8}
    }};
    matrix::Mat4 expected{{
        {0, 9, 1, 0},
        {9, 8, 8, 0},
        {3, 0, 5, 5},
        {0, 8, 3, 8}
    }};
    EXPECT_EQ(matrix::transpose(A), expected);
}

TEST(MatrixTest, TransposeIdentityMatrix) {
    matrix::Mat4 A = matrix::transpose(matrix::identity());
    EXPECT_EQ(A, matrix::identity());
}

TEST(MatrixTest, Determinant2) {
    matrix::Mat2 A{{
        {1, 5},
        {-3, 2}
    }};
    EXPECT_NEAR(matrix::determinant(A), 17, util::err);
}

TEST(MatrixTest, Submatrix3) {
    matrix::Mat3 A{{
        {1, 5, 0},
        {-3, 2, 7},
        {0, 6, -3}
    }};
    matrix::Mat2 expected{{
        {-3, 2},
        {0, 6}
    }};
    EXPECT_EQ(A.submatrix(0, 2), expected);
}

TEST(MatrixTest, Submatrix4) {
    matrix::Mat4 A{{
        {-6, 1, 1, 6},
        {-8, 5, 8, 6},
        {-1, 0, 8, 2},
        {-7, 1, -1, 1}
    }};
    matrix::Mat3 expected{{
        {-6, 1, 6},
        {-8, 8, 6},
        {-7, -1, 1}
    }};
    EXPECT_EQ(A.submatrix(2, 1), expected);
}

TEST(MatrixTest, Minor) {
    matrix::Mat3 A{{
        {3, 5, 0},
        {2, -1, -7},
        {6, -1, 5}
    }};
    matrix::Mat2 B = A.submatrix(1, 0);
    EXPECT_NEAR(matrix::determinant(B), 25, util::err);
    EXPECT_NEAR(A.minor(1, 0), 25, util::err);
}

TEST(MatrixTest, Cofactor) {
    matrix::Mat3 A{{
        {3, 5, 0},
        {2, -1, -7},
        {6, -1, 5}
    }};
    EXPECT_NEAR(A.minor(0, 0), -12, util::err);
    EXPECT_NEAR(A.cofactor(0, 0), -12, util::err);
    EXPECT_NEAR(A.minor(1, 0), 25, util::err);
    EXPECT_NEAR(A.cofactor(1, 0), -25, util::err);
}

TEST(MatrixTest, Determinant3) {
    matrix::Mat3 A{{
        {1, 2, 6},
        {-5, 8, -4},
        {2, 6, 4}
    }};
    EXPECT_NEAR(A.cofactor(0, 0), 56, util::err);
    EXPECT_NEAR(A.cofactor(0, 1), 12, util::err);
    EXPECT_NEAR(A.cofactor(0, 2), -46, util::err);
    EXPECT_NEAR(matrix::determinant(A), -196, util::err);
}

TEST(MatrixTest, Determinant4) {
    matrix::Mat4 A{{
        {-2, -8, 3, 5},
        {-3, 1, 7, 3},
        {1, 2, -9, 6},
        {-6, 7, 7, -9}
    }};
    EXPECT_NEAR(A.cofactor(0, 0), 690, util::err);
    EXPECT_NEAR(A.cofactor(0, 1), 447, util::err);
    EXPECT_NEAR(A.cofactor(0, 2), 210, util::err);
    EXPECT_NEAR(A.cofactor(0, 3), 51, util::err);
    EXPECT_NEAR(matrix::determinant(A), -4071, util::err);
}

TEST(MatrixTest, IsInvertible) {
    matrix::Mat4 A{{
        {6, 4, 4, 4},
        {5, 5, 7, 6},
        {4, -9, 3, -7},
        {9, 1, 7, -6}
    }};
    EXPECT_NEAR(matrix::determinant(A), -2120, util::err);
    EXPECT_TRUE(matrix::is_invertible(A));
}

TEST(MatrixTest, IsNotInvertible) {
    matrix::Mat4 A{{
        {-4, 2, -2, -3},
        {9, 6, 2, 6},
        {0, -5, 1, -5},
        {0, 0, 0, 0}
    }};
    EXPECT_NEAR(matrix::determinant(A), 0, util::err);
    EXPECT_FALSE(matrix::is_invertible(A));
}

TEST(MatrixTest, Inverse1) {
    matrix::Mat4 A{{
        {-5, 2, 6, -8},
        {1, -5, 1, 8},
        {7, 7, -6, -7},
        {1, -3, 7, 4}
    }};
    matrix::Mat4 B = matrix::inverse(A);
    matrix::Mat4 expected_B{{
        {0.21805, 0.45113, 0.24060, -0.04511},
        {-0.80827, -1.45677, -0.44361, 0.52068},
        {-0.07895, -0.22368, -0.05263, 0.19737},
        {-0.52256, -0.81391, -0.30075, 0.30639}
    }};
    EXPECT_NEAR(matrix::determinant(A), 532, util::err);
    EXPECT_NEAR(A.cofactor(2, 3), -160, util::err);
    EXPECT_NEAR(B.at(3, 2), -160.0/532.0, util::err);
    EXPECT_NEAR(A.cofactor(3, 2), 105, util::err);
    EXPECT_NEAR(B.at(2, 3), 105.0/532.0, util::err);
    EXPECT_EQ(B, expected_B);
}

TEST(MatrixTest, Inverse2) {
    matrix::Mat4 A{{
        {8, -5, 9, 2},
        {7, 5, 6, 1},
        {-6, 0, 9, 6},
        {-3, 0, -9, -4}
    }};
    matrix::Mat4 expected{{
        {-0.15385, -0.15385, -0.28205, -0.53846},
        {-0.07692, 0.12308, 0.02564, 0.03077},
        {0.35897, 0.35897, 0.43590, 0.92308},
        {-0.69231, -0.69231, -0.76923, -1.92308}
    }};
    EXPECT_EQ(matrix::inverse(A), expected);
}

TEST(MatrixTest, Inverse3) {
    matrix::Mat4 A{{
        {9, 3, 0, 9},
        {-5, -2, -6, -3},
        {-4, 9, 6, 4},
        {-7, 6, 6, 2}
    }};
    matrix::Mat4 expected{{
        {-0.04074, -0.07778, 0.14444, -0.22222},
        {-0.07778, 0.03333, 0.36667, -0.33333},
        {-0.02901, -0.14630, -0.10926, 0.12963},
        {0.17778, 0.06667, -0.26667, 0.33333}
    }};
    EXPECT_EQ(matrix::inverse(A), expected);
}

TEST(MatrixTest, MultProductByItsInverse) {
    matrix::Mat4 A{{
        {3, -9, 7, 3},
        {3, -8, 2, -9},
        {-4, 4, 4, 1},
        {-6, 5, -1, 1}
    }};
    matrix::Mat4 B{{
        {8, 2, 2, 2},
        {3, -1, 7, 0},
        {7, 0, 5, 4},
        {6, -2, 0, 5}
    }};
    matrix::Mat4 C = A * B;
    EXPECT_EQ(C * matrix::inverse(B), A);
}
