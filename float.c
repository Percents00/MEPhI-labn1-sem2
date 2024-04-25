#include <stdio.h>
#include <stdlib.h>
#include "float.h"
#include "Vector.h"

static struct FieldInfo *FLOAT_FIELD_INFO = NULL;

struct FieldInfo *get_float_fieldInfo() {
    if (FLOAT_FIELD_INFO == NULL) {
        FLOAT_FIELD_INFO = (struct FieldInfo *) calloc(1, sizeof(struct FieldInfo));
        FLOAT_FIELD_INFO->element_size = sizeof(float);
        FLOAT_FIELD_INFO->sum_two_elements = float_sum_two_elements;
        FLOAT_FIELD_INFO->multiplication_two_elements = float_multiplication_two_elements;
        FLOAT_FIELD_INFO->output = float_output;
        FLOAT_FIELD_INFO->equality = float_equality;
    }
    return FLOAT_FIELD_INFO;
}



void float_sum_two_elements(void *element1, void *element2, void *result) {
    *(float *) result = *(float *) element1 + *(float *) element2;
}

void float_multiplication_two_elements(void *element1, void *element2, void *result) {
    *(float *) result = *(float *) element1 * *(float *) element2;
}

void float_output(void *element) {
    printf("%f", *(float *) element);
}

int float_equality(void *element1, void *element2) {
    return *(float *) element1 == *(float *) element2;
}

