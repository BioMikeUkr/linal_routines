#ifndef VECTOR_H
#define VECTOR_H
#include "point.h"

typedef struct vector {
    int type;
    int size;
    point **value;
} vector;

vector *init_vector(double *points, int size);
vector *init_zero_vector(int size);
vector *init_one_vector(int size);
int free_vector(vector *vector);
int print_vector(vector *vector);

int add_vector(vector *vec_1, vector *vec_2, vector *out);
int add_point_to_vector(vector *vec_1, point *point, vector *out);
int diff_vector(vector *vec_1, vector *vec_2, vector *out);
int diff_point_from_vector(vector *vec_1, point *point, vector *out);
int mul_vector(vector *vec_1, vector *vec_2, vector *out);
int mul_vector_by_point(vector *vec, point *point, vector *out);
int div_vector(vector *vec_1, vector *vec_2, vector *out);
int div_vector_by_point(vector *vec, point *point, vector *out);

int mat_mul_vector(vector *vec_1, vector *vec_2, point *out);
int get_l2_norm(vector *vec, point* out);

#endif