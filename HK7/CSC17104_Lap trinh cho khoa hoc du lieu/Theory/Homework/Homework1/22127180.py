import numpy as np
import random
import time
def generate_random_matrix(N):
    return [[random.random() for _ in range(N)] for _ in range(N)]

def multiply_pure_python_optimized(a, b, N):
    c = [[0 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            sum_value = 0
            for k in range(N):
                sum_value += a[i][k] * b[k][j]
            c[i][j] = sum_value
    return c

if __name__ == "__main__":
    N_values = [10, 25, 50, 75, 100, 250, 500, 750, 1000, 1250]

    python_times = []
    numpy_times = []

    for N in N_values:
        # For Pure Python Optimized with random values
        a_python = generate_random_matrix(N)
        b_python = generate_random_matrix(N)

        # For Numpy with random values
        a_numpy = np.random.rand(N, N)
        b_numpy = np.random.rand(N, N)

        start_python = time.time()
        c_python = multiply_pure_python_optimized(a_python, b_python, N)
        end_python = time.time()
        python_times.append(end_python - start_python)

        start_numpy = time.time()
        c_numpy = np.dot(a_numpy, b_numpy)
        end_numpy = time.time()
        numpy_times.append(end_numpy - start_numpy)

    for i in range(len(N_values)):
        print(f"N = {N_values[i]} - Pure Python: {python_times[i]} seconds, Numpy: {numpy_times[i]} seconds")
