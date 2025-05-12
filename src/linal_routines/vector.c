#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "point.h"
#include "vector.h"

//---------------------------------------------------- vector
int free_vector(vector *vec) {
    for (int i=0; i < vec->size; i++) {
        free_point(vec->value[i]);
    }
    free(vec->value);
    free(vec);
    return 0;
}

int print_vector(vector *vec) {
    printf("[");
    for (int i=0; i < vec->size; i++) {
        if (i == vec->size - 1) {
            print_point(vec->value[i]);
        }
        else {
            print_point(vec->value[i]);
            printf(" ");
        }
    }
    printf("]");
    return 0;
}

vector *init_vector(double *points, int size) {
    vector *vec = malloc(sizeof(vector));
    if (!vec) return NULL;

    vec->size = size;
    vec->type = 1;
    vec->value = malloc(size * sizeof(point *));
    if (!vec->value) {
        free(vec);
        return NULL;
    }

    for (int i=0; i < size; i++) {
        vec->value[i] = init_point(points[i]);
    }
    return vec;
}

vector *init_zero_vector(int size) {
    vector *vec = malloc(sizeof(vector));
    if (!vec) return NULL;

    vec->size = size;
    vec->type = 1;

    vec->value = malloc(size * sizeof(point *));
    if (!vec->value) {
        free(vec);
        return NULL;
    }

    for (int i=0; i < size; i++) {
        vec->value[i] = init_zero_point();
    }
    return vec;
}
vector *init_one_vector(int size) {
    vector *vec = malloc(sizeof(vector));
    if (!vec) return NULL;

    vec->size = size;
    vec->type = 1;

    vec->value = malloc(size * sizeof(point *));
    if (!vec->value) {
        free(vec);
        return NULL;
    }

    for (int i=0; i < size; i++) {
        vec->value[i] = init_one_point();
    }
    return vec;
}
int add_vector(vector *vec_1, vector *vec_2, vector *out) {
    for (int i=0; i < vec_1->size; i++) {
        add_point(vec_1->value[i], vec_2->value[i], out->value[i]);
    }
    return 0;
}

int add_point_to_vector(vector *vec_1, point *point, vector *out) {
    for (int i=0; i < vec_1->size; i++) {
        add_point(vec_1->value[i], point, out->value[i]);
    }
    return 0;
}

int diff_vector(vector *vec_1, vector *vec_2, vector *out) {
    for (int i=0; i < vec_1->size; i++) {
        diff_point(vec_1->value[i], vec_2->value[i], out->value[i]);
    }
    return 0;
}

int diff_point_from_vector(vector *vec_1, point *point, vector *out) {
    for (int i=0; i < vec_1->size; i++) {
        diff_point(vec_1->value[i], point, out->value[i]);
    }
    return 0;
}

int mul_vector(vector *vec_1, vector *vec_2, vector *out) {
    for (int i=0; i < vec_1->size; i++) {
        mul_point(vec_1->value[i], vec_2->value[i], out->value[i]);
    }
    return 0;
}

int mul_vector_by_point(vector *vec, point *point, vector *out) {
    for (int i=0; i<vec->size; i++) {
        mul_point(vec->value[i], point, out->value[i]);
    }
    return 0;
}

int div_vector(vector *vec_1, vector *vec_2, vector *out) {
    for (int i=0; i < vec_1->size; i++) {
        div_point(vec_1->value[i], vec_2->value[i], out->value[i]);
    }
    return 0;
}

int div_vector_by_point(vector *vec, point *point, vector *out) {
    for (int i=0; i<vec->size; i++) {
        div_point(vec->value[i], point, out->value[i]);
    }
    return 0;
}

int mat_mul_vector(vector *vec_1, vector *vec_2, point *out) {
    vector *temp_vector = init_zero_vector(vec_1->size);
    for (int i=0; i < vec_1->size; i++) {
        mul_point(vec_1->value[i], vec_2->value[i], temp_vector->value[i]);
        add_point(temp_vector->value[i], out, out);
    }
    free_vector(temp_vector);
    return 0;
}

int get_l2_norm(vector *vec, point *out) {
    vector *temp_vec = init_zero_vector(vec->size);
    for (int i=0; i<vec->size; i++) {
            mul_point(vec->value[i], vec->value[i], temp_vec->value[i]);
    }
    for (int i=0; i<vec->size; i++) {
        add_point(temp_vec->value[i], out, out);
    }
    out->value = sqrt(out->value);
    free_vector(temp_vec);
    return 0;
}
