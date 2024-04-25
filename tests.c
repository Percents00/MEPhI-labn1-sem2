#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <assert.h>
#include <string.h>

#include "vector.h"
#include "FieldInfo.h"
#include "integer.h"
#include "complex.h"
#include "float.h"
#include "scalar.h"


void test_int_sum1() {
    int data1[] = {1, 2, 3};
    int data2[] = {4, 5, 6};
    int expected[] = {5, 7, 9};
    struct Vector vec1 = init_vector(3, data1, get_int_fieldInfo());
    struct Vector vec2 = init_vector(3, data2, get_int_fieldInfo());
    struct Vector result = vector_addition(vec1, vec2);
    struct Vector expected_vec = init_vector(3, expected, get_int_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 1.1 passed\n");
    } else {
        printf("Test 1.1 failed\n");
    }
    destroy_vector(&vec1);
    destroy_vector(&vec2);
    destroy_vector(&result);
    destroy_vector(&expected_vec);

}

void test_int_sum2() {
    int data1[] = {0, 0, 0};
    int data2[] = {4, 5, 6};
    int expected[] = {4, 5, 6};
    struct Vector vec1 = init_vector(3, data1, get_int_fieldInfo());
    struct Vector vec2 = init_vector(3, data2, get_int_fieldInfo());
    struct Vector result = vector_addition(vec1, vec2);
    struct Vector expected_vec = init_vector(3, expected, get_int_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 1.2 passed\n");
    } else {
        printf("Test 1.2 failed\n");
    }
    destroy_vector(&vec1);
    destroy_vector(&vec2);
    destroy_vector(&result);
    destroy_vector(&expected_vec);

}

void test_int_sum3() {
    int data1[] = {-1, 2, -3};
    int data2[] = {4, -5, 6};
    int expected[] = {3, -3, 3};
    struct Vector vec1 = init_vector(3, data1, get_int_fieldInfo());
    struct Vector vec2 = init_vector(3, data2, get_int_fieldInfo());
    struct Vector result = vector_addition(vec1, vec2);
    struct Vector expected_vec = init_vector(3, expected, get_int_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 1.3 passed\n");
    } else {
        printf("Test 1.3 failed\n");
    }
    destroy_vector(&vec1);
    destroy_vector(&vec2);
    destroy_vector(&result);
    destroy_vector(&expected_vec);

}

void test_float_sum1() {
    float data1[] = {1.1f, 2.2f, 3.3f};
    float data2[] = {4.4f, 5.5f, 6.6f};
    float expected[] = {5.5f, 7.7f, 9.9f};
    struct Vector vec1 = init_vector(3, data1, get_float_fieldInfo());
    struct Vector vec2 = init_vector(3, data2, get_float_fieldInfo());
    struct Vector result = vector_addition(vec1, vec2);
    struct Vector expected_vec = init_vector(3, expected, get_float_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 2.1 passed\n");
    } else {
        printf("Test 2.1 failed\n");
    }
    destroy_vector(&vec1);
    destroy_vector(&vec2);
    destroy_vector(&result);
    destroy_vector(&expected_vec);
}

void test_float_sum2() {
    float data1[] = {1.1f, 2.2f, 3.3f};
    float data2[] = {4.9f, 5.0f, 6.0f};
    float expected[] = {6.0f, 7.2f, 9.3f};
    struct Vector vec1 = init_vector(3, data1, get_float_fieldInfo());
    struct Vector vec2 = init_vector(3, data2, get_float_fieldInfo());
    struct Vector result = vector_addition(vec1, vec2);
    struct Vector expected_vec = init_vector(3, expected, get_float_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 2.2 passed\n");
    } else {
        printf("Test 2.2 failed\n");
    }
    destroy_vector(&vec1);
    destroy_vector(&vec2);
    destroy_vector(&result);
    destroy_vector(&expected_vec);
}

void test_float_sum3() {
    float data1[] = {1.1f, 2.2f, 3.3f};
    float data2[] = {-1.1f, -2.2f, -3.3f};
    float expected[] = {0.0f, 0.0f, 0.0f};
    struct Vector vec1 = init_vector(3, data1, get_float_fieldInfo());
    struct Vector vec2 = init_vector(3, data2, get_float_fieldInfo());
    struct Vector result = vector_addition(vec1, vec2);
    struct Vector expected_vec = init_vector(3, expected, get_float_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 2.3 passed\n");
    } else {
        printf("Test 2.3 failed\n");
    }
    destroy_vector(&vec1);
    destroy_vector(&vec2);
    destroy_vector(&result);
    destroy_vector(&expected_vec);
}

