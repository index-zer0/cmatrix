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

void matrix_hadamard(matrix m, matrix a) {
    // element - wise mult
    int i;
    // more checks
    if (m->rows != a->rows || m->columns != a->columns) {
        printf("ERROR: matrices should have the save dimensions\n");
        exit(1);
    }
    for (i = 0; i < m->rows * m->columns; i++) {
        m->p[i] *= a->p[i];
    }
    return;
}

void matrix_add(matrix m, matrix a) {
    int i;
    // more checks
    if (m->rows != a->rows || m->columns != a->columns) {
        printf("ERROR: matrices should have the save dimensions\n");
        exit(1);
    }
    for (i = 0; i < m->rows * m->columns; i++) {
        m->p[i] += a->p[i];
    }
    return;
}

matrix matrix_mult(matrix m, matrix a) {
    if (m->columns != a->rows) {
        printf("ERROR:number of columns of the first matrix is different than the rows of the second one\n");
        exit(1);
    }
    matrix n = matrix_constructor(m->rows, a->columns);
    int i, j, k;
    for (i = 0; i < n->rows; i++) {
        for (j = 0; j < n->columns; j++) {
            for (k = 0; k < m->columns; k++) {
                n->p[i * n->columns + j] += m->p[i*m->columns + k] * a->p[k*a->columns + j];
            }
        }
    }
    return n;
}

double get_random(double min, double max) {
    return (double)rand()/RAND_MAX*(max + 1.0) + min;
}

void matrix_randomize(matrix m, double min, double max) {
    int i;
    for (i = 0; i < m->rows * m->columns; i++) {
        m->p[i] = get_random(min, max);
    }
    return;
}

matrix transpose(matrix m) {
    int i, j;
    matrix t = matrix_constructor(m->columns, m->rows);
    for (i = 0; i < m->columns; i++) {
        for (j = 0; j < m->rows; j++) {
            t->p[i * m->rows * j] = m->p[i + j * m->columns];
        }
    }
    return t;
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