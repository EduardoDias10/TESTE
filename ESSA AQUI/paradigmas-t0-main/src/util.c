/* SPDX-License-Identifer: MIT */

#include <string.h>

void swap(void *a, void *b, int size)
{
    char buffer[size];
    memcpy(buffer, a, size);
    memcpy(a, b, size);
    memcpy(b, buffer, size);
}

void* linear_search(
    void *key,
    void *base, int n,
    int elem_sz,
    int (*cmpfn)(void*, void*)
) {
    for (int i = 0; i < n; i++) {
        void *elem_address = (char*)base + i*elem_sz;
        if (cmpfn(key, elem_address) == 0) {
            return elem_address;
        }
    }
    return NULL;
}

