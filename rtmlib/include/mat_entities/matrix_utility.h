#ifndef MATRIX_UTILITY_H    
#define MATRIX_UTILITY_H

#include "matrix.h"

namespace rtm
{
bool compare(Matrix, Matrix);
float determinant(Matrix M);
Matrix inverse(Matrix M);

// Stuff for computing the inverse of a matrix

Matrix submatrix(Matrix M, int row, int col);
float minor(Matrix M, int row, int col);
float cofactor(Matrix M, int row, int col);

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