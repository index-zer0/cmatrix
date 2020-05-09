typedef struct { 
    int rows;
    int columns; 
    double *p;
} _matrix, *matrix;

matrix matrix_constructor(int, int);
void matrix_delete(matrix);
void matrix_scalar_mult(matrix, double);
void matrix_scalar_add(matrix, double);
void matrix_hadamard(matrix, matrix);
void matrix_add(matrix, matrix);
matrix matrix_mult(matrix, matrix);
double get_random(double, double);
void matrix_randomize(matrix, double, double);
matrix transpose(matrix);
void matrix_print(matrix);