#include <stdio.h>
#include <omp.h>

long long fib_rec(int n)
{
    if (n <= 2)
        return 1;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

int main(void)
{
    int n = 50;    // valor fixado; acima de 45 pode demorar bastante!
    double t0, t1;

    t0 = omp_get_wtime();
    long long resultado = fib_rec(n);
    t1 = omp_get_wtime();

    printf("fib(%d) = %lld\n", n, resultado);
    printf("Tempo: %f segundos\n", t1 - t0);

    return 0;
}
