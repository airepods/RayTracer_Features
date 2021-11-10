#include "mat_entities/matrix.h"
#include "util/utils.h"
#include <iostream>

using namespace rtm;

// Default constructor
Matrix::Matrix() : matrix(nullptr)
{}

// Custom consturctor
Matrix::Matrix(int row, int column) : _row(row), _column(column)
{
    matrix = new float*[_row];

    for(int i=0; i<_row; ++i)
    {
        matrix[i] = new float[_column];
    }

    for(int i=0; i<_row; ++i)
    {
        for(int j=0; j<_column; ++j)
        {
            matrix[i][j] = 0.0f;
        }
    }
}

// Construct a Matrix providing a built-in array of arrays (built-in matrix) and
// the number of rows and columns 
Matrix::Matrix(int row, int column, float* mat) : _row(row), _column(column)
{
    matrix = new float*[_row];

    for(int i=0; i<_row; ++i)
    {
        matrix[i] = new float[_column];
    }

    for(int i=0; i<_row; ++i)
    {
        for(int j=0; j<_column; ++j)
        {
            matrix[i][j] = 0.0f;
        }
    }

    int i, j;
    for(i=0; i<_row; i++)
    {
        for(j=0; j<_column; j++)
        {
            matrix[i][j] = *(mat + i*_column + j);
        }
    }

}

// Destructor
Matrix::~Matrix()
{
    if(matrix != nullptr)
    {
        for(int i=0; i<_row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        //std::cout<<"delete matrix"<<std::endl;
    } 
}

// Copy constructor
Matrix::Matrix(const Matrix& m)
{
    _row = m._row;
    _column = m._column;

    matrix = new float*[_row];

    for(int i=0; i<_row; ++i)
    {
        matrix[i] = new float[_column];
    }

    for(int i=0; i<_row; ++i)
    {
        for(int j=0; j<_column; ++j)
        {
            matrix[i][j] = m.matrix[i][j];
        }
    }
}

// Copy assignment operator
Matrix& Matrix::operator= (const Matrix& m)
{
    _row = m._row;
    _column = m._column;

    matrix = new float*[_row];

    for(int i=0; i<_row; ++i)
    {
        matrix[i] = new float[_column];
    }

    for(int i=0; i<_row; ++i)
    {
        for(int j=0; j<_column; ++j)
        {
            matrix[i][j] = m.matrix[i][j];
        }
    }

    return *this;
}

// Get an element of a matrix given its row and column indexes
float Matrix::at(int row, int column) const
{
    if(row > _row-1 || column > _column-1)
        throw Matrix::out_of_index();
    
    return matrix[row][column];
}

// void Matrix::set_matrix(int nrow, int ncolumn, float* mat)
// {
//     int i, j;
//     for(i=0; i<nrow; i++)
//     {
//         for(j=0; j<ncolumn; j++)
//         {
//             matrix[i][j] = *(mat + i*ncolumn + j);
//         }
//     }
// }

// Create the identity matrix
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

// Set the values of the elements of the matrix given an specific index i(row), j(column) 
void Matrix::set_value(int row, int column, float val)
{
    if(row > _row-1 || column > _column-1)
        throw Matrix::out_of_index();

    matrix[row][column] = val;
}

// Matrix multiplication
Matrix Matrix::operator*(const Matrix& m)
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

// Return the transpose of a matrix
Matrix Matrix::transpose()
{
    Matrix tmatrix(_column, _row);

    for(int row=0; row<_column; ++row)
    {
        for(int col=0; col<_row; ++col)
        {
            tmatrix.set_value(row, col, matrix[col][row]);
        }
    }
    
    return tmatrix;
}

