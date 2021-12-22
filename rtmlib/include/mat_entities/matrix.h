#ifndef MATRIX_H    
#define MATRIX_H

namespace rtm
{
class Matrix
{
    private:
        int m_row, m_column;
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
        Matrix(const int& row, const int& column);
        Matrix(const int& row, const int& column, float* mat);
        ~Matrix();

        Matrix(const Matrix&);
        Matrix& operator= (const Matrix&);

        inline int get_nrow() const { return m_row; }
        inline int get_ncolumn() const { return m_column; }

        float at(const int& row, const int& column) const;
        //void set_matrix(int nrow, int ncolumn, float* mat);
        void set_identity();
        void set_value(const int& row, const int& column, const float& val);
        Matrix transpose() const;

        Matrix operator *(const Matrix& m) const;

};
} //namespace rtm

#endif