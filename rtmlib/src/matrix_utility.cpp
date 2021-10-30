#include "mat_entities/matrix_utility.h"
#include "util/utils.h"
#include "mat_entities/matrix.h"

using namespace rtm;

bool rtm::compare(Matrix A, Matrix B)
{
    int row = A.get_nrow();
    int col = A.get_ncolumn();

    int ntrues = 0;
    int totalTrues = row*col;

    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
        {
            if(fcompare(A.at(i,j), B.at(i,j)))
                ntrues++;
        }
    }

    if(ntrues == totalTrues)
        return true;
    else
        return false;    
}

float rtm::determinant(Matrix M)
{   
    if(M.get_nrow() != M.get_ncolumn())
         throw Matrix::size_not_equal();

    float det = 0;

    if(M.get_nrow() == 2 && M.get_ncolumn() == 2)
    {
        det = M.at(0,0)*M.at(1, 1) - M.at(0, 1)*M.at(1, 0);
        return det;
    }
    else
    {
        for(int col=0; col<M.get_ncolumn(); ++col)
        {
            det+=M.at(0, col)*cofactor(M, 0, col);
        }

        return det;
    }
}

Matrix rtm::inverse(Matrix M)
{
    if(determinant(M) == 0)
         throw Matrix::zero_determinant_error();

    const int SIZE = M.get_nrow();
    float det = determinant(M);
    
    Matrix inv = Matrix(SIZE, SIZE);

    for(int row=0; row<SIZE; ++row)
    {
        for(int col=0 ; col<SIZE; ++col)
        {
            float c = cofactor(M, row, col);
            inv.set_value(col, row, c/det);
        }
    }

    return inv;
}

// Compute the submatrix of a given matrix
Matrix rtm::submatrix(Matrix M, int row, int col)
{
    int ROW = M.get_nrow()-1;
    int COL = M.get_ncolumn()-1;

    Matrix R = Matrix(ROW, COL);

    int r = 0;
    for(int i=0; i<M.get_nrow(); ++i)
    {
        if(i == row)
            continue;

        int c = 0;
        for(int j=0; j<M.get_ncolumn(); ++j)
        {
            if(j == col)
                continue;

            R.set_value(r, c, M.at(i, j));
            c++;
        }
        r++;
    }

    return R;
}

// Compute the submatrix of a given matrix
float rtm::minor(Matrix M, int row, int col)
{
    return determinant(submatrix(M, row, col));
}

// Compute the submatrix of a matrix given its row and colomun indices
float rtm::cofactor(Matrix M, int row, int col)
{
    if((row+col)%2 != 0)
        return -minor(M, row, col);
    else
        return minor(M, row, col);
}