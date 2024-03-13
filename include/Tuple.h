#ifndef TUPLE_H
#define TUPLE_H

namespace tuple {

class Tuple {
public:
    double e[4];
    Tuple(double e0, double e1, double e2, double e3) : e{e0, e1, e2, e3} { }
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }
    double w() const { return e[3]; }
    double r() const { return e[0]; }
    double g() const { return e[1]; }
    double b() const { return e[2]; }
};

Tuple point(double x, double y, double z);
Tuple vector(double x, double y, double z);
Tuple color(double r, double g, double b);
Tuple operator+(const Tuple& lhs, const Tuple& rhs);
Tuple operator-(const Tuple& lhs, const Tuple& rhs);
Tuple operator-(const Tuple& t);
Tuple operator*(const Tuple& lhs, const Tuple& rhs);
Tuple operator*(const Tuple& lhs, const double scalar);
Tuple operator*(const double scalar, const Tuple& rhs);
Tuple operator/(const Tuple& lhs, const double scalar);
const bool operator==(const Tuple& lhs, const Tuple& rhs);
const double magnitude(const Tuple& vec);
Tuple normalize(const Tuple& vec);
const double dot(const Tuple& a, const Tuple& b);
Tuple cross(const Tuple& a, const Tuple& b);

}

#endif
