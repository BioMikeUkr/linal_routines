#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "point.h"
#include "vector.h"
#include "matrix.h"

int free_matrix(matrix *matx) {
    for (int i=0; i < matx->size[0]; i++) {
        free_vector(matx->value[i]);
    }
    free(matx->value);
    free(matx);
    return 0;
}

int print_matrix(matrix *matx) {
    printf("[");
    for (int i=0; i < matx->size[0]; i++) {
        if (i!=0) {
            printf("  ");
        }
        if (i == matx->size[0] - 1) {
            print_vector(matx->value[i]);
        }
        else {
            print_vector(matx->value[i]);
            printf(",\n");
        }
    }
    printf("]");
    return 0;
}

matrix *init_matrix(vector **vectors, int *size) {
    matrix *matx = malloc(sizeof(matrix));
    if (!matx) return NULL;

    matx->size[0] = size[0];
    matx->size[1] = size[1];
    matx->type = 2;

    matx->value = malloc(size[0] * sizeof(vector *));
    if (!matx->value) {
        free(matx);
        return NULL;
    }

    for (int i=0; i < size[0]; i++) {
        matx->value[i] = vectors[i];
    }

    return matx;
}

matrix *init_zero_matrix(int *size) {
    matrix *matx = malloc(sizeof(matrix));
    if (!matx) return NULL;

    matx->size[0] = size[0];
    matx->size[1] = size[1];
    matx->type = 2;

    matx->value = malloc(size[0] * sizeof(vector *));
    if (!matx->value) {
        free(matx);
        return NULL;
    }

    for (int i=0; i < size[0]; i++) {
        matx->value[i] = init_zero_vector(size[1]);
    }

    return matx;
}

matrix *init_one_matrix(int *size) {
    matrix *matx = malloc(sizeof(matrix));
    if (!matx) return NULL;

    matx->size[0] = size[0];
    matx->size[1] = size[1];
    matx->type = 2;

    matx->value = malloc(size[0] * sizeof(vector *));
    if (!matx->value) {
        free(matx);
        return NULL;
    }

    for (int i=0; i < size[0]; i++) {
        matx->value[i] = init_one_vector(size[1]);
    }

    return matx;
}

int add_matrix(matrix *matx_1, matrix *matx_2, matrix *out) {
    for (int i=0; i < matx_1->size[0]; i++) {
        add_vector(matx_1->value[i], matx_2->value[i], out->value[i]);
    }
    return 0;
}

int add_point_to_matrix(matrix *matx, point *point, matrix *out) {
    for (int i=0; i < matx->size[0]; i++) {
        add_point_to_vector(matx->value[i], point, out->value[i]);
    }
    return 0;
}

int diff_matrix(matrix *matx_1, matrix *matx_2, matrix *out) {
    for (int i=0; i < matx_1->size[0]; i++) {
        diff_vector(matx_1->value[i], matx_2->value[i], out->value[i]);
    }
    return 0;
}

int diff_point_from_matrix(matrix *matx, point *point, matrix *out) {
    for (int i=0; i < matx->size[0]; i++) {
        diff_point_from_vector(matx->value[i], point, out->value[i]);
    }
    return 0;
}

int mul_matrix(matrix *matx_1, matrix *matx_2, matrix *out) {
    for (int i=0; i < matx_1->size[0]; i++) {
        diff_vector(matx_1->value[i], matx_2->value[i], out->value[i]);
    }
    return 0;
}

int mul_matrix_by_point(matrix *matx, point *point, matrix *out) {
    for (int i=0; i < matx->size[0]; i++) {
        mul_vector_by_point(matx->value[i], point, out->value[i]);
    }
    return 0;
}

int div_matrix(matrix *matx_1, matrix *matx_2, matrix *out) {
    for (int i=0; i < matx_1->size[0]; i++) {
        div_vector(matx_1->value[i], matx_2->value[i], out->value[i]);
    }
    return 0;
}

int div_matrix_by_point(matrix *matx, point *point, matrix *out) {
    for (int i=0; i < matx->size[0]; i++) {
        div_vector_by_point(matx->value[i], point, out->value[i]);
    }
    return 0;
}

int transpose_matrix(matrix *matx, matrix *out) {
    for (int i=0; i < matx->size[0]; i++) {
        for (int j=0; j < matx->size[1]; j++) {
            out->value[j]->value[i] = matx->value[i]->value[j];
        }
    }
    return 0;
}

int auto_compute_mat_mul_out_size(matrix *matx_1, matrix *matx_2, int out[2]) {
    out[0] = matx_1->size[0];
    out[1] = matx_2->size[1];
    return 0;
}

int mat_mul_matrix(matrix *matx_1, matrix *matx_2, matrix *out) {
    int transposed_matx_2_size[2] = {matx_2->size[1], matx_2->size[0]};
    matrix *transposed_matx_2 = init_zero_matrix(transposed_matx_2_size);
    transpose_matrix(matx_2, transposed_matx_2);
    
    for (int i=0; i < matx_1->size[0]; i++) {
        for (int j=0; j < matx_2->size[1]; j++) {
            mat_mul_vector(matx_1->value[i], transposed_matx_2->value[j], out->value[i]->value[j]);
        }
    }
    free_matrix(transposed_matx_2);
    return 0;
}
