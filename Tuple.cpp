#include <cmath>
#include <cstdio>
#include "Tuple.h"

namespace tuple {

Tuple point(double x, double y, double z) {
    return Tuple{x, y, z, 1.0};
}

Tuple vector(double x, double y, double z) {
    return Tuple{x, y, z, 0.0};
}

const Tuple operator+(const Tuple& lhs, const Tuple& rhs) {
    return Tuple{lhs.e[0] + rhs.e[0], lhs.e[1] + rhs.e[1], lhs.e[2] + rhs.e[2], lhs.e[3] + rhs.e[3]};
}

const Tuple operator-(const Tuple& lhs, const Tuple& rhs) {
    return Tuple{lhs.e[0] - rhs.e[0], lhs.e[1] - rhs.e[1], lhs.e[2] - rhs.e[2], lhs.e[3] - rhs.e[3]};
}

const Tuple& Tuple::operator*(const double scalar) {
    e[0] *= scalar;
    e[1] *= scalar;
    e[2] *= scalar;
    e[3] *= scalar;
    return *this;
}

const Tuple operator*(const double scalar, const Tuple& rhs) {
    return Tuple{rhs.e[0] * scalar, rhs.e[1] * scalar, rhs.e[2] * scalar, rhs.e[3] * scalar};
}

const Tuple& Tuple::operator/(const double scalar) {
    e[0] /= scalar;
    e[1] /= scalar;
    e[2] /= scalar;
    e[3] /= scalar;
    return *this;
}

const Tuple& Tuple::operator-() {
    e[0] = -e[0];
    e[1] = -e[1];
    e[2] = -e[2];
    e[3] = -e[3];
    return *this;
}

const bool operator==(const Tuple& lhs, const Tuple& rhs) {
    return (std::abs(lhs.e[0] - rhs.e[0]) < err) &&
        (std::abs(lhs.e[1] - rhs.e[1]) < err) &&
        (std::abs(lhs.e[2] - rhs.e[2]) < err) &&
        (std::abs(lhs.e[3] - rhs.e[3]) < err);
}

const double magnitude(const Tuple& vec) {
    return std::sqrt(std::pow(vec.e[0], 2) + std::pow(vec.e[1], 2) + std::pow(vec.e[2], 2) + std::pow(vec.e[3], 2));
}

const Tuple normalize(const Tuple& vec) {
    double mag = magnitude(vec);
    return Tuple{vec.e[0] / mag, vec.e[1] / mag, vec.e[2] / mag, vec.e[3] / mag};
}

}
