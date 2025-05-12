#include <stdio.h>
#include <linal/utils.h>
#include <linal/matrix.h>

int main() {
    int out_size[2];
    MATRIX *matx_1 = load("matrices/matrix_1.txt", "matrix");
    MATRIX *matx_2 = load("matrices/matrix_2.txt", "matrix");

    auto_compute_mat_mul_out_size(matx_1, matx_2, out_size);
    MATRIX *out_matx = init_zero_matrix(out_size);

    printf("matx_1:\n");
    print_obj(matx_1);
    printf("matx_2:\n");
    print_obj(matx_2);

    mat_mul_matrix(matx_1, matx_2, out_matx);
    printf("mat_mul:\n");
    print_obj(out_matx);
}