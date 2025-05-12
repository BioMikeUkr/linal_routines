#include <stdio.h>
#include <linal/utils.h>
#include <linal/point.h>
#include <linal/vector.h>

int main() {
    double array_1[] = {1, 1, 1, 0};

    vector *v_1 = load("vectors/vec_1.txt", "vector");
    vector *v_2 = init_vector(array_1, 4);

    point *mmul_res = init_zero_point();

    point *v_1_l2_norm = init_zero_point();
    point *v_2_l2_norm = init_zero_point();

    get_l2_norm(v_1, v_1_l2_norm);
    get_l2_norm(v_2, v_2_l2_norm);

    printf("v_1 l2 norm:\n");
    print_obj(v_1_l2_norm);
    printf("v_2 l2 norm:\n");
    print_obj(v_2_l2_norm);

    div_vector_by_point(v_1, v_1_l2_norm, v_1);
    div_vector_by_point(v_2, v_2_l2_norm, v_2);

    printf("v_1 normalized:\n");
    print_obj(v_1);
    printf("v_2 normalized:\n");
    print_obj(v_2);

    mat_mul_vector(v_1, v_2, mmul_res);
    printf("v_1 & v_2 cosine similarity:\n");
    print_obj(mmul_res);
    printf("\n");

    free_point(mmul_res);
    free_point(v_1_l2_norm);
    free_point(v_2_l2_norm);

    free_vector(v_1);
    free_vector(v_2);

    return 0;
}