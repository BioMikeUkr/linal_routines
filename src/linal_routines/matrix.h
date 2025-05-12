#ifndef MATRIX_H
#define MATRIX_H
#include "point.h"
#include "vector.h"

typedef struct MATRIX {
    int type;
    int size[2];
    VECTOR **value;
} MATRIX;

MATRIX *init_matrix(VECTOR **vectors, int *size);
MATRIX *init_zero_matrix(int *size);
MATRIX *init_one_matrix(int *size);
int free_matrix(MATRIX *matx);
int print_matrix(MATRIX *matx);

int add_matrix(MATRIX *matx_1, MATRIX *matx_2, MATRIX *out);
int add_point_to_matrix(MATRIX *matx, POINT *point, MATRIX *out);
int diff_matrix(MATRIX *matx_1, MATRIX *matx_2, MATRIX *out);
int diff_point_from_matrix(MATRIX *matx, POINT *point, MATRIX *out);
int mul_matrix(MATRIX *matx_1, MATRIX *matx_2, MATRIX *out);
int mul_matrix_by_point(MATRIX *matx, POINT *point, MATRIX *out);
int div_matrix(MATRIX *matx_1, MATRIX *matx_2, MATRIX *out);
int div_matrix_by_point(MATRIX *matx, POINT *point, MATRIX *out);

int auto_compute_mat_mul_out_size(MATRIX *matx_1, MATRIX *matx_2, int out[2]);

int mat_mul_matrix(MATRIX *matx_1, MATRIX *matx_2, MATRIX *out);

#endif