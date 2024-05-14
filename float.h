#ifndef FLOAT_H
#define FLOAT_H


struct FieldInfo* get_float_fieldInfo();

void float_output(const void* element);
void float_sum_two_elements(const void* element1, const void* element2, void* result);
void float_multiplication_two_elements(const void* element1, const void* element2, void* result);
int float_equality(const void* element1, const void* element2);
void float_scalar_multiplication(const void* element, int scalar, void* result);

#endif