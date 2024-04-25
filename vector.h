#ifndef LABA1_VECTOR_H
#define LABA1_VECTOR_H
#include "FieldInfo.h"
#include "scalar.h"


struct Vector {
    const struct FieldInfo *fieldInfo;
    int size;
    void *data;
};
struct Vector init_vector(int size, void* data, const struct FieldInfo* fieldInfo);
struct Vector vector_addition(struct Vector vec1, struct Vector vec2);
struct Vector vector_scalar_multiplication(struct Vector vec, Scalar scalar);
int equal_vectors(struct Vector vec1, struct Vector vec2);
void print_vector(struct Vector vec);
void destroy_vector(struct Vector *vec);
#endif