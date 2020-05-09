#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <time.h>
#include "cmatrix.h"

matrix matrix_constructor(int r, int c) {
    matrix m = (matrix)malloc(sizeof(_matrix));
    m->rows = r;
    m->columns = c;
    m->p = (double*)malloc(sizeof(double) * m->rows * m->columns);
    memset(m->p, 0.0, sizeof(double) * m->rows * m->columns);
    return m;
}

void matrix_delete(matrix m) {
    free(m->p);
    free(m);
}

void matrix_scalar_mult(matrix m, double number) {
    int i;
    for (i = 0; i < m->rows * m->columns; i++) {
        m->p[i] *= number;
    }
    return;
}

void matrix_scalar_add(matrix m, double number) {
    int i;
    for (i = 0; i < m->rows * m->columns; i++) {
        m->p[i] += number;
    }
    return;
}

void matrix_print(matrix m) {
    int i;
    if (m == NULL) {
        return;
    }
    for (i = 0; i < m->rows * m->columns; i++) {
        printf("%lf", m->p[i]);
        if ((i + 1) % m->columns == 0) {
            printf("\n");
        }
        else {
            printf(" ");
        }
    }
    return;
}


int main(void) {
    matrix m0 = matrix_constructor(3, 2);
    matrix_scalar_add(m0, 1.3);
    matrix_scalar_mult(m0, 2);
    matrix_print(m0);
    matrix_delete(m0);
}