#ifndef POINT_H
#define POINT_H

typedef struct POINT {
    int type;
    double value;
} POINT;

POINT *init_point(double value);
POINT *init_zero_point();
POINT *init_one_point();
int free_point(POINT *point);
int print_point(POINT *point);

int add_point(POINT *point_1, POINT *point_2, POINT *out);
int diff_point(POINT *point_1, POINT *point_2, POINT *out);
int mul_point(POINT *point_1, POINT *point_2, POINT *out);
int div_point(POINT *point_1, POINT *point_2, POINT *out);

#endif
