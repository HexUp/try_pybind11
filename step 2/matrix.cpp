#include <vector>
#include <stdexcept> // For std::invalid_argument
#include <random>
#include <iostream>

#include "matrix.h"


Matrix::Matrix(size_t rows, size_t cols): rows(rows), cols(cols), data(rows * cols, 0.0f)
{}

void Matrix::Set(int row, int col, float value)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        data[row * cols + col] = value;
    }
}

float Matrix::Get(int row, int col) const
{
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return data[row * cols + col];
    }
    throw std::out_of_range("Matrix indices out of range");
}

Matrix Matrix::Dot(const Matrix& other) const
{
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions mismatch for dot product");
    }

    Matrix result(rows, other.cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < other.cols; j++) {
            float sum = 0.0f;
            for (size_t k = 0; k < cols; k++) {
                sum += this->Get(i, k) * other.Get(k, j);
            }
            result.Set(i, j, sum);
        }
    }
    return result;
}

void Matrix::Print() const
{
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            std::cout << Get(i, j) << " ";
        }
        std::cout << std::endl;
    }    
}

void Matrix::FillRandom()
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_real_distribution<float> distr(0.0f, 1.0f);

    for (size_t i = 0; i < rows; i++)
    for (size_t j = 0; j < cols; j++) {
        this->Set(i, j, distr(eng));
    }
}
