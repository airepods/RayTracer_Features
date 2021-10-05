#ifndef MATRIX_H    
#define MATRIX_H

class Matrix
{
    private:
        int _row, _column;
        float** matrix = nullptr;
    public:

        // Exception class
        class out_of_index
        {
        };

        class no_allocation_detected
        {
        };

        class size_not_equal
        {
        };

        class zero_determinant_error
        {
        };

        Matrix();
        Matrix(int row, int column);
        ~Matrix();

        inline int get_nrow() { return _row; }
        int get_ncolumn() { return _column; }

        float at(int row, int column) const;
        void set_matrix(int nrow, int ncolumn, float* mat);
        void set_identity();
        void set_value(int row, int column, float val);
        Matrix transpose();

        Matrix operator*(Matrix m);

};

bool compare(Matrix, Matrix);

float determinant(Matrix M);
Matrix inverse(Matrix M);

template<class T>
T operator*(Matrix m, T tuple)
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



#endif