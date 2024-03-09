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

    const Tuple& operator-();
    const Tuple& operator*(const double scalar);
    const Tuple& operator/(const double scalar);
};

Tuple point(double x, double y, double z);
Tuple vector(double x, double y, double z);
const Tuple operator+(const Tuple& lhs, const Tuple& rhs);
const Tuple operator-(const Tuple& lhs, const Tuple& rhs);
const Tuple operator*(const double scalar, const Tuple& rhs);
const bool operator==(const Tuple& lhs, const Tuple& rhs);
const double magnitude(const Tuple& vec);
const Tuple normalize(const Tuple& vec);

const double err = 0.00001;

}

#endif
