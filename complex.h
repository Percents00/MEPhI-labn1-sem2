#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct{
    float real;
    float imag;
} ComplexNumber;

struct FieldInfo* get_complex_fieldInfo();

void complex_output(void* element);
void complex_sum_two_elements(void* element1, void* element2, void* result);
void complex_multiplication_two_elements(void* element1, void* element2, void* result);
int complex_equality(void* element1, void* element2);

#endif