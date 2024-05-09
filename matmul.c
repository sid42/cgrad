#include <immintrin.h>
#include <stdio.h>

void matmul_simple(float* A, float* B, float* C, int n) {
    __m256 a_line, b_line, result_line;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result_line = _mm256_setzero_ps();

            for (int k = 0; k < n; k += 8) {
                a_line = _mm256_loadu_ps(&A[i * n + k]);
                b_line = _mm256_loadu_ps(&B[j * n + k]);

                result_line = _mm256_fmadd_ps(a_line, b_line, result_line);
            }

            C[i * n + j] = _mm256_reduce_add_ps(result_line);
        }
    }
}