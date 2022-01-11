#include "mat_entities/matrix.h"
#include "util/utils.h"
#include <iostream>

using namespace rtm;

// Default constructor
Matrix::Matrix() : matrix(nullptr)
{}

// Custom consturctor
Matrix::Matrix(const int& row, const int& column) : m_row(row), m_column(column)
{
    matrix = new double*[m_row];

    for(int i=0; i<m_row; ++i)
    {
        matrix[i] = new double[m_column];
    }

    for(int i=0; i<m_row; ++i)
    {
        for(int j=0; j<m_column; ++j)
        {
            matrix[i][j] = 0.0f;
        }
    }
}

// Construct a Matrix providing a built-in array of arrays (built-in matrix) and
// the number of rows and columns 
Matrix::Matrix(const int& row, const int& column, double* mat) : m_row(row), m_column(column)
{
    matrix = new double*[m_row];

    for(int i=0; i<m_row; ++i)
    {
        matrix[i] = new double[m_column];
    }

    for(int i=0; i<m_row; ++i)
    {
        for(int j=0; j<m_column; ++j)
        {
            matrix[i][j] = 0.0f;
        }
    }

    int i, j;
    for(i=0; i<m_row; i++)
    {
        for(j=0; j<m_column; j++)
        {
            matrix[i][j] = *(mat + i*m_column + j);
        }
    }

}

// Destructor
Matrix::~Matrix()
{
    if(matrix != nullptr)
    {
        for(int i=0; i<m_row; ++i)
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
    m_row = m.m_row;
    m_column = m.m_column;

    matrix = new double*[m_row];

    for(int i=0; i<m_row; ++i)
    {
        matrix[i] = new double[m_column];
    }

    for(int i=0; i<m_row; ++i)
    {
        for(int j=0; j<m_column; ++j)
        {
            matrix[i][j] = m.matrix[i][j];
        }
    }
}

// Copy assignment operator
Matrix& Matrix::operator= (const Matrix& m)
{
    m_row = m.m_row;
    m_column = m.m_column;

    matrix = new double*[m_row];

    for(int i=0; i<m_row; ++i)
    {
        matrix[i] = new double[m_column];
    }

    for(int i=0; i<m_row; ++i)
    {
        for(int j=0; j<m_column; ++j)
        {
            matrix[i][j] = m.matrix[i][j];
        }
    }

    return *this;
}

// Get an element of a matrix given its row and column indexes
double Matrix::at(const int& row, const int& column) const
{
    if(row > m_row-1 || column > m_column-1)
        throw Matrix::out_of_index();
    
    return matrix[row][column];
}

// void Matrix::set_matrix(int nrow, int ncolumn, double* mat)
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
void Matrix::set_value(const int& row, const int& column, const double& val)
{
    if(row > m_row-1 || column > m_column-1)
        throw Matrix::out_of_index();

    matrix[row][column] = val;
}

// Matrix multiplication
Matrix Matrix::operator*(const Matrix& m) const
{
    Matrix result = Matrix(4, 4);

    for(int row=0; row<4; ++row)
    {
        for(int col=0; col<4; ++col)
        {
            double val = this->at(row, 0) * m.at(0, col) +
                        this->at(row, 1) * m.at(1, col) +
                        this->at(row, 2) * m.at(2, col) +
                        this->at(row, 3) * m.at(3, col);

            result.set_value(row, col, val);
        }
    }

    return result;
}

// Return the transpose of a matrix
Matrix Matrix::transpose() const
{
    Matrix tmatrix(m_column, m_row);

    for(int row=0; row<m_column; ++row)
    {
        for(int col=0; col<m_row; ++col)
        {
            tmatrix.set_value(row, col, matrix[col][row]);
        }
    }
    
    return tmatrix;
}

