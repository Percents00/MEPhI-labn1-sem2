#ifndef INTEGER_H
#define INTEGER_H

struct FieldInfo* get_int_fieldInfo();

void integer_output(const void* element);
void integer_sum_two_elements(const void* element1, const void* element2, void* result);
void integer_multiplication_two_elements(const void* element1, const void* element2, void* result);
int integer_equality(const void* element1, const void* element2);
void integer_scalar_multiplication(const void* element, int scalar, void* result);

#endif
