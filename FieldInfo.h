#ifndef FIELDINFO_H
#define FIELDINFO_H

struct FieldInfo {
    int element_size;

    void (*sum_two_elements)(const void *element1, const void *element2, void *result);
    void (*multiplication_two_elements)(const void *element1, const void *element2, void *result);
    void (*output)(const void* element);
    int (*equality)(const void* element1, const void* element2);
    void (*scalar_mupltiplication) (const void* element, int scalar, void* result);
};

#endif