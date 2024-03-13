#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <initializer_list>
#include <string>
#include <Tuple.h>

namespace matrix {

template <unsigned s>
class Mat {
    std::array<double, 16> data;
    static const std::string ctor_exception_msg;
public:
    Mat(std::initializer_list<std::initializer_list<double>> grid);
    Mat() : data{0} { }
    double at(const unsigned i, const unsigned j) const { return data[j + s*i]; }
    void set(unsigned i, unsigned j, double v) { data[j + s*i] = v; }
    Mat<s-1> submatrix(const unsigned i, const unsigned j) const;
    double minor(unsigned i, unsigned j) const;
    double cofactor(unsigned i, unsigned j) const;
    tuple::Tuple row(const unsigned i) const;
    tuple::Tuple col(const unsigned j) const;
};

using Mat4 = Mat<4>;
using Mat3 = Mat<3>;
using Mat2 = Mat<2>;

template <unsigned s>
bool operator==(const Mat<s>& a, const Mat<s>& b);

template <unsigned s>
bool operator!=(const Mat<s>& a, const Mat<s>& b);

Mat4 operator*(const Mat4& lhs, const Mat4& rhs);

tuple::Tuple operator*(const Mat4& lhs, const tuple::Tuple& rhs);

Mat4 identity();

template <unsigned s>
Mat<s> transpose(const Mat<s>& m);

template <unsigned s>
double determinant(const Mat<s>& m);

template <>
double determinant(const Mat2& m);

bool is_invertible(const Mat4& m);

Mat4 inverse(const Mat4& m);

}

#include "../src/Matrix.cpp"

#endif
