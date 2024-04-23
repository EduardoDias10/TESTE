/* SPDX-License-Identifer: MIT */

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "genarray.h"

static void GenericArray_ensureCapacity(GenericArray *array, int new_size)
{
    if (array->capacity < new_size) {
        array->capacity *= 2;
        array->data = realloc(
            array->data, array->capacity * array->elem_size
        );
    }
}


void GenericArray_new(GenericArray *array, int elem_size)
{
    array->size = 0;
    array->capacity = 8;
    array->elem_size = elem_size;
    array->data = malloc(array->capacity * array->elem_size);
}

void GenericArray_delete(GenericArray *array)
{
    free(array->data);
}

int GenericArray_size(GenericArray *array)
{
    return array->size;
}

void GenericArray_append(GenericArray *array, void* value)
{
    GenericArray_ensureCapacity(array, array->size + 1);
    void* elem_addr = (char*)array->data + array->size * array->elem_size;
    memcpy(elem_addr, value, array->elem_size);
    array->size += 1;
}

void GenericArray_get(GenericArray *array, int index, void *elem)
{
    assert(0 <= index && index < array->size);
    void *elem_addr = (char*)array->data + index * array->elem_size;
    memcpy(elem, elem_addr, array->elem_size);
}

void GenericArray_set(GenericArray* array, int n, void *d)
{
	assert(n >= 0 || n < GenericArray_size(array));
	void *elem_addr = (char*)array->data + n * array->elem_size;
	memcpy(elem_addr, d, array->elem_size);
}

