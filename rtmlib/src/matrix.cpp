#include "mat_entities/matrix.h"
#include "util/utils.h"

Matrix::Matrix()
{}

Matrix::Matrix(int row, int column) : _row(row), _column(column)
{
    matrix = new float*[row];

    for(int i=0; i<row; ++i)
    {
        matrix[i] = new float[column];
    }

    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<column; ++j)
        {
            matrix[i][j] = 0.0f;
        }
    }
}

Matrix::~Matrix()
{
    for(int i=0; i<_row; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

float Matrix::at(int row, int column) const
{
    if(row > _row-1 || column > _column-1)
        throw Matrix::out_of_index();
    
    return matrix[row][column];
}

void Matrix::set_matrix(int nrow, int ncolumn, float* mat)
{
    int i, j;
    for(i=0; i<nrow; i++)
    {
        for(j=0; j<ncolumn; j++)
        {
            matrix[i][j] = *(mat + i*ncolumn + j);
        }
    }
}

void Matrix::set_identity()
{   
    if(matrix == nullptr)
    {
        throw Matrix::no_allocation_detected();
    }

    this->set_value(0, 0, 1.0f);
    this->set_value(1, 1, 1.0f);
    this->set_value(2, 2, 1.0f);
    this->set_value(3, 3, 1.0f);
}

void Matrix::set_value(int row, int column, float val)
{
    if(row > _row-1 || column > _column-1)
        throw Matrix::out_of_index();

    matrix[row][column] = val;
}

Matrix Matrix::operator*(Matrix m)
{
    Matrix result = Matrix(4, 4);

    for(int row=0; row<4; ++row)
    {
        for(int col=0; col<4; ++col)
        {
            float val = this->at(row, 0) * m.at(0, col) +
                        this->at(row, 1) * m.at(1, col) +
                        this->at(row, 2) * m.at(2, col) +
                        this->at(row, 3) * m.at(3, col);

            result.set_value(row, col, val);
        }
    }

    return result;
}

Matrix Matrix::transpose()
{
    Matrix tmatrix = Matrix(_column, _row);

    for(int row=0; row<_column; ++row)
    {
        for(int col=0; col<_row; ++col)
        {
            tmatrix.set_value(row, col, matrix[col][row]);
        }
    }
    
    return tmatrix;
}

bool compare(Matrix A, Matrix B)
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

float determinant(Matrix M)
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

Matrix inverse(Matrix M)
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
