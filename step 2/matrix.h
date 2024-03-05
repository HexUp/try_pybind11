#include <vector>

class Matrix
{
private:
    std::vector<float> data;
    size_t rows, cols;

public:
    Matrix(size_t rows, size_t cols);

    void Set(size_t row, size_t col, float value);
    float Get(size_t row, size_t col) const;

    size_t Rows() const;
    size_t Cols() const;

    void FillRandom();

    Matrix Dot(const Matrix& other) const;
    static void Dot(const Matrix& A, const Matrix& B, Matrix& C);

    void Print() const;
    void PrintSummary() const;
};