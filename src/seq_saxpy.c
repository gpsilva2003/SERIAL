#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void saxpy(int n, float a, float *x, float *restrict y)
{

for (int i = 0; i < n; ++i)
     y[i] = a * x[i] + y[i];
}

int main(int argc, char **argv)
{
    int N = 1<<20; // 1 milhão de floats
    clock_t inicio, fim;
    double tempo;
    if (argc > 1)
        N = atoi(argv[1]);

    float *x = (float*)malloc(N * sizeof(float));
    float *y = (float*)malloc(N * sizeof(float));
    for (int i = 0; i < N; ++i) {
        x[i] = 2.0f;
        y[i] = 1.0f;
    }
    inicio = clock();
    saxpy(N, 3.0f, x, y);
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n", tempo);
    printf("Elementos: %lld — Taxa: %.2f milhões de elementos/seg\n",
           n, (n / 1e6) / tempo);
    free(x);
    free(y);
    return 0;
}
