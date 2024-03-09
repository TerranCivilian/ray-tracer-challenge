#include <cmath>
#include <gtest/gtest.h>
#include "Tuple.h"

TEST(TupleTest, Point) {
    tuple::Tuple a{4.3, -4.2, 3.1, 1.0};
    EXPECT_NEAR(a.x(), 4.3, tuple::err);
    EXPECT_NEAR(a.y(), -4.2, tuple::err);
    EXPECT_NEAR(a.z(), 3.1, tuple::err);
    EXPECT_NEAR(a.w(), 1.0, tuple::err);
}

TEST(TupleTest, Vector) {
    tuple::Tuple a{4.3, -4.2, 3.1, 0.0};
    EXPECT_NEAR(a.x(), 4.3, tuple::err);
    EXPECT_NEAR(a.y(), -4.2, tuple::err);
    EXPECT_NEAR(a.z(), 3.1, tuple::err);
    EXPECT_NEAR(a.w(), 0.0, tuple::err);
}

TEST(TupleTest, PointFactory) {
    tuple::Tuple p = tuple::point(4, -4, 3);
    tuple::Tuple expected{4, -4, 3, 1.0};
    EXPECT_EQ(p, expected);
}

TEST(TupleTest, VectorFactory) {
    tuple::Tuple v = tuple::vector(4, -4, 3);
    tuple::Tuple expected{4, -4, 3, 0.0};
    EXPECT_EQ(v, expected);
}

TEST(TupleTest, Addition) {
    tuple::Tuple a1{3, -2, 5, 1};
    tuple::Tuple a2{-2, 3, 1, 0};
    tuple::Tuple expected{1, 1, 6, 1};
    EXPECT_EQ(a1 + a2, expected);
}

TEST(TupleTest, SubtractTwoPoints) {
    tuple::Tuple p1 = tuple::point(3, 2, 1);
    tuple::Tuple p2 = tuple::point(5, 6, 7);
    tuple::Tuple expected = tuple::vector(-2, -4, -6);
    EXPECT_EQ(p1 - p2, expected);
}

TEST(TupleTest, SubtractVectorFromPoint) {
    tuple::Tuple p1 = tuple::point(3, 2, 1);
    tuple::Tuple p2 = tuple::vector(5, 6, 7);
    tuple::Tuple expected = tuple::point(-2, -4, -6);
    EXPECT_EQ(p1 - p2, expected);
}

TEST(TupleTest, SubtractTwoVectors) {
    tuple::Tuple p1 = tuple::vector(3, 2, 1);
    tuple::Tuple p2 = tuple::vector(5, 6, 7);
    tuple::Tuple expected = tuple::vector(-2, -4, -6);
    EXPECT_EQ(p1 - p2, expected);
}

TEST(TupleTest, SubtractVectorFromZeroVector) {
    tuple::Tuple zero = tuple::vector(0, 0, 0);
    tuple::Tuple v = tuple::vector(1, -2, 3);
    tuple::Tuple expected = tuple::vector(-1, 2, -3);
    EXPECT_EQ(zero - v, expected);
}

TEST(TupleTest, Negation) {
    tuple::Tuple a{1, -2, 3, -4};
    tuple::Tuple expected{-1, 2, -3, 4};
    EXPECT_EQ(-a, expected);
}

TEST(TupleTest, MultiplyByScalar) {
    tuple::Tuple a{1, -2, 3, -4};
    tuple::Tuple expected{3.5, -7, 10.5, -14};
    EXPECT_EQ(a * 3.5, expected);
}


TEST(TupleTest, MultiplyByFraction) {
    tuple::Tuple a{1, -2, 3, -4};
    tuple::Tuple expected{0.5, -1, 1.5, -2};
    EXPECT_EQ(a * 0.5, expected);
}

TEST(TupleTest, MultiplyByScalarRevOperands) {
    tuple::Tuple a{1, -2, 3, -4};
    tuple::Tuple expected{3.5, -7, 10.5, -14};
    EXPECT_EQ(3.5 * a, expected);
}

TEST(TupleTest, DivideByScalar) {
    tuple::Tuple a{1, -2, 3, -4};
    tuple::Tuple expected{0.5, -1, 1.5, -2};
    EXPECT_EQ(a / 2, expected);
}

TEST(TupleTest, Magnitude1) {
    tuple::Tuple v = tuple::vector(1, 0, 0);
    double expected = 1;
    EXPECT_NEAR(tuple::magnitude(v), expected, tuple::err);
}

TEST(TupleTest, Magnitude2) {
    tuple::Tuple v = tuple::vector(0, 1, 0);
    double expected = 1;
    EXPECT_NEAR(tuple::magnitude(v), expected, tuple::err);
}

TEST(TupleTest, Magnitude3) {
    tuple::Tuple v = tuple::vector(0, 0, 1);
    double expected = 1;
    EXPECT_NEAR(tuple::magnitude(v), expected, tuple::err);
}

TEST(TupleTest, Magnitude4) {
    tuple::Tuple v = tuple::vector(1, 2, 3);
    double expected = std::sqrt(14);
    EXPECT_NEAR(tuple::magnitude(v), expected, tuple::err);
}

TEST(TupleTest, Magnitude5) {
    tuple::Tuple v = tuple::vector(-1, -2, -3);
    double expected = std::sqrt(14);
    EXPECT_NEAR(tuple::magnitude(v), expected, tuple::err);
}

TEST(TupleTest, Normalize1) {
    tuple::Tuple v = tuple::vector(4, 0, 0);
    tuple::Tuple expected = tuple::vector(1, 0, 0);
    EXPECT_EQ(tuple::normalize(v), expected);
}

TEST(TupleTest, Normalize2) {
    tuple::Tuple v = tuple::vector(1, 2, 3);
    tuple::Tuple expected = tuple::vector(1/std::sqrt(14), 2/std::sqrt(14), 3/std::sqrt(14));
    EXPECT_EQ(tuple::normalize(v), expected);
}

TEST(TupleTest, MagnitudeOfNormalizedVector) {
    tuple::Tuple norm = tuple::normalize(tuple::vector(1, 2, 3));
    double expected = 1;
    EXPECT_NEAR(tuple::magnitude(norm), expected, tuple::err);
}
