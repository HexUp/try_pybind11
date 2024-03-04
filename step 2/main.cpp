#include <iostream>
#include "matrix.h"


void Test()
{
    Matrix A(3,3), B(3,3);
    A.FillRandom();
    B.FillRandom();
    Matrix C = A.Dot(B);
    A.Print();
    B.Print();
    C.Print();
}

int main()
{
    Test();
    return 0;
}