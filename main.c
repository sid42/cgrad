#include "matmul.h"
#include <stdio.h>

#define N 2

int main() {
    float A[N*N] = { 1, 2, 3, 4 };
    float B[N*N] = { 5, 6, 7, 8 };
    float C[N*N] = {0};  

    matmul_simple(A, B, C, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%f ", C[i * N + j]);
        }
        printf("\n");
    }
}