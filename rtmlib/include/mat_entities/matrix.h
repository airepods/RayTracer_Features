#ifndef MATRIX_H    
#define MATRIX_H

namespace rtm
{
class Matrix
{
    private:
        int _row, _column;
        float** matrix;
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

        inline int get_nrow() const { return _row; }
        inline int get_ncolumn() const { return _column; }

        float at(int row, int column) const;
        void set_matrix(int nrow, int ncolumn, float* mat);
        void set_identity();
        void set_value(int row, int column, float val);
        Matrix transpose();

        Matrix operator *(const Matrix& m);

};
} //namespace rtm

#endif