#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>
#define N 100000000

void crivo_de_eratostenes(int limite) {
    bool *primos = (bool*)malloc((limite + 1) * sizeof(bool));

    if (primos == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return;
    }

    for (int i = 0; i <= limite; i++) {
        primos[i] = true;
    }

    for (int i = 3; i * i <= limite; i += 2) {
        if (primos[i]) {
            for (int j = i * i; j <= limite; j += 2 * i) {
                primos[j] = false;
            }
        }
    }

    int cont = 1;  // conta o 2
    for (int i = 3; i <= limite; i += 2) {
        if (primos[i]) cont++;
    }
    printf("Total de números primos encontrados: %d\n", cont);
    free(primos);
}

int main(int argc, char *argv[]) {
    int limite = N;   // valor padrão: 100 milhões

    if (argc >= 2) {
        limite = atoi(argv[1]);
        if (limite <= 2) {
            printf("Valor inválido. Usando valor padrão %d.\n\n", N);
            limite = N;
        }
    }

    printf("Executando o crivo até %d...\n", limite);
    double t0 = omp_get_wtime();
    crivo_de_eratostenes(limite);
    double t1 = omp_get_wtime();
    printf("Tempo de execução: %f segundos\n", t1 - t0);

    return 0;
}
