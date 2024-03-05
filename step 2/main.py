import numpy as np
import time

def PrintSummary(A):
    print("Matrix A:")
    print("  Shape: ", A.shape)
    print("  Size: ", A.size)
    # print first 10 elements
    print("  First 10 elements: ", A.flatten()[:10])

def Test(N):
    # create a NxN matrix
    A = np.random.rand(N, N)
    B = np.random.rand(N, N)
    C = np.random.rand(N, N)

    # measure the time to multiply two matrices

    start = time.time()
    np.dot(A, B, out=C)
    end = time.time()
    
    PrintSummary(A)
    PrintSummary(B)
    PrintSummary(C)

    print("Matrix multiplication time: ", (end - start) * 1000)

if __name__ == "__main__":
    # add a command line argument to specify the size of the matrix
    import sys
    N = int(sys.argv[1])
    Test(N)