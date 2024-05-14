#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct{
    float real;
    float imag;
} ComplexNumber;

struct FieldInfo* get_complex_fieldInfo();

void complex_output(const void* element);
void complex_sum_two_elements(const void* element1, const void* element2, void* result);
void complex_multiplication_two_elements(const void* element1, const void* element2, void* result);
int complex_equality(const void* element1, const void* element2);
void complex_scalar_multiplication(const void* element, int scalar, void* result);

#endif