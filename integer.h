#ifndef INTEGER_H
#define INTEGER_H


struct FieldInfo* get_int_fieldInfo();

void integer_output(void* element);
void integer_sum_two_elements(void* element1, void* element2, void* result);
void integer_multiplication_two_elements(void* element1, void* element2, void* result);
int integer_equality(void* element1, void* element2);

#endif
