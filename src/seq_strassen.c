#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

void add(int **a, int **b, int size, int **c);
void sub(int **a, int **b, int size, int **c);
void multiply(int **c, int **d, int size, int size2, int **new);
void init_matrix_random(int **matrix, int size, int actualSize);
void print_matrix(char* title, int **matrix, int size);

void multiply(int **c, int **d, int size, int size2, int **new){
    if(size == 1){
        new[0][0] = c[0][0] * d[0][0];
    }
    else {
        int i, j;
        int nsize = size/2;
        
        // Alocar submatrizes
        int **c11 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            c11[i] = malloc(nsize*sizeof(int));
        }
        int **c12 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            c12[i] = malloc(nsize * sizeof(int));
        }
        int **c21 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            c21[i] = malloc(nsize * sizeof(int));
        }
        int **c22 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            c22[i] = malloc(nsize*sizeof(int));
        }
        int **d11 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            d11[i] = malloc(nsize*sizeof(int));
        }
        int **d12 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            d12[i] = malloc(nsize*sizeof(int));
        }
        int **d21 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            d21[i] = malloc(nsize*sizeof(int));
        }
        int **d22 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            d22[i] = malloc(nsize*sizeof(int));
        }
        int **m1 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            m1[i] = malloc(nsize*sizeof(int));
        }
        int **m2 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            m2[i] = malloc(nsize*sizeof(int));
        }
        int **m3 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            m3[i] = malloc(nsize*sizeof(int));
        }
        int **m4 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            m4[i] = malloc(nsize*sizeof(int));
        }
        int **m5 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            m5[i] = malloc(nsize*sizeof(int));
        }
        int **m6 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            m6[i] = malloc(nsize*sizeof(int));
        }
        int **m7 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            m7[i] = malloc(nsize * sizeof(int));
        }
        
        // Dividir matrizes em quadrantes
        for(i=0; i<nsize; i++){
            for(j=0; j<nsize; j++){
                c11[i][j] = c[i][j];
                c12[i][j] = c[i][j+nsize];
                c21[i][j] = c[i+nsize][j];
                c22[i][j] = c[i+nsize][j+nsize];
                d11[i][j] = d[i][j];
                d12[i][j] = d[i][j+nsize];
                d21[i][j] = d[i+nsize][j];
                d22[i][j] = d[i+nsize][j+nsize];
            }
        }
        
        int **temp1 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            temp1[i] = malloc(nsize*sizeof(int));
        }
        int **temp2 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            temp2[i] = malloc(nsize*sizeof(int));
        }

        // M1 = (c11 + c22) * (d11 + d22)
        add(c11, c22, nsize, temp1);
        add(d11, d22, nsize, temp2);
        multiply(temp1, temp2, nsize, size, m1);
        free(temp1);
        free(temp2);

        // M2 = (c21 + c22) * d11
        int **temp3 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            temp3[i] = malloc(nsize*sizeof(int));
        }
        add(c21, c22, nsize, temp3);
        multiply(temp3, d11, nsize, size, m2);
        free(temp3);

        // M3 = c11 * (d12 - d22)
        int **temp4 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            temp4[i] = malloc(nsize*sizeof(int));
        }
        sub(d12, d22, nsize, temp4);
        multiply(c11, temp4, nsize, size, m3);
        free(temp4);

        // M4 = c22 * (d21 - d11)
        int **temp5 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            temp5[i] = malloc(nsize*sizeof(int));
        }
        sub(d21, d11, nsize, temp5);
        multiply(c22, temp5, nsize, size, m4);
        free(temp5);

        // M5 = (c11 + c12) * d22
        int **temp6 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            temp6[i] = malloc(nsize*sizeof(int));
        }
        add(c11, c12, nsize, temp6);
        multiply(temp6, d22, nsize, size, m5);
        free(temp6);

        // M6 = (c21 - c11) * (d11 + d12)
        int **temp7 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            temp7[i] = malloc(nsize*sizeof(int));
        }
        int **temp8 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            temp8[i] = malloc(nsize*sizeof(int));
        }
        sub(c21, c11, nsize, temp7);
        add(d11, d12, nsize, temp8);
        multiply(temp7, temp8, nsize, size, m6);
        free(temp7);
        free(temp8);

        // M7 = (c12 - c22) * (d21 + d22)
        int **temp9 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            temp9[i] = malloc(nsize*sizeof(int));
        }
        int **temp10 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            temp10[i] = malloc(nsize*sizeof(int));
        }
        sub(c12, c22, nsize, temp9);
        add(d21, d22, nsize, temp10);
        multiply(temp9, temp10, nsize, size, m7);
        free(temp9);
        free(temp10);

        // Calcular quadrantes da matriz resultado
        int **te1 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            te1[i] = malloc(nsize*sizeof(int));
        }
        int **te2 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            te2[i] = malloc(nsize*sizeof(int));
        }
        int **te3 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            te3[i] = malloc(nsize*sizeof(int));
        }
        int **te4 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            te4[i] = malloc(nsize*sizeof(int));
        }
        int **te5 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            te5[i] = malloc(nsize*sizeof(int));
        }
        int **te6 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            te6[i] = malloc(nsize*sizeof(int));
        }
        int **te7 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            te7[i] = malloc(nsize*sizeof(int));
        }
        int **te8 = malloc(nsize * sizeof(int *));
        for(i=0; i<nsize; i++){
            te8[i] = malloc(nsize*sizeof(int));
        }

        // C11 = M1 + M4 - M5 + M7
        add(m1, m7, nsize, te1);
        sub(m4, m5, nsize, te2);
        add(te1, te2, nsize, te3);

        // C12 = M3 + M5
        add(m3, m5, nsize, te4);
        
        // C21 = M2 + M4
        add(m2, m4, nsize, te5);

        // C22 = M1 - M2 + M3 + M6
        add(m3, m6, nsize, te6);
        sub(m1, m2, nsize, te7);
        add(te6, te7, nsize, te8);

        // Combinar quadrantes na matriz resultado
        int a=0, b=0, c_idx=0, d_idx=0, e=0;
        int nsize2 = 2*nsize;
        for(i=0; i<nsize2; i++){
            for(j=0; j<nsize2; j++){
                if(j>=0 && j<nsize && i>=0 && i<nsize){
                    new[i][j] = te3[i][j];
                }
                if(j>=nsize && j<nsize2 && i>=0 && i<nsize){
                    a = j-nsize;
                    new[i][j] = te4[i][a];
                }
                if(j>=0 && j<nsize && i>=nsize && i<nsize2){
                    c_idx = i-nsize;
                    new[i][j] = te5[c_idx][j];
                }
                if(j>=nsize && j<nsize2 && i>=nsize && i<nsize2){
                    d_idx = i-nsize;
                    e = j-nsize;
                    new[i][j] = te8[d_idx][e];
                }
            }
        }
        
        // Liberar memória
        free(m1); free(m2); free(m3); free(m4);
        free(m5); free(m6); free(m7);
        free(te1); free(te2); free(te3); free(te4);
        free(te5); free(te6); free(te7); free(te8);
        free(c11); free(c12); free(c21); free(c22);
        free(d11); free(d12); free(d21); free(d22);
    }
}

