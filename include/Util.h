#ifndef UTIL_H
#define UTIL_H

#include <cmath>

namespace util {

const double err = 0.00001;
inline bool d_eq(const double a, const double b) { return abs(a - b) < err; }

}

#endif
