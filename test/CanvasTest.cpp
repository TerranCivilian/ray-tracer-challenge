#include <gtest/gtest.h>
#include <Canvas.h>

TEST(CanvasTest, Canvas) {
    canvas::Canvas c(10, 20);
    EXPECT_EQ(c.width(), 10);
    EXPECT_EQ(c.height(), 20);
    for (unsigned y = 0; y < c.height(); ++y)
        for (unsigned x = 0; x < c.width(); ++x)
            EXPECT_EQ(c.at(x, y), tuple::color(0, 0, 0));
}

TEST(CanvasTest, Write) {
    canvas::Canvas c(10, 20);
    tuple::Tuple red = tuple::color(1, 0, 0);
    c.write(2, 3, red);
    EXPECT_EQ(c.at(2, 3), red);
}

TEST(CanvasTest, ToPpmHeader) {
    canvas::Canvas c(5, 3);
    std::string ppm = canvas::to_ppm(c);
    std::string expected{"P3\n5 3\n255\n"};
    EXPECT_EQ(ppm.substr(0, expected.size()), expected);
}

TEST(CanvasTest, ToPpmData) {
    canvas::Canvas c(5, 3);
    tuple::Tuple c1 = tuple::color(1.5, 0, 0);
    tuple::Tuple c2 = tuple::color(0, 0.5, 0);
    tuple::Tuple c3 = tuple::color(-0.5, 0, 1);
    c.write(0, 0, c1);
    c.write(2, 1, c2);
    c.write(4, 2, c3);
    std::string ppm = canvas::to_ppm(c);
    std::string expected{
        "P3\n5 3\n255\n255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
        "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n"
        "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n"
    };
    EXPECT_EQ(ppm, expected);
}

TEST(CanvasTest, ToPpmDataLongLines) {
    canvas::Canvas c(10, 2);
    for (unsigned y = 0; y < c.height(); ++y) {
        for (unsigned x = 0; x < c.width(); ++x) {
            c.write(x, y, tuple::color(1, 0.8, 0.6));
        }
    }
    std::string ppm = canvas::to_ppm(c);
    std::string expected{
        "P3\n10 2\n255\n"
        "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n"
        "153 255 204 153 255 204 153 255 204 153 255 204 153\n"
        "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n"
        "153 255 204 153 255 204 153 255 204 153 255 204 153\n"
    };
    EXPECT_EQ(ppm, expected);
}

TEST(CanvasTest, PpmEndsWithNewline) {
    canvas::Canvas c(5, 3);
    std::string ppm = canvas::to_ppm(c);
    EXPECT_EQ(ppm.back(), '\n');
}
