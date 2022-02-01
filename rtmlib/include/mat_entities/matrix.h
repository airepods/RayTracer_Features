#ifndef MATRIX_H    
#define MATRIX_H

namespace rtm
{
class Matrix
{
    private:
        int m_row, m_column;
        double** matrix;
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
        Matrix(const int& row, const int& column, double* mat);
        ~Matrix();

        Matrix(const Matrix&);
        Matrix& operator= (const Matrix&);

        inline int get_nrow() const { return m_row; }
        inline int get_ncolumn() const { return m_column; }

        double at(const int& row, const int& column) const;
        //void set_matrix(int nrow, int ncolumn, double* mat);
        void set_identity();
        void set_value(const int& row, const int& column, const double& val);
        Matrix transpose() const;

        Matrix operator *(const Matrix& m) const;

        //check if matrix is null
        inline bool is_empty() const {return matrix == nullptr ? true : false;}

};
} //namespace rtm

#endif