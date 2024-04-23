/* SPDX-License-Identifer: MIT */

#ifndef PARADIGMAS_INTARRAY_H_
#define PARADIGMAS_INTARRAY_H_

typedef struct {
    int size;
    int capacity;
    int* data;
} IntArray;


void IntArray_new(IntArray *array);
void IntArray_delete(IntArray *array);

int IntArray_size(IntArray *array);
int IntArray_get(IntArray *array, int index);
void IntArray_set(IntArray *array, int index, int value);
void IntArray_append(IntArray *array, int value);
void IntArray_insert(IntArray *array, int index, int value);
void IntArray_remove(IntArray *array, int index);

#endif  /* PARADIGMAS_INTARRAY_H_ */
