#ifndef LABA1_FIELDINFO_H
#define LABA1_FIELDINFO_H

struct FieldInfo {
    int element_size;

    void (*sum_two_elements)(void *element1, void *element2, void *result);
    void (*multiplication_two_elements)(void *element1, void *element2, void *result);
    void (*output)(void* result);
    int (*equality)(void* element1, void* element2);
};

#endif