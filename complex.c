#include <stdlib.h>
#include "complex.h"
#include "vector.h"
#include <stdio.h>

static struct FieldInfo *COMPLEX_FIELD_INFO = NULL;

struct FieldInfo *get_complex_fieldInfo() {
    if (COMPLEX_FIELD_INFO == NULL) {
        COMPLEX_FIELD_INFO = (struct FieldInfo *) calloc(1, sizeof(struct FieldInfo));
        COMPLEX_FIELD_INFO->element_size = sizeof(ComplexNumber);
        COMPLEX_FIELD_INFO->sum_two_elements = complex_sum_two_elements;
        COMPLEX_FIELD_INFO->multiplication_two_elements = complex_multiplication_two_elements;
        COMPLEX_FIELD_INFO->output = complex_output;
        COMPLEX_FIELD_INFO->equality = complex_equality;
        COMPLEX_FIELD_INFO->scalar_mupltiplication = complex_scalar_multiplication;
    }
    return COMPLEX_FIELD_INFO;
}

void complex_sum_two_elements(const void *element1, const void *element2, void *result) {
    ComplexNumber *z1 = (ComplexNumber *) element1;
    ComplexNumber *z2 = (ComplexNumber *) element2;
    ComplexNumber *z_result = (ComplexNumber *) result;

    z_result->real = z1->real + z2->real;
    z_result->imag = z1->imag + z2->imag;
}

void complex_multiplication_two_elements(const void *element1, const void *element2, void *result) {
    ComplexNumber *z1 = (ComplexNumber *) element1;
    ComplexNumber *z2 = (ComplexNumber *) element2;
    ComplexNumber *z_result = (ComplexNumber *) result;

    z_result->real = z1->real * z2->real - z1->imag * z2->imag;
    z_result->imag = z1->real * z2->imag + z1->imag * z2->real;
}

void complex_output(const void *element) {
    ComplexNumber *z = (ComplexNumber *) element;
    printf("%.2f + %.2fi", z->real, z->imag);
}

int complex_equality(const void *element1, const void *element2) {
    ComplexNumber *z1 = (ComplexNumber *) element1;
    ComplexNumber *z2 = (ComplexNumber *) element2;
    return (z1->real == z2->real) && (z1->imag == z2->imag);
}

void complex_scalar_multiplication(const void *element, int scalar, void *result) {
    ComplexNumber *z = (ComplexNumber *) element;
    ComplexNumber *z_result = (ComplexNumber *) result;
    z_result->real = z->real * scalar;
    z_result->imag = z->imag * scalar;
}

