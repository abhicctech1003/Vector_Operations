#include <iostream>
#include <vector>

class Matrix 
{
    private:
        std::vector<std::vector<int>> data;
        double rows;
        double cols;

    public:
        // Constructor
        Matrix(double rows, double cols) : rows(rows), cols(cols) 
        {
            // Initialization of matrix 
            data.resize(rows, std::vector<int>(cols, 0));
        }

        // Number of rows accessor
        double numRows()  
        {
            return rows;
        }

        // Number of columns accessor
        double numCols()  
        {
            return cols;
        }

        // Element at specific row and column accessor
        int getElement(double row, double col)  
        {
            return data[row][col];
        }

        // Element at specific row and column modifier 
        void setElement(double row, double col, int value) 
        {
            data[row][col] = value;
        }

        // Overloading multiplication operator
        Matrix operator*(int scalar) const 
        {
            Matrix result(rows, cols);
            for (size_t i = 0; i < rows; ++i) 
            {
                for (size_t j = 0; j < cols; ++j) 
                {
                    result.data[i][j] = data[i][j] * scalar;
                }
            }
            return result;
        }

        // Overloading addition operator
        Matrix operator+(const Matrix& other) const 
        {
            if (rows != other.rows || cols != other.cols) 
            {
                throw std::invalid_argument("Matrices should have same dimensions");
            }
            Matrix result(rows, cols);
            for (size_t i = 0; i < rows; ++i) 
            {
                for (size_t j = 0; j < cols; ++j) 
                {
                    result.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
            return result;
        }

        // Overloading the output stream operator
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) 
        {
            for (size_t i = 0; i < matrix.rows; ++i) 
            {
                for (size_t j = 0; j < matrix.cols; ++j) 
                {
                    os << matrix.data[i][j] << " ";
                }
                os << std::endl;
            }
            return os;
     }
};


