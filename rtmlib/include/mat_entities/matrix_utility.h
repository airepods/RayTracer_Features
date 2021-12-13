#ifndef MATRIX_UTILITY_H    
#define MATRIX_UTILITY_H

#include "matrix.h"

namespace rtm
{
bool compare(const Matrix&, const Matrix&);
float determinant(const Matrix& M);
Matrix inverse(const Matrix& M);

// Stuff for computing the inverse of a matrix
Matrix submatrix(const Matrix& M, int row, int col);
float minor(const Matrix& M, int row, int col);
float cofactor(const Matrix& M, int row, int col);



// Matrix - Tuple multiplication
template<class T>
T operator*(const Matrix& m, const T& tuple)
{
    float results[4];

    for(int row=0; row<4; ++row)
    {
        results[row] = m.at(row, 0) * tuple.x() +
                       m.at(row, 1) * tuple.y() +
                       m.at(row, 2) * tuple.z() +
                       m.at(row, 3) * tuple.w();
    }
    return T(results);
}
}

#endif