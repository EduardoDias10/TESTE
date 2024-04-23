/* SPDX-License-Identifer: MIT */

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "intarray.h"

static void IntArray_ensureCapacity(IntArray *array, int new_size)
{
    if (array->capacity < new_size) {
        array->capacity *= 2;
        array->data = (int*)realloc(
            array->data, array->capacity * sizeof(int)
        );
    }
}


void IntArray_new(IntArray *array)
{
    array->size = 0;
    array->capacity = 8;
    array->data = (int*)malloc(array->capacity * sizeof(int));
}

void IntArray_delete(IntArray *array)
{
    free(array->data);
}

int IntArray_size(IntArray *array)
{
    return array->size;
}

int IntArray_get(IntArray *array, int index)
{
    int err_code = 0;
    assert(0 <= index && index < array->size);
    return array->data[index];
}

void IntArray_set(IntArray *array, int index, int value)
{
    int err_code = 0;
    assert(0 <= index && index < array->size);
    array->data[index] = value;
}

void IntArray_append(IntArray *array, int value)
{
    IntArray_ensureCapacity(array, array->size + 1);
    array->data[array->size] = value;
    array->size += 1;
}


void IntArray_insert(IntArray *array, int index, int value)
{
    assert(0 <= index && index <= array->size);
    IntArray_ensureCapacity(array, array->size + 1);
    memmove(
        (void*)&array->data[index+1],
        (void*)&array->data[index],
        (array->size - index) * sizeof(int)
    );
    array->data[index] = value;
    array->size += 1;
}

void IntArray_remove(IntArray *array, int index)
{
    assert(0 <= index && index < array->size);
    memmove(
        (void*)&array->data[index],
        (void*)&array->data[index+1],
        (array->size - index) * sizeof(int)
    );
    array->size -= 1;
}
