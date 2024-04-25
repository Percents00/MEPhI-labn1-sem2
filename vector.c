#include <stdlib.h>
#include <stdio.h>
#include "Vector.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "scalar.h"

struct Vector init_vector(int size, void *data, const struct FieldInfo *fieldInfo) {
    assert(size > 0 && fieldInfo != NULL);
    struct Vector vec;
    vec.size = size;
    vec.fieldInfo = fieldInfo;
    if (data != NULL) {
        vec.data = malloc(size * fieldInfo->element_size);
        assert(vec.data != NULL);
        memcpy(vec.data, data, size * fieldInfo->element_size);
    } else {
        vec.data = NULL;}
    return vec;
}

void destroy_vector(struct Vector *vec) {
    if (vec != NULL && vec->data != NULL) {
        free(vec->data);
        vec->data = NULL;
        vec->size = 0;
    }
}

void print_vector(struct Vector vec) {
    if (vec.size == 0) {
        printf("Vector is empty\n");
        return;}
    for (int i = 0; i < vec.size; i++) {
        void* element_pointer = (char*)vec.data + i * vec.fieldInfo->element_size;
        vec.fieldInfo->output(element_pointer);
        if (i < vec.size - 1) {
            printf(" ");}
    }
}

struct Vector vector_scalar_multiplication(struct Vector vec, Scalar scalar) {
    if (vec.size == 0) {
        return vec;
    }

    struct Vector result_vec = {
            .fieldInfo = vec.fieldInfo,
            .size = vec.size,
            .data = malloc(vec.size * vec.fieldInfo->element_size)
    };

    if (result_vec.data == NULL) {
        fprintf(stderr, "Mem error!\n");
        exit(1);
    }

    for (int i = 0; i < vec.size; i++) {
        void *element_pointer = (char *) vec.data + i * vec.fieldInfo->element_size;
        void *result_vec_pointer = (char *) result_vec.data + i * vec.fieldInfo->element_size;

        if (scalar.i) {
            vec.fieldInfo->multiplication_two_elements(element_pointer, &scalar.i, result_vec_pointer);
        } else if (scalar.f != 0) {
            vec.fieldInfo->multiplication_two_elements(element_pointer, &scalar.f, result_vec_pointer);
        } else {
            ComplexNumber *c_pointer = &scalar.c;
            vec.fieldInfo->multiplication_two_elements(element_pointer, c_pointer, result_vec_pointer);
        }
    }

    return result_vec;
}

struct Vector vector_addition(struct Vector vec1, struct Vector vec2) {
    if (vec1.size != vec2.size) {
        printf("Different vector' sizes");
        exit(1);}
    if (vec1.size == 0 && vec2.size != 0) {
        return vec2;}
    if (vec1.size != 0 && vec2.size == 0) {
        return vec1;}
    struct Vector result_vec = {
            .fieldInfo = vec1.fieldInfo,
            .size = vec1.size,
            .data = malloc(vec1.size * vec1.fieldInfo->element_size)};
    if (result_vec.data == NULL) {
        fprintf(stderr, "Mem error!");
        exit(1);}
    for (int i = 0; i < vec1.size; i++) {
        void *element1_ptr = (char *) vec1.data + i * vec1.fieldInfo->element_size;
        void *element2_ptr = (char *) vec2.data + i * vec2.fieldInfo->element_size;
        void *result_ptr = (char *) result_vec.data + i * result_vec.fieldInfo->element_size;
        vec1.fieldInfo->sum_two_elements(element1_ptr, element2_ptr, result_ptr);}
    return result_vec;
}

int equal_vectors(struct Vector vec1, struct Vector vec2) {
    if (vec1.size != vec2.size) return 0;

    for (int i = 0; i < vec1.size; i++) {
        void *element1_pointer = (char *)vec1.data + i * vec1.fieldInfo->element_size;
        void *element2_pointer = (char *)vec2.data + i * vec2.fieldInfo->element_size;

        if (!vec1.fieldInfo->equality(element1_pointer, element2_pointer)) return 0;
    }

    return 1;
}