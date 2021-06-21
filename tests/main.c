#include "../cmatrix.h"
#include <stdio.h>
#if defined(_OPENMP)
    #include <omp.h>
#else
    #include <time.h>
#endif

int main(int argc, char **argv) {
    matrix m1 = matrix_constructor(1000, 1000);
    matrix m2 = matrix_constructor(1000, 1000);

    matrix_randomize(m1, -99999.0, 99999.0);
    matrix_randomize(m2, -99999.0, 99999.0);

    #if defined(_OPENMP)
        double start = omp_get_wtime();
    #else
        clock_t t;
        t = clock();
    #endif
    matrix m3 = matrix_mult(m1, m2);
    #if defined(_OPENMP)
        double end = omp_get_wtime();
        printf("Parallel Work took %f seconds\n", end - start);
    #else
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("Work took %f seconds\n", time_taken);
    #endif

    matrix_delete(m1);
    matrix_delete(m2);
    matrix_delete(m3);

    return 0;
}