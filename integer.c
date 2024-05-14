#include <stdio.h>
#include <stdlib.h>
#include "integer.h"
#include "Vector.h"

static struct FieldInfo *INT_FIELD_INFO = NULL;

struct FieldInfo *get_int_fieldInfo() {
    if (INT_FIELD_INFO == NULL) {
        INT_FIELD_INFO = (struct FieldInfo *) calloc(1, sizeof(struct FieldInfo));
        INT_FIELD_INFO->element_size = sizeof(int);
        INT_FIELD_INFO->sum_two_elements = integer_sum_two_elements;
        INT_FIELD_INFO->multiplication_two_elements = integer_multiplication_two_elements;
        INT_FIELD_INFO->output = integer_output;
        INT_FIELD_INFO->equality = integer_equality;
        INT_FIELD_INFO->scalar_mupltiplication = integer_scalar_multiplication;
    }
    return INT_FIELD_INFO;
}

void integer_sum_two_elements(const void *element1, const void *element2, void *result) {
    *(int *) result = *(int *) element1 + *(int *) element2;
}

void integer_multiplication_two_elements(const void *element1, const void *element2, void *result) {
    *(int *) result = *(int *) element1 * *(int *) element2;
}

void integer_output(const void *element) {
    const int a = *(const int *) element;
    printf("%d", a);
}

int integer_equality(const void *element1, const void *element2) {
    return *(int *) element1 == *(int *) element2;
}

void integer_scalar_multiplication(const void *element, int scalar, void *result) {
    *(int *) result = *(int *) element * scalar;
}


