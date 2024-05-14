#include <stdio.h>
#include "Vector.h"
#include "Integer.h"

int main() {

    
    int data1[] = {1, 2, 3};
    int data2[] = {4, 5, 6};
    int expected_sum[] = {5, 7, 9};
    int expected_scalar_mul[] = {2, 4, 6};
    int scalar = 2;

    struct Vector vec1 = init_vector(3, data1, get_int_fieldInfo());
    struct Vector vec2 = init_vector(3, data2, get_int_fieldInfo());

    struct Vector sum_vec = vector_addition(vec1, vec2);
    struct Vector expected_vec = init_vector(3, expected_sum, get_int_fieldInfo());

    struct Vector scalar_mul_vec = vector_scalar_multiplication(vec1, &scalar);
    expected_vec = init_vector(3, expected_scalar_mul, get_int_fieldInfo());

    if (equal_vectors(sum_vec, expected_vec) && equal_vectors(scalar_mul_vec, expected_vec)) {
        return 0;
    } else {
        return 1;
    }

}