#ifndef VECTOR_H
#define VECTOR_H
#include "point.h"

typedef struct VECTOR {
    int type;
    int size;
    POINT **value;
} VECTOR;

VECTOR *init_vector(double *points, int size);
VECTOR *init_zero_vector(int size);
VECTOR *init_one_vector(int size);
int free_vector(VECTOR *vector);
int print_vector(VECTOR *vector);

int add_vector(VECTOR *vec_1, VECTOR *vec_2, VECTOR *out);
int add_point_to_vector(VECTOR *vec_1, POINT *point, VECTOR *out);
int diff_vector(VECTOR *vec_1, VECTOR *vec_2, VECTOR *out);
int diff_point_from_vector(VECTOR *vec_1, POINT *point, VECTOR *out);
int mul_vector(VECTOR *vec_1, VECTOR *vec_2, VECTOR *out);
int mul_vector_by_point(VECTOR *vec, POINT *point, VECTOR *out);
int div_vector(VECTOR *vec_1, VECTOR *vec_2, VECTOR *out);
int div_vector_by_point(VECTOR *vec, POINT *point, VECTOR *out);

int mat_mul_vector(VECTOR *vec_1, VECTOR *vec_2, POINT *out);
int get_l2_norm(VECTOR *vec, POINT* out);

#endif