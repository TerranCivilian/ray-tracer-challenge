#include <algorithm>
#include <stdexcept>
#include <Matrix.h>
#include <Util.h>

namespace matrix {

template <unsigned s>
const std::string Mat<s>::ctor_exception_msg = "Mat<s>(initializer_list<initializer_list<double>> grid): argument 'grid' must be MxM matrix where M is in range [2, 4]";

template <unsigned s>
Mat<s>::Mat(std::initializer_list<std::initializer_list<double>> grid) {
    if (grid.size() != s) throw std::invalid_argument(ctor_exception_msg);
    if (grid.size() > 4 || grid.size() < 2) throw std::invalid_argument(ctor_exception_msg);
    for (int i = 0; i < s; ++i) {
        auto list = *(grid.begin()+i);
        if (list.size() != s) throw std::invalid_argument(ctor_exception_msg);
        if (list.size() > 4 || list.size() < 2) throw std::invalid_argument(ctor_exception_msg);
        if (list.size() != grid.size()) throw std::invalid_argument(ctor_exception_msg);
        std::copy(list.begin(), list.end(), data.begin()+i*s);
    }
}

template <unsigned s>
bool operator==(const Mat<s>& a, const Mat<s>& b) {
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            if (!util::d_eq(a.at(i,j), b.at(i,j))) return false;
        }
    }
    return true;
}

template <unsigned s>
bool operator!=(const Mat<s>& a, const Mat<s>& b) {
    return !(a == b);
}

template <>
tuple::Tuple Mat4::row(const unsigned i) const {
    return tuple::Tuple{
        at(i,0),
        at(i,1),
        at(i,2),
        at(i,3)
    };
}

template <>
tuple::Tuple Mat4::col(const unsigned j) const {
    return tuple::Tuple{
        at(0,j),
        at(1,j),
        at(2,j),
        at(3,j)
    };
}

template <unsigned s>
tuple::Tuple Mat<s>::row(const unsigned i) const = delete;

template <unsigned s>
tuple::Tuple Mat<s>::col(const unsigned i) const = delete;

Mat4 operator*(const Mat4& lhs, const Mat4& rhs) {
    Mat4 ret;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            tuple::Tuple r = lhs.row(i);
            tuple::Tuple c = rhs.col(j);
            ret.set(i, j, tuple::dot(r, c));
        }
    }
    return ret;
}

tuple::Tuple operator*(const Mat4& lhs, const tuple::Tuple& rhs) {
    return tuple::Tuple{
        tuple::dot(lhs.row(0), rhs),
        tuple::dot(lhs.row(1), rhs),
        tuple::dot(lhs.row(2), rhs),
        tuple::dot(lhs.row(3), rhs),
    };
}

Mat4 identity() {
    return Mat4{{
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    }};
}

template <unsigned s>
Mat<s> transpose(const Mat<s>& m) {
    Mat<s> ret;
    for (int i = 0; i < s; ++i)
        for (int j = 0; j < s; ++j)
            ret.set(i, j, m.at(j, i));
    return ret;
}

template <unsigned s>
double determinant(const Mat<s>& m) {
    double ret = 0;
    for (unsigned j = 0; j < s; ++j) {
        ret += m.at(0, j) * m.cofactor(0, j);
    }
    return ret;
}

template<>
double determinant(const Mat2& m) {
    return m.at(0,0)*m.at(1,1) - m.at(0,1)*m.at(1,0);
}

template <unsigned s>
Mat<s-1> Mat<s>::submatrix(const unsigned i, const unsigned j) const {
    Mat<s-1> ret;
    for (unsigned ii = 0, new_i = 0; ii < s; ++ii) {
        for (unsigned jj = 0, new_j = 0; jj < s; ++jj) {
            if (jj != j && ii != i) {
                ret.set(new_i, new_j, at(ii, jj));
                ++new_j;
            }
        }
        if (ii != i) ++new_i;
    }
    return ret;
}

template <>
Mat<1> Mat<2>::submatrix(const unsigned i, const unsigned j) const = delete;

template <unsigned s>
double Mat<s>::minor(unsigned i, unsigned j) const {
    return determinant<s-1>(submatrix(i, j));
}

template <>
double Mat<2>::minor(const unsigned i, const unsigned j) const = delete;

template <unsigned s>
double Mat<s>::cofactor(unsigned i, unsigned j) const {
    double ret = minor(i, j);
    unsigned sum = i + j;
    return ((sum % 2) == 0) ? ret : -ret;
}

template <>
double Mat<2>::cofactor(unsigned i, unsigned j) const = delete;

bool is_invertible(const Mat4& m) {
    return determinant(m) != 0;
}

Mat4 inverse(const Mat4& m) {
    if (!is_invertible(m)) return Mat4{};

    double d = determinant(m);
    Mat4 ret;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            double c = m.cofactor(i, j);
            ret.set(j, i, c / d);
        }
    }
    return ret;
}

}