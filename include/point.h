#ifndef POINT_H
#define POINT_H

typedef struct point {
    int type;
    double value;
} point;

point *init_point(double value);
point *init_zero_point();
point *init_one_point();
int free_point(point *point);
int print_point(point *point);

int add_point(point *point_1, point *point_2, point *out);
int diff_point(point *point_1, point *point_2, point *out);
int mul_point(point *point_1, point *point_2, point *out);
int div_point(point *point_1, point *point_2, point *out);

#endif
