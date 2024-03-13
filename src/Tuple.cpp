#include <cmath>
#include <cstdio>
#include <Tuple.h>
#include <Util.h>

namespace tuple {

Tuple point(double x, double y, double z) {
    return Tuple{x, y, z, 1.0};
}

Tuple vector(double x, double y, double z) {
    return Tuple{x, y, z, 0.0};
}

Tuple color(double r, double g, double b) {
    return Tuple{r, g, b, 0.0};
}

Tuple operator+(const Tuple& lhs, const Tuple& rhs) {
    return Tuple{
        lhs.e[0] + rhs.e[0],
        lhs.e[1] + rhs.e[1],
        lhs.e[2] + rhs.e[2],
        lhs.e[3] + rhs.e[3]
    };
}

Tuple operator-(const Tuple& lhs, const Tuple& rhs) {
    return Tuple{
        lhs.e[0] - rhs.e[0],
        lhs.e[1] - rhs.e[1],
        lhs.e[2] - rhs.e[2],
        lhs.e[3] - rhs.e[3]
    };
}

Tuple operator*(const Tuple& lhs, const double scalar) {
    return Tuple{
        lhs.e[0] * scalar,
        lhs.e[1] * scalar,
        lhs.e[2] * scalar,
        lhs.e[3] * scalar
    };
}

Tuple operator*(const Tuple& lhs, const Tuple& rhs) {
    return color(
        lhs.e[0] * rhs.e[0],
        lhs.e[1] * rhs.e[1],
        lhs.e[2] * rhs.e[2]
    );
}

Tuple operator*(const double scalar, const Tuple& rhs) {
    return Tuple{
        rhs.e[0] * scalar,
        rhs.e[1] * scalar,
        rhs.e[2] * scalar,
        rhs.e[3] * scalar
    };
}

Tuple operator/(const Tuple& lhs, const double scalar) {
    return Tuple{
        lhs.e[0] / scalar,
        lhs.e[1] / scalar,
        lhs.e[2] / scalar,
        lhs.e[3] / scalar
    };
}

Tuple operator-(const Tuple& t) {
    return Tuple{-t.e[0], -t.e[1], -t.e[2], -t.e[3]};
}

const bool operator==(const Tuple& lhs, const Tuple& rhs) {
    return util::d_eq(lhs.e[0], rhs.e[0]) &&
        util::d_eq(lhs.e[1], rhs.e[1]) &&
        util::d_eq(lhs.e[2], rhs.e[2]) &&
        util::d_eq(lhs.e[3], rhs.e[3]);
}

const double magnitude(const Tuple& vec) {
    return sqrt(
        vec.e[0]*vec.e[0] +
        vec.e[1]*vec.e[1] +
        vec.e[2]*vec.e[2] +
        vec.e[3]*vec.e[3]
    );
}

Tuple normalize(const Tuple& vec) {
    double mag = magnitude(vec);
    return Tuple{
        vec.e[0] / mag,
        vec.e[1] / mag,
        vec.e[2] / mag,
        vec.e[3] / mag
    };
}

const double dot(const Tuple& a, const Tuple& b) {
    return a.e[0] * b.e[0] +
        a.e[1] * b.e[1] +
        a.e[2] * b.e[2] +
        a.e[3] * b.e[3];
}

Tuple cross(const Tuple& a, const Tuple& b) {
    return vector(
        a.e[1] * b.e[2] - a.e[2] * b.e[1],
        a.e[2] * b.e[0] - a.e[0] * b.e[2],
        a.e[0] * b.e[1] - a.e[1] * b.e[0]
    );
}

}