void test_comp_sum1() {
    ComplexNumber data1[] = {{1, 2}, {3, -4}};
    ComplexNumber data2[] = {{5, -1}, {-2, 6}};
    ComplexNumber expected[] = {{6, 1}, {1, 2}};
    struct Vector vec1 = init_vector(2, data1, get_complex_fieldInfo());
    struct Vector vec2 = init_vector(2, data2, get_complex_fieldInfo());
    struct Vector result = vector_addition(vec1, vec2);
    struct Vector expected_vec = init_vector(2, expected, get_complex_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 3.1 passed\n");
    } else {
        printf("Test 3.1 failed\n");
    }
    destroy_vector(&vec1);
    destroy_vector(&vec2);
    destroy_vector(&result);
    destroy_vector(&expected_vec);
}

void test_comp_sum2() {
    ComplexNumber data1[] = {{0, 2}, {3, 0}};
    ComplexNumber data2[] = {{5, 0}, {0, 6}};
    ComplexNumber expected[] = {{5, 2}, {3, 6}};
    struct Vector vec1 = init_vector(2, data1, get_complex_fieldInfo());
    struct Vector vec2 = init_vector(2, data2, get_complex_fieldInfo());
    struct Vector result = vector_addition(vec1, vec2);
    struct Vector expected_vec = init_vector(2, expected, get_complex_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 3.2 passed\n");
    } else {
        printf("Test 3.2 failed\n");
    }
    destroy_vector(&vec1);
    destroy_vector(&vec2);
    destroy_vector(&result);
    destroy_vector(&expected_vec);
}

void test_comp_sum3() {
    ComplexNumber data1[] = {{-1, 2}, {3, -4}};
    ComplexNumber data2[] = {{5, -1}, {-2, -6}};
    ComplexNumber expected[] = {{4, 1}, {1, -10}};
    struct Vector vec1 = init_vector(2, data1, get_complex_fieldInfo());
    struct Vector vec2 = init_vector(2, data2, get_complex_fieldInfo());
    struct Vector result = vector_addition(vec1, vec2);
    struct Vector expected_vec = init_vector(2, expected, get_complex_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 3.3 passed\n");
    } else {
        printf("Test 3.3 failed\n");
    }
    destroy_vector(&vec1);
    destroy_vector(&vec2);
    destroy_vector(&result);
    destroy_vector(&expected_vec);
}

void test_int_scal1() {
    int data[] = {2, 4, 6};
    int expected[] = {10, 20, 30};
    Scalar scalar;
    scalar.i = 5;
    struct Vector vec = init_vector(3, data, get_int_fieldInfo());
    struct Vector result = vector_scalar_multiplication(vec, scalar);
    struct Vector expected_vec = init_vector(3, expected, get_int_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 4.1 passed\n");
    } else {
        printf("Test 4.1 failed\n");
    }
    destroy_vector(&vec);
    destroy_vector(&result);
    destroy_vector(&expected_vec);
}

void test_int_scal2() {
    int data[] = {2, 4, 6};
    int expected[] = {0, 0, 0};
    Scalar scalar;
    scalar.i = 0;
    struct Vector vec = init_vector(3, data, get_int_fieldInfo());
    struct Vector result = vector_scalar_multiplication(vec, scalar);
    struct Vector expected_vec = init_vector(3, expected, get_int_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 4.2 passed\n");
    } else {
        printf("Test 4.2 failed\n");
    }
    destroy_vector(&vec);
    destroy_vector(&result);
    destroy_vector(&expected_vec);
}

void test_int_scal3() {
    int data[] = {2, 4, 6};
    int expected[] = {-2, -4, -6};
    Scalar scalar;
    scalar.i = -1;
    struct Vector vec = init_vector(3, data, get_int_fieldInfo());
    struct Vector result = vector_scalar_multiplication(vec, scalar);
    struct Vector expected_vec = init_vector(3, expected, get_int_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 4.3 passed\n");
    } else {
        printf("Test 4.3 failed\n");
    }
    destroy_vector(&vec);
    destroy_vector(&result);
    destroy_vector(&expected_vec);
}

