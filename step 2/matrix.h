#include <vector>

using std::vector;

class Matrix
{
private:
    vector<float> data;
    size_t rows, cols;

public:
    Matrix(size_t rows, size_t cols);

    void Set(int row, int col, float value);
    float Get(int row, int col) const;

    size_t Rows() const;
    size_t Cols() const;

    void FillRandom();

    Matrix Dot(const Matrix& other) const;
    // static void Dot(const Matrix& A, const Matrix& B, Matrix& C);

    void Print() const;
};