/* SPDX-License-Identifer: MIT */

#include <stdio.h>

#include "intarray.h"

void print_array(IntArray* array)
{
    int sz = IntArray_size(array);
    if (sz) {
        printf("%d", IntArray_get(array, 0)); 
        for (int i = 1; i < sz; i++) {
            printf(", %d", IntArray_get(array, i));
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    IntArray array;
    IntArray_new(&array);

    for (int i = 0; i < 10; i++) {
        IntArray_append(&array, i);
    }
    print_array(&array);
    printf("======================\n");
    for (int i = 0; i < 10; i++) {
        IntArray_insert(&array, 0, 10+i);
    }
    print_array(&array);
    printf("======================\n");
    IntArray_remove(&array, 10);
    print_array(&array);
    printf("======================\n");

    IntArray_delete(&array);

    return 0;
}
