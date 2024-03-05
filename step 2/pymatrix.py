"""A naive Python implementation of matrix multiplication
"""

import random
import time
from statistics import mean

class PyMatrix:
    def __init__(self, rows, cols, random_fill=False):
        self.rows = rows
        self.cols = cols

        if random_fill:
            self.data = [random.random() for _ in range(rows * cols)]
        else:
            self.data = [0.0] * (rows * cols)

    def Get(self, row, col):
        return self.data[row * self.cols + col]
    
    def Set(self, row, col, value):
        self.data[row * self.cols + col] = value

    def Dot(self, other):
        if self.cols != other.rows:
            raise ValueError("Matrices cannot be multiplied")

        result = PyMatrix(self.rows, other.cols)
        for i in range(self.rows):
            for j in range(other.cols):
                sum = 0.0
                for k in range(self.cols):
                    sum += self.Get(i, k) * other.Get(k, j)
                result.Set(i, j, sum)
        return result
    
    @staticmethod
    def Dot(A, B, C):
        if A.cols != B.rows:
            raise ValueError("Matrices cannot be multiplied")
        
        if A.rows != C.rows or B.cols != C.cols:
            raise ValueError("Result PyMatrix has wrong dimensions")

        for i in range(A.rows):
            for j in range(B.cols):
                sum = 0.0
                for k in range(A.cols):
                    sum += A.Get(i, k) * B.Get(k, j)
                C.Set(i, j, sum)


if __name__ == "__main__":
    import sys
    N = int(sys.argv[1])

    m = PyMatrix(N, N, random_fill=True)
    n = PyMatrix(N, N, random_fill=True)
    r = PyMatrix(N, N)

    start = time.time()
    PyMatrix.Dot(m, n, r)
    end = time.time()
    print("PyMatrix multiplication time in naive python: ", (end - start) * 1000)

    print(mean(r.data))