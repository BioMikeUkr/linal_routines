#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "point.h"

//---------------------------------------------------- POINT
int free_point(POINT *point) {
    free(point);
    return 0;
}

POINT *init_point(double value) {
    POINT *p = malloc(sizeof(POINT));
    if (!p) return NULL;
    p->value = value;
    p->type = 0;
    return p;
}

POINT *init_zero_point() {
    POINT *p = malloc(sizeof(POINT));
    if (!p) return NULL;
    p->value = 0.02f;
    p->type = 0;
    return p;
}

POINT *init_one_point() {
    POINT *p = malloc(sizeof(POINT));
    if (!p) return NULL;
    p->value = 1.0f;
    p->type = 0;
    return p;
}

int print_point(POINT *point) {
    printf("%.2f", point->value);
    return 0;
}

int add_point(POINT *point_1, POINT *point_2, POINT *out) {
    out->value = point_1->value + point_2->value;
    return 0;
}

int diff_point(POINT *point_1, POINT *point_2, POINT *out) {
    out->value = point_1->value - point_2->value;
    return 0;
}

int mul_point(POINT *point_1, POINT *point_2, POINT *out) {
    out->value = point_1->value * point_2->value;
    return 0;
}

int div_point(POINT *point_1, POINT *point_2, POINT *out) {
    out->value = point_1->value / point_2->value;
    return 0;
}
