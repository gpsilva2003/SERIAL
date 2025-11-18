#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void saxpy(int n, double a, double *x, double *restrict y)
{

for (int i = 0; i < n; ++i)
     y[i] = a * x[i] + y[i];
}

int main(int argc, char **argv)
{
    long int N = 1<<30; // 1 bilhão de doubles
    clock_t inicio, fim;
    double tempo;
    if (argc > 1)
        N = atoi(argv[1]);

    double *x = (double*)malloc(N * sizeof(double));
    double *y = (double*)malloc(N * sizeof(double));
    for (int i = 0; i < N; ++i) {
        x[i] = 2.0f;
        y[i] = 1.0f;
    }
    inicio = clock();
    saxpy(N, 3.0f, x, y);
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n", tempo);
    printf("Elementos: %ld — Taxa: %.2f milhões de elementos/seg\n", N, (N / 1e6) / tempo);
    free(x);
    free(y);
    return 0;
}
