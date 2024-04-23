/* SPDX-License-Identifer: MIT */

#ifndef PARADIGMAS_GENARRAY_H_
#define PARADIGMAS_GENARRAY_H_

typedef struct {
    int size;
    int capacity;
    int elem_size;
    void* data;
} GenericArray;


void GenericArray_new(GenericArray *array, int elem_size);
void GenericArray_delete(GenericArray *array);

int GenericArray_size(GenericArray *array);

void GenericArray_append(GenericArray *array, void* value);
void GenericArray_get(GenericArray *array, int index, void *elem);


void GenericArray_set(GenericArray *array, int index, void* value);
void GenericArray_insert(GenericArray *array, int index, void* value);
void GenericArray_remove(GenericArray *array, int index);

#endif  /* PARADIGMAS_INTARRAY_H_ */
