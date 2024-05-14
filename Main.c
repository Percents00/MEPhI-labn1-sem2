#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"
#include "Integer.h"
#include "Float.h"
#include "Complex.h"


void main() {
    int key = 0;
    int test_result = system("Tests.c");

    if (test_result == 0) {
        printf("Tests passed\n");
        key = 1;
    } else {
        printf("Tests failed\n");
    }

    if (key == 1) {
        
    
        while (1) {
            
            printf("Choose the data type: \n1. Integer\n2. Float\n3. Complex\n");
            int type;
            scanf("%d", &type);

            printf("Choose the operation: \n1. Vector addition\n2. Scalar multiplication\n");
            int operation;
            scanf("%d", &operation);

            switch(type) {
                case 1:
                    switch(operation) {
                        case 1:
                            printf("Enter vector1 size: \n");
                            int size1;
                            scanf("%d", &size1);
                            printf("Enter vector1 elements: \n");
                            int data1[50];
                            for (int i = 0; i < size1; i++) {
                                scanf("%d", &data1[i]);
                            }

                            printf("Enter vector2 size: \n");
                            int size2;
                            scanf("%d", &size2);
                            if (size1 != size2) {
                                printf("Vector sizes are different");
                                exit(1);
                            }

                            printf("Enter vector2 elements: \n");
                            int data2[50];
                            for (int i = 0; i < size2; i++) {
                                scanf("%d", &data2[i]);
                            }

                            struct Vector vec1 = init_vector(size1, data1, get_int_fieldInfo());
                            struct Vector vec2 = init_vector(size2, data2, get_int_fieldInfo());
                            struct Vector res_vec1 = vector_addition(vec1, vec2);

                            print_vector(res_vec1);
                            break;
                        case 2:
                            printf("Enter vector size: \n");
                            int size;
                            scanf("%d", &size);
                            printf("Enter vector elements: \n");
                            int data[50];
                            for (int i = 0; i < size; i++) {
                                scanf("%d", &data[i]);
                            }
                            struct Vector vec = init_vector(size, data, get_int_fieldInfo());

                            printf("Enter scalar: \n");
                            int scalar;
                            scanf("%d", &scalar);
                            struct Vector res_vec2 = vector_scalar_multiplication(vec, &scalar);
                            print_vector(res_vec2);
                            break;
                        default:
                            printf("Wrong operation");
                            break;
                    }
                    break;

                case 2:
                    switch(operation) {
                        case 1:
                            printf("Enter vector1 size: \n");
                            int size1;
                            scanf("%d", &size1);
                            printf("Enter vector1 elements: \n");
                            int data1[50];
                            for (int i = 0; i < size1; i++) {
                                scanf("%f", &data1[i]);
                            }

                            printf("Enter vector2 size: \n");
                            int size2;
                            scanf("%d", &size2);
                            if (size1 != size2) {
                                printf("Vector sizes are different");
                                exit(1);
                            }

                            printf("Enter vector2 elements: \n");
                            int data2[50];
                            for (int i = 0; i < size2; i++) {
                                scanf("%f", &data2[i]);
                            }

                            struct Vector vec1 = init_vector(size1, data1, get_float_fieldInfo());
                            struct Vector vec2 = init_vector(size2, data2, get_float_fieldInfo());
                            struct Vector res_vec1 = vector_addition(vec1, vec2);

                            print_vector(res_vec1);
                            break;
                        case 2:
                            printf("Enter vector size: \n");
                            int size;
                            scanf("%d", &size);
                            printf("Enter vector elements: \n");
                            int data[50];
                            for (int i = 0; i < size; i++) {
                                scanf("%f", &data[i]);
                            }
                            struct Vector vec = init_vector(size, data, get_float_fieldInfo());

                            printf("Enter scalar: \n");
                            int scalar;
                            scanf("%d", &scalar);
                            struct Vector res_vec2 = vector_scalar_multiplication(vec, &scalar);
                            print_vector(res_vec2);
                            break;
                        default:
                            printf("Wrong operation");
                            break;
                    }
                    break;

                case 3:
                    switch(operation) {
                        case 1:
                            printf("Enter vector1 size: \n");
                            int size1;
                            scanf("%d", &size1);
                            printf("Enter vector1 elements: \n");
                            ComplexNumber data1[50];
                            for (int i = 0; i < size1; i++) {
                                printf("Enter real part: ");
                                scanf("%f", &data1[i].real);
                                printf("Enter imaginary part: ");
                                scanf("%f", &data1[i].imag);
                            }

                            printf("Enter vector2 size: \n");
                            int size2;
                            scanf("%d", &size2);
                            if (size1 != size2) {
                                printf("Vector sizes are different");
                                exit(1);
                            }

                            printf("Enter vector2 elements: \n");
                            ComplexNumber data2[50];
                            for (int i = 0; i < size2; i++) {
                                printf("Enter real part: ");
                                scanf("%f", &data2[i].real);
                                printf("Enter imaginary part: ");
                                scanf("%f", &data2[i].imag);
                            }

                            struct Vector vec1 = init_vector(size1, data1, get_complex_fieldInfo());
                            struct Vector vec2 = init_vector(size2, data2, get_complex_fieldInfo());
                            struct Vector res_vec1 = vector_addition(vec1, vec2);

                            print_vector(res_vec1);
                            break;
                        case 2:
                            printf("Enter vector size: \n");
                            int size;
                            scanf("%d", &size);
                            printf("Enter vector elements: \n");
                            ComplexNumber data[50];
                            for (int i = 0; i < size; i++) {
                                printf("Enter real part: ");
                                scanf("%f", &data[i].real);
                                printf("Enter imaginary part: ");
                                scanf("%f", &data[i].imag);
                            }
                            struct Vector vec = init_vector(size, data, get_complex_fieldInfo());

                            printf("Enter scalar: \n");
                            int scalar;
                            scanf("%d", &scalar);
                            struct Vector res_vec2 = vector_scalar_multiplication(vec, &scalar);
                            print_vector(res_vec2);
                            break;

                    }
                    break;

                default:
                    printf("Wrong operation");
                    break;
            }
            break;
        }
    }
}