void test_float_scal1() {
    float data[] = {2.1f, 4.1f, 6.1f};
    float expected[] = {4.2f, 8.2f, 12.2f};
    Scalar scalar;
    scalar.f = 2.0f;
    struct Vector vec = init_vector(3, data, get_float_fieldInfo());
    struct Vector result = vector_scalar_multiplication(vec, scalar);
    struct Vector expected_vec = init_vector(3, expected, get_float_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 5.1 passed\n");
    } else {
        printf("Test 5.1 failed\n");
    }
    destroy_vector(&vec);
    destroy_vector(&result);
    destroy_vector(&expected_vec);
}

void test_float_scal2() {
    float data[] = {2.1f, 4.1f, 6.1f};
    float expected[] = {0.0f, 0.0f, 0.0f};
    Scalar scalar;
    scalar.f = 0.0f;
    struct Vector vec = init_vector(3, data, get_float_fieldInfo());
    struct Vector result = vector_scalar_multiplication(vec, scalar);
    struct Vector expected_vec = init_vector(3, expected, get_float_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 5.2 passed\n");
    } else {
        printf("Test 5.2 failed\n");
    }
    destroy_vector(&vec);
    destroy_vector(&result);
    destroy_vector(&expected_vec);
}

void test_float_scal3() {
    float data[] = {2.0f, 2.0f, 2.0f};
    float expected[] = {-5.0f, -5.0f, -5.0f};
    Scalar scalar;
    scalar.f = -2.5f;
    struct Vector vec = init_vector(3, data, get_float_fieldInfo());
    struct Vector result = vector_scalar_multiplication(vec, scalar);
    struct Vector expected_vec = init_vector(3, expected, get_float_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 5.3 passed\n");
    } else {
        printf("Test 5.3 failed\n");
    }
    destroy_vector(&vec);
    destroy_vector(&result);
    destroy_vector(&expected_vec);
}

void test_comp_scal1() {
    ComplexNumber data[] = {{1, 2}, {3, -4}};
    ComplexNumber expected[] = {{2, 4}, {6, -8}};
    Scalar scalar;
    scalar.c.real = 2;
    scalar.c.imag = 0;
    struct Vector vec = init_vector(2, data, get_complex_fieldInfo());
    struct Vector result = vector_scalar_multiplication(vec, scalar);
    struct Vector expected_vec = init_vector(2, expected, get_complex_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 6.1 passed\n");
    } else {
        printf("Test 6.1 failed\n");
    }
    destroy_vector(&vec);
    destroy_vector(&result);
    destroy_vector(&expected_vec);
}

void test_comp_scal2() {
    ComplexNumber data[] = {{1, 2}, {3, -4}};
    ComplexNumber expected[] = {{0, 0}, {0, 0}};
    Scalar scalar;
    scalar.c.real = 0;
    scalar.c.imag = 0;
    struct Vector vec = init_vector(2, data, get_complex_fieldInfo());
    struct Vector result = vector_scalar_multiplication(vec, scalar);
    struct Vector expected_vec = init_vector(2, expected, get_complex_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 6.2 passed\n");
    } else {
        printf("Test 6.2 failed\n");
    }
    destroy_vector(&vec);
    destroy_vector(&result);
    destroy_vector(&expected_vec);
}

void test_comp_scal3() {
    ComplexNumber data[] = {{1, 2}, {3, -4}};
    ComplexNumber expected[] = {{1, 12}, {23, -14}};
    Scalar scalar;
    scalar.c.real = 5;
    scalar.c.imag = 2;
    struct Vector vec = init_vector(2, data, get_complex_fieldInfo());
    struct Vector result = vector_scalar_multiplication(vec, scalar);
    struct Vector expected_vec = init_vector(2, expected, get_complex_fieldInfo());
    if (equal_vectors(result, expected_vec)) {
        printf("Test 6.3 passed\n");
    } else {
        printf("Test 6.3 failed\n");
    }
    destroy_vector(&vec);
    destroy_vector(&result);
    destroy_vector(&expected_vec);

}

int main() {
    test_int_sum1();
    test_int_sum2();
    test_int_sum3();

    printf("\n");

    test_float_sum1();
    test_float_sum2();
    test_float_sum3();

    printf("\n");

    test_comp_sum1();
    test_comp_sum2();
    test_comp_sum3();

    printf("\n");

    test_int_scal1();
    test_int_scal2();
    test_int_scal3();

    printf("\n");

    test_float_scal1();
    test_float_scal2();
    test_float_scal3();

    printf("\n");

    test_comp_scal1();
    test_comp_scal2();
    test_comp_scal3();

    printf("\n");

    return 0;
}