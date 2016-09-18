#include <cmath>
#include <vector>

class Matrix {
    public:
        int rows;
        int cols;
        std::vector< std::vector<double> > elementAt;
        Matrix(int r, int c) {
            rows = r;
            cols = c;
            elementAt.resize(rows, std::vector<double> (cols, 0));
        }
};

Matrix* add(Matrix* m1, Matrix* m2)
{
    Matrix* result = new Matrix(m1 -> rows, m1 -> cols);
    for (int i = 0; i < m1 -> rows; i++) {
        for (int j = 0; j < m1 -> cols; j++) {
            result->elementAt[i][j] = m1->elementAt[i][j] + m2->elementAt[i][j];
        }
    }
    return result;
}

Matrix* multiply(Matrix* m1, Matrix* m2) 
{
    Matrix* result = new Matrix(m1->rows, m2->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            double curr = 0;
            for (int k = 0; k < m1->cols; k++) {
                curr += m1->elementAt[i][k] * m2->elementAt[k][j];
            }
            result->elementAt[i][j] = curr;
        }
    }
    return result;
}

