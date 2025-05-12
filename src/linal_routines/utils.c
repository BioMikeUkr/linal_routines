#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "point.h"
#include "vector.h"
#include "matrix.h"


Types TYPES = {
    .types = {"point", "vector", "matrix", "tensor"}
};

int print_obj(void *obj) {
    int type = *((int *)obj);
    if (type == 0) {
        printf("[[");
        print_point(obj);
        char *type_name = TYPES.types[type];
        printf("], type = (%s)(double)]\n", type_name);
    }
    else if (type == 1) {
        printf("[");
        print_vector(obj);
        char *type_name = TYPES.types[type];
        printf(", type = (%s)(double)]\n", type_name);
    }
    else if (type == 2) {
        printf("[");
        print_matrix(obj);
        char *type_name = TYPES.types[type];
        printf(", type = (%s)(double)]\n", type_name);
    }
    return 0;
}


void *load_object_from_file(const char *filename, char **type_out) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;

    char lines[1024][1024];
    int line_count = 0;

    while (fgets(lines[line_count], sizeof(lines[line_count]), file)) {
        if (strlen(lines[line_count]) > 1) line_count++;
    }
    fclose(file);

    if (line_count == 1) {
        if (strchr(lines[0], '[')) {
            // vector
            char *token = strtok(lines[0], "[], \n");
            double values[1024];
            int count = 0;
            while (token) {
                values[count++] = atof(token);
                token = strtok(NULL, "[], \n");
            }
            if (type_out) *type_out = "vector";
            return init_vector(values, count);
        } else {
            // point
            double value = atof(lines[0]);
            if (type_out) *type_out = "point";
            return init_point(value);
        }
    } else {
        // matrix
        vector *rows[1024];
        int row_count = 0;
        for (int i = 0; i < line_count; i++) {
            char *token = strtok(lines[i], "[], \n");
            double values[1024];
            int count = 0;
            while (token) {
                values[count++] = atof(token);
                token = strtok(NULL, "[], \n");
            }
            rows[row_count++] = init_vector(values, count);
        }
        int size[2] = { row_count, rows[0]->size };
        if (type_out) *type_out = "matrix";
        return init_matrix(rows, size);
    }
}


void *load(const char *filename, const char *expected_type) {
    char *actual_type = NULL;
    void *obj = load_object_from_file(filename, &actual_type);
    if (!obj) return NULL;
    if (strcmp(actual_type, expected_type) != 0) {
        free(obj);
        return NULL;
    }
    return obj;
}

int add_(void *inp_1, void *inp_2, void *out) {
    int inp_1_type = *((int *)inp_1);
    int inp_2_type = *((int *)inp_2);
    int out_type = *((int *)out);

    if ((inp_1_type==0) & (inp_2_type==0) & (out_type==0)) {
        add_point(inp_1, inp_2, out);
    }
    else if ((inp_1_type==1) & (inp_2_type==1) & (out_type==1)) {
        add_vector(inp_1, inp_2, out);
    }
    else if ((inp_1_type==1) & (inp_2_type==0) & (out_type==1)) {
        add_point_to_vector(inp_1, inp_2, out);
    }
    else if ((inp_1_type==2) & (inp_2_type==2) & (out_type==2)) {
        add_matrix(inp_1, inp_2, out);
    }
    else if ((inp_1_type==2) & (inp_2_type==0) & (out_type==2)) {
        add_point_to_matrix(inp_1, inp_2, out);
    }
    else {
        printf("Operation add_ with \n");
        printf("inp_1:\n");
        print_obj(inp_1);
        printf("and inp_2:\n");
        print_obj(inp_2);
        printf("Is not supported!\n");
    }
    return 0;
}

