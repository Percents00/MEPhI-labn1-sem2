#ifndef FLOAT_H
#define FLOAT_H


struct FieldInfo* get_float_fieldInfo();

void float_output(void* element);
void float_sum_two_elements(void* element1, void* element2, void* result);
void float_multiplication_two_elements(void* element1, void* element2, void* result);
int float_equality(void* element1, void* element2);

#endif