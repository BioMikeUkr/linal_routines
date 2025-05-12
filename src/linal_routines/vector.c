#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "point.h"
#include "vector.h"

//---------------------------------------------------- VECTOR
int free_vector(VECTOR *vec) {
    for (int i=0; i < vec->size; i++) {
        free_point(vec->value[i]);
    }
    free(vec->value);
    free(vec);
    return 0;
}

int print_vector(VECTOR *vec) {
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

VECTOR *init_vector(double *points, int size) {
    VECTOR *vec = malloc(sizeof(VECTOR));
    if (!vec) return NULL;

    vec->size = size;
    vec->type = 1;
    vec->value = malloc(size * sizeof(POINT *));
    if (!vec->value) {
        free(vec);
        return NULL;
    }

    for (int i=0; i < size; i++) {
        vec->value[i] = init_point(points[i]);
    }
    return vec;
}

VECTOR *init_zero_vector(int size) {
    VECTOR *vec = malloc(sizeof(VECTOR));
    if (!vec) return NULL;

    vec->size = size;
    vec->type = 1;

    vec->value = malloc(size * sizeof(POINT *));
    if (!vec->value) {
        free(vec);
        return NULL;
    }

    for (int i=0; i < size; i++) {
        vec->value[i] = init_zero_point();
    }
    return vec;
}
VECTOR *init_one_vector(int size) {
    VECTOR *vec = malloc(sizeof(VECTOR));
    if (!vec) return NULL;

    vec->size = size;
    vec->type = 1;

    vec->value = malloc(size * sizeof(POINT *));
    if (!vec->value) {
        free(vec);
        return NULL;
    }

    for (int i=0; i < size; i++) {
        vec->value[i] = init_one_point();
    }
    return vec;
}
int add_vector(VECTOR *vec_1, VECTOR *vec_2, VECTOR *out) {
    for (int i=0; i < vec_1->size; i++) {
        add_point(vec_1->value[i], vec_2->value[i], out->value[i]);
    }
    return 0;
}

int add_point_to_vector(VECTOR *vec_1, POINT *point, VECTOR *out) {
    for (int i=0; i < vec_1->size; i++) {
        add_point(vec_1->value[i], point, out->value[i]);
    }
    return 0;
}

int diff_vector(VECTOR *vec_1, VECTOR *vec_2, VECTOR *out) {
    for (int i=0; i < vec_1->size; i++) {
        diff_point(vec_1->value[i], vec_2->value[i], out->value[i]);
    }
    return 0;
}

int diff_point_from_vector(VECTOR *vec_1, POINT *point, VECTOR *out) {
    for (int i=0; i < vec_1->size; i++) {
        diff_point(vec_1->value[i], point, out->value[i]);
    }
    return 0;
}

int mul_vector(VECTOR *vec_1, VECTOR *vec_2, VECTOR *out) {
    for (int i=0; i < vec_1->size; i++) {
        mul_point(vec_1->value[i], vec_2->value[i], out->value[i]);
    }
    return 0;
}

int mul_vector_by_point(VECTOR *vec, POINT *point, VECTOR *out) {
    for (int i=0; i<vec->size; i++) {
        mul_point(vec->value[i], point, out->value[i]);
    }
    return 0;
}

int div_vector(VECTOR *vec_1, VECTOR *vec_2, VECTOR *out) {
    for (int i=0; i < vec_1->size; i++) {
        div_point(vec_1->value[i], vec_2->value[i], out->value[i]);
    }
    return 0;
}

int div_vector_by_point(VECTOR *vec, POINT *point, VECTOR *out) {
    for (int i=0; i<vec->size; i++) {
        div_point(vec->value[i], point, out->value[i]);
    }
    return 0;
}

int mat_mul_vector(VECTOR *vec_1, VECTOR *vec_2, POINT *out) {
    VECTOR *temp_vector = init_zero_vector(vec_1->size);
    for (int i=0; i < vec_1->size; i++) {
        mul_point(vec_1->value[i], vec_2->value[i], temp_vector->value[i]);
        add_point(temp_vector->value[i], out, out);
    }
    free_vector(temp_vector);
    return 0;
}

int get_l2_norm(VECTOR *vec, POINT *out) {
    VECTOR *temp_vec = init_zero_vector(vec->size);
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
