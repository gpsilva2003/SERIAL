#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printHistogram(int *hist, int n);

int main(int argc, char *argv[]) {   /* seq_histogram.c */
    int i, j;

    // Gerar quantidade suficiente de dados
    int inputValue = 800000000;
    int *data = (int *)malloc(inputValue * sizeof(int));

    if (data == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Inicializar gerador de números aleatórios
    srand(time(NULL));

    printf("Gerando %d valores aleatórios entre 0 e 9...\n", inputValue);

    // Gerar valores aleatórios
    for (i = 0; i < inputValue; i++) {
        data[i] = rand() % 10;
    }

    printf("Valores gerados com sucesso!\n");

    // Iniciar medição de tempo
    clock_t start = clock();

    int results[10] = {0};

    // Processamento para computar histograma
    for (i = 0; i < 10; ++i) {
        for(j = 0; j < inputValue; j++) {
            if (data[j] == i)
                results[i]++;
        }
    }
    // Finalizar medição de tempo
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("=== HISTOGRAMA ===\n");
    printHistogram(results, 10);

    printf("\n=== MÉTRICAS DE DESEMPENHO ===\n");
    printf("Tempo de execução: %.6f segundos\n", cpu_time_used);
    printf("Total de valores processados: %d\n", inputValue);

    // Liberar memória alocada
    free(data);

    return 0;
}

void printHistogram(int *hist, int n) {
    int i;
    for (i = 0; i < n; i++) {
            printf("hist[%d] = %d \n", i, hist[i]);
        }
}
