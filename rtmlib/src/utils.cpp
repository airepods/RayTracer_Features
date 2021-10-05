#define _USE_MATH_DEFINES

#include "util/utils.h"
#include "mat_entities/matrix.h"
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Compare two floating point numbers
bool fcompare(float a, float b)
{
    const float EPSILON = 0.00001;

    if(abs(a - b) < EPSILON)
        return true;
    else
        return false;
}

// Convert float to string with fixed decimal places
string ftos(float f, int nd)
{
   ostringstream ostr;
   int tens = stoi("1" + string(nd, '0'));
   ostr << round(f*tens)/tens;
   return ostr.str();
}

// Compute the submatrix of a given matrix
Matrix submatrix(Matrix M, int row, int col)
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
float minor(Matrix M, int row, int col)
{
    return determinant(submatrix(M, row, col));
}

// Compute the submatrix of a matrix given its row and colomun indices
float cofactor(Matrix M, int row, int col)
{
    if((row+col)%2 != 0)
        return -minor(M, row, col);
    else
        return minor(M, row, col);
}

// Convert an angle from degrees to radians
float to_radians(float degrees)
{
    return (degrees/180)*M_PI;
}

// Return null pointer
void* empty_array()
{
    return nullptr;
}