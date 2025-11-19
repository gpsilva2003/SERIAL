#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000  // Tamanho da matriz (ajustável)


/* Aloca matriz n×n (float) */
float** allocate_matrix(int n) {
    float** M = (float**)malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++)
        M[i] = (float*)malloc(n * sizeof(float));
    return M;
}

/* Libera matriz */
void free_matrix(float** M, int n) {
    for (int i = 0; i < n; i++)
        free(M[i]);
    free(M);
}

/* Inicia a matriz om valores aleatórios entre 0.0 e 9.9 */
void init_random(float** A, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = (float)(rand() % 100) / 10.0f;
}

/* Multiplicação serial C = A × B */
void matrix_mult(float** A, float** B, float** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0.0f;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    srand(time(NULL));

    printf("Multiplicação de matrizes %dx%d (dinâmica)\n", n, n);

    float** A = allocate_matrix(N);
    float** B = allocate_matrix(N);
    float** C = allocate_matrix(N);

    init_random(A, N);
    init_random(B, N);

    clock_t start = clock();
    matrix_mult(A, B, C, N);
    clock_t end = clock();

    double tempo = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Concluído. Tempo: %.6f s (%.2f ms)\n",
           tempo, tempo * 1000);

    free_matrix(A, N);
    free_matrix(B, N);
    free_matrix(C, N);

    return 0;
}
