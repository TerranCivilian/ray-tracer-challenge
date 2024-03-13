#include <gtest/gtest.h>
#include <Tuple.h>
#include <Util.h>

TEST(ColorTest, Color) {
    tuple::Tuple c = tuple::color(-0.5, 0.4, 1.7);
    EXPECT_NEAR(c.r(), -0.5, util::err);
    EXPECT_NEAR(c.g(), 0.4, util::err);
    EXPECT_NEAR(c.b(), 1.7, util::err);
}

TEST(ColorTest, Addition) {
    tuple::Tuple c1 = tuple::color(0.9, 0.6, 0.75);
    tuple::Tuple c2 = tuple::color(0.7, 0.1, 0.25);
    tuple::Tuple expected = tuple::color(1.6, 0.7, 1.0);
    EXPECT_EQ(c1 + c2, expected);
}

TEST(ColorTest, Subtraction) {
    tuple::Tuple c1 = tuple::color(0.9, 0.6, 0.75);
    tuple::Tuple c2 = tuple::color(0.7, 0.1, 0.25);
    tuple::Tuple expected = tuple::color(0.2, 0.5, 0.5);
    EXPECT_EQ(c1 - c2, expected);
}

TEST(ColorTest, MultiplyByScalar) {
    tuple::Tuple c = tuple::color(0.2, 0.3, 0.4);
    tuple::Tuple expected = tuple::color(0.4, 0.6, 0.8);
    EXPECT_EQ(c * 2, expected);
}

TEST(ColorTest, MultiplyColors) {
    tuple::Tuple c1 = tuple::color(1, 0.2, 0.4);
    tuple::Tuple c2 = tuple::color(0.9, 1, 0.1);
    tuple::Tuple expected = tuple::color(0.9, 0.2, 0.04);
    EXPECT_EQ(c1 * c2, expected);
}
