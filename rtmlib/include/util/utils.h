#ifndef UTILS_H    
#define UTILS_H

#include "mat_entities/matrix.h"
#include <string>
#include <cmath>

bool fcompare(float, float);
std::string ftos(float f, int nd);
Matrix submatrix(Matrix M, int row, int col);
float minor(Matrix M, int row, int col);
float cofactor(Matrix M, int row, int col);
float to_radians(float degrees);
void* empty_array();

#endif