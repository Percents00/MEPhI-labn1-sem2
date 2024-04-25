#ifndef LABA1_SCALAR_H
#define LABA1_SCALAR_H
#include "complex.h"

typedef union {
    int i;
    float f;
    ComplexNumber c;
} Scalar;

#endif
