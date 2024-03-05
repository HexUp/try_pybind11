#include <iostream>
#include <chrono>
#include "matrix.h"


void Test()
{
    std::cout << "Input Test Dimension: ";
    size_t N;
    std::cin >> N;

    Matrix A(N,N), B(N,N), C(N,N);
    // Initialize A and B with random values
    A.FillRandom();
    B.FillRandom();

    // Start the clock
    auto start = std::chrono::high_resolution_clock::now();

    // Perform the dot product operation
    Matrix::Dot(A, B, C);

    // Stop the clock
    auto stop = std::chrono::high_resolution_clock::now();
    // Calculate the duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    // Print the summary of the matrices
    A.PrintSummary();
    B.PrintSummary();
    C.PrintSummary();

    std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;
}

int main()
{
    Test();
    return 0;
}