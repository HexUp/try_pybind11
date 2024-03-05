import time
import numpy as np
from build.Release import toy_matrix
from pymatrix import PyMatrix

Matrix = toy_matrix.Matrix

def NPArrayFromMatrix(A):
    N = A.Rows()
    M = A.Cols()
    return np.array([[A.Get(i, j) for j in range(M)] for i in range(N)])

def CompareResult(A, B):
    A_NP = NPArrayFromMatrix(A)
    B_NP = NPArrayFromMatrix(B)
    C_NP = A_NP.dot(B_NP)

    C = Matrix(A.Rows(), B.Cols())
    Matrix.Dot(A, B, C)
    C_NP2 = NPArrayFromMatrix(C)

    if not np.allclose(C_NP, C_NP2, atol=1e-6):
        print("Results do not match")
        
        ERR = C_NP - C_NP2
        print("Error: ", np.max(np.abs(ERR)))
    else:
        print("Results match")

def Compare(N=1000):
    A = Matrix(N, N)
    B = Matrix(N, N)
    # C = Matrix(N, N)
    A.FillRandom()
    B.FillRandom()

    CompareResult(A, B)

def TestNumpy(N):
    # create a NxN matrix
    A = np.random.rand(N, N)
    B = np.random.rand(N, N)
    C = np.random.rand(N, N)

    # measure the time to multiply two numpy matrices
    start = time.time()
    np.dot(A, B, out=C)
    end = time.time()

    print(f"Numpy matrix multiplication: size: {N}, time: {(end - start) * 1000} ms")

if __name__ == "__main__":
    import sys
    N = int(sys.argv[1])

    Compare(N)
    TestNumpy(N)