void main(){
    int size, p, i, j;
    
    // Tamanho fixo da matriz (deve ser potência de 2)
    int tempS = 8; // Altere para 4, 8, 16, 32, etc.
    size = tempS;
    
    // Garantir que o tamanho é potência de 2
    if((size & (size-1)) != 0){
        p = log(size)/log(2);
        size = pow(2, p+1);
    }
    
    printf("=== MULTIPLICAÇÃO DE MATRIZES - ALGORITMO DE STRASSEN ===\n");
    printf("Tamanho das matrizes: %d x %d\n\n", tempS, tempS);
    
    // Inicializar gerador de números aleatórios
    srand(time(NULL));
    
    // Alocar matrizes
    int **a = malloc(size * sizeof(int *));
    for(i=0; i<size; i++){
        a[i] = malloc(size*sizeof(int));
    }
    int **b = malloc(size * sizeof(int *));
    for(i=0; i<size; i++){
        b[i] = malloc(size*sizeof(int));
    }
    
    // Inicializar matrizes com valores aleatórios
    init_matrix_random(a, size, tempS);
    init_matrix_random(b, size, tempS);
    
    // Imprimir matrizes de entrada
    print_matrix("Matriz A:", a, tempS);
    printf("\n");
    print_matrix("Matriz B:", b, tempS);
    printf("\n");
    
    // Alocar matriz resultado
    int **new = malloc(size * sizeof(int *));
    for(i=0; i<size; i++){
        new[i] = malloc(size*sizeof(int));
    }
    
    // Medir tempo de execução
    clock_t start = clock();
    multiply(a, b, size, size, new);
    clock_t end = clock();
    
    // Imprimir matriz resultado
    if(tempS < size)
        size = tempS;
    
   // print_matrix("Matriz C (Produto A x B):", new, size);
    
    // Exibir tempo de execução
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n=== TEMPO DE EXECUÇÃO ===\n");
    printf("Tempo: %.6f segundos\n", cpu_time_used);
    printf("Tempo: %.2f milissegundos\n", cpu_time_used * 1000);
    
    // Liberar memória
    free(a);
    free(b);
    free(new);
}

void add(int **a, int **b, int size, int **c){
    int i, j;
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void sub(int **a, int **b, int size, int **c){
    int i, j;
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void init_matrix_random(int **matrix, int size, int actualSize){
    int i, j;
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            if(i >= actualSize || j >= actualSize){
                matrix[i][j] = 0; // Preencher com zeros para padding
            } else {
                matrix[i][j] = rand() % 10; // Valores entre 0 e 9
            }
        }
    }
}

void print_matrix(char* title, int **matrix, int size){
    int i, j;
    printf("%s\n", title);
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}
