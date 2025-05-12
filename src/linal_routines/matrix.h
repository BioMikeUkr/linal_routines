#ifndef MATRIX_H
#define MATRIX_H
#include "point.h"
#include "vector.h"

typedef struct matrix {
    int type;
    int size[2];
    vector **value;
} matrix;

matrix *init_matrix(vector **vectors, int *size);
matrix *init_zero_matrix(int *size);
matrix *init_one_matrix(int *size);
int free_matrix(matrix *matx);
int print_matrix(matrix *matx);

int add_matrix(matrix *matx_1, matrix *matx_2, matrix *out);
int add_point_to_matrix(matrix *matx, point *point, matrix *out);
int diff_matrix(matrix *matx_1, matrix *matx_2, matrix *out);
int diff_point_from_matrix(matrix *matx, point *point, matrix *out);
int mul_matrix(matrix *matx_1, matrix *matx_2, matrix *out);
int mul_matrix_by_point(matrix *matx, point *point, matrix *out);
int div_matrix(matrix *matx_1, matrix *matx_2, matrix *out);
int div_matrix_by_point(matrix *matx, point *point, matrix *out);

int auto_compute_mat_mul_out_size(matrix *matx_1, matrix *matx_2, int out[2]);

int mat_mul_matrix(matrix *matx_1, matrix *matx_2, matrix *out);

#endif