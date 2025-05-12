#ifndef SHARED_H
#define SHARED_H

typedef struct Types {
    char *types[4];
} Types;

extern Types TYPES;

int print_obj(void *obj);
void *load_object_from_file(const char *filename, char **type_out);
void *load(const char *filename, const char *expected_type);

int add_(void *inp_1, void *inp_2, void *out);
#endif