int diff_(void *inp_1, void *inp_2, void *out) {
    int inp_1_type = *((int *)inp_1);
    int inp_2_type = *((int *)inp_2);
    int out_type = *((int *)out);

    if ((inp_1_type==0) & (inp_2_type==0) & (out_type==0)) {
        diff_point(inp_1, inp_2, out);
    }
    else if ((inp_1_type==1) & (inp_2_type==1) & (out_type==1)) {
        diff_vector(inp_1, inp_2, out);
    }
    else if ((inp_1_type==1) & (inp_2_type==0) & (out_type==1)) {
        diff_point_from_vector(inp_1, inp_2, out);
    }
    else if ((inp_1_type==2) & (inp_2_type==2) & (out_type==2)) {
        diff_matrix(inp_1, inp_2, out);
    }
    else if ((inp_1_type==2) & (inp_2_type==0) & (out_type==2)) {
        diff_point_from_matrix(inp_1, inp_2, out);
    }
    else {
        printf("Operation diff_ with \n");
        printf("inp_1:\n");
        print_obj(inp_1);
        printf("and inp_2:\n");
        print_obj(inp_2);
        printf("Is not supported!\n");
    }
    return 0;
}

int mul_(void *inp_1, void *inp_2, void *out) {
    int inp_1_type = *((int *)inp_1);
    int inp_2_type = *((int *)inp_2);
    int out_type = *((int *)out);

    if ((inp_1_type==0) & (inp_2_type==0) & (out_type==0)) {
        mul_point(inp_1, inp_2, out);
    }
    else if ((inp_1_type==1) & (inp_2_type==1) & (out_type==1)) {
        mul_vector(inp_1, inp_2, out);
    }
    else if ((inp_1_type==1) & (inp_2_type==0) & (out_type==1)) {
        mul_vector_by_point(inp_1, inp_2, out);
    }
    else if ((inp_1_type==2) & (inp_2_type==2) & (out_type==2)) {
        mul_matrix(inp_1, inp_2, out);
    }
    else if ((inp_1_type==2) & (inp_2_type==0) & (out_type==2)) {
        mul_matrix_by_point(inp_1, inp_2, out);
    }
    else {
        printf("Operation mul_ with \n");
        printf("inp_1:\n");
        print_obj(inp_1);
        printf("and inp_2:\n");
        print_obj(inp_2);
        printf("Is not supported!\n");
    }
    return 0;
}

int div_(void *inp_1, void *inp_2, void *out) {
    int inp_1_type = *((int *)inp_1);
    int inp_2_type = *((int *)inp_2);
    int out_type = *((int *)out);

    if ((inp_1_type==0) & (inp_2_type==0) & (out_type==0)) {
        div_point(inp_1, inp_2, out);
    }
    else if ((inp_1_type==1) & (inp_2_type==1) & (out_type==1)) {
        div_vector(inp_1, inp_2, out);
    }
    else if ((inp_1_type==1) & (inp_2_type==0) & (out_type==1)) {
        div_vector_by_point(inp_1, inp_2, out);
    }
    else if ((inp_1_type==2) & (inp_2_type==2) & (out_type==2)) {
        div_matrix(inp_1, inp_2, out);
    }
    else if ((inp_1_type==2) & (inp_2_type==0) & (out_type==2)) {
        div_matrix_by_point(inp_1, inp_2, out);
    }
    else {
        printf("Operation div_ with \n");
        printf("inp_1:\n");
        print_obj(inp_1);
        printf("and inp_2:\n");
        print_obj(inp_2);
        printf("Is not supported!\n");
    }
    return 0;
}

int mat_mul_(void *inp_1, void *inp_2, void *out) {
    int inp_1_type = *((int *)inp_1);
    int inp_2_type = *((int *)inp_2);
    int out_type = *((int *)out);

    if ((inp_1_type==1) & (inp_2_type==1) & (out_type==0)) {
        mat_mul_vector(inp_1, inp_2, out);
    }
    else if ((inp_1_type==2) & (inp_2_type==2) & (out_type==2)) {
        mat_mul_matrix(inp_1, inp_2, out);
    }
    else {
        printf("Operation div_ with \n");
        printf("inp_1:\n");
        print_obj(inp_1);
        printf("and inp_2:\n");
        print_obj(inp_2);
        printf("Is not supported!\n");
    }
    return 0;
}