#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm nhân ma trận
void multiply_matrix(int** matrix_a, int** matrix_b, int** matrix_c, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
}

// Hàm khởi tạo ma trận với giá trị cho trước
int** create_matrix(int size, int value) {
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = value;
        }
    }
    return matrix;
}

// Hàm giải phóng bộ nhớ ma trận
void free_matrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int sizes[] = {10, 25, 50, 75, 100, 250, 500, 750, 1000, 1250};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    // Mảng lưu thời gian thực thi
    double* elapsed_times = (double*)malloc(num_sizes * sizeof(double));

    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];

        // Tạo ma trận A, B và C
        int** matrix_a = create_matrix(size, 1);
        int** matrix_b = create_matrix(size, 2);
        int** matrix_c = create_matrix(size, 0);

        // Đo thời gian thực thi
        clock_t start_time = clock();
        multiply_matrix(matrix_a, matrix_b, matrix_c, size);
        clock_t end_time = clock();

        // Tính thời gian thực thi
        double elapsed_seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        elapsed_times[i] = elapsed_seconds;

        printf("C Execution Time for size = %d: %f seconds\n", size, elapsed_seconds);

        // Giải phóng bộ nhớ
        free_matrix(matrix_a, size);
        free_matrix(matrix_b, size);
        free_matrix(matrix_c, size);
    }

    // Giải phóng mảng thời gian thực thi
    free(elapsed_times);

    return 0;
}
