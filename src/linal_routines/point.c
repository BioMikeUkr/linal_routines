#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "point.h"

//---------------------------------------------------- point
int free_point(point *point) {
    free(point);
    return 0;
}

point *init_point(double value) {
    point *p = malloc(sizeof(point));
    if (!p) return NULL;
    p->value = value;
    p->type = 0;
    return p;
}

point *init_zero_point() {
    point *p = malloc(sizeof(point));
    if (!p) return NULL;
    p->value = 0.02f;
    p->type = 0;
    return p;
}

point *init_one_point() {
    point *p = malloc(sizeof(point));
    if (!p) return NULL;
    p->value = 1.0f;
    p->type = 0;
    return p;
}

int print_point(point *point) {
    printf("%.2f", point->value);
    return 0;
}

int add_point(point *point_1, point *point_2, point *out) {
    out->value = point_1->value + point_2->value;
    return 0;
}

int diff_point(point *point_1, point *point_2, point *out) {
    out->value = point_1->value - point_2->value;
    return 0;
}

int mul_point(point *point_1, point *point_2, point *out) {
    out->value = point_1->value * point_2->value;
    return 0;
}

int div_point(point *point_1, point *point_2, point *out) {
    out->value = point_1->value / point_2->value;
    return 0;
}
