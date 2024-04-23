/* SPDX-License-Identifer: MIT */

#include <stdio.h>
#include <string.h>

#include "util.h"


int int_cmp(void *lhs, void *rhs)
{
   return *(int*)lhs - *(int*)rhs; 
}

void test_int()
{
    int array[] = { 3, 4, 1, 8, 9, 5, 7, 4, 0, 2 };
    int size = 10;
    int needle = 7;

    int *found = linear_search(&needle, array, size, sizeof(int), int_cmp);
    printf("%sFound!\n", (found)? "" : "Not ");
    
    needle = -100;
    found = linear_search(&needle, array, size, sizeof(int), int_cmp);
    printf("%sFound!\n", (found)? "" : "Not ");
}

int double_cmp(void *lhs, void *rhs)
{
    double v1 = *(double*)lhs;
    double v2 = *(double*)rhs;
    if (v1 == v2) {
        return 0;
    } else {
        return (v1 < v2) ? -1 : 1;
    }
}

void test_double()
{
    double array[] = { 3.1, 4.2, 1.3, 8.4, 9.5, 5.6, 7.7, 4.8, 0.9, 2.01 };
    int size = 10;
    double needle = 5.6;

    int *found = linear_search(&needle, array, size, sizeof(double), double_cmp);
    printf("%sFound!\n", (found)? "" : "Not ");
    
    needle = 3.1415;
    found = linear_search(&needle, array, size, sizeof(double), double_cmp);
    printf("%sFound!\n", (found)? "" : "Not ");
}

int string_cmp(void *lhs, void *rhs)
{
    char *s1 = *(char**)lhs;
    char *s2 = *(char**)rhs;
    return strcmp(s1, s2);
}

void test_string()
{
    char *names[] = {"Ana", "Maria", "João", "André", "Rafael", "Sandra"};
    int size = 6;
    char *needle = "Rafael";
    
    int *found = linear_search(&needle, names, size, sizeof(char**), string_cmp);
    printf("%sFound!\n", (found)? "" : "Not ");
    
    needle = "Renato";
    found = linear_search(&needle, names, size, sizeof(char**), string_cmp);
    printf("%sFound!\n", (found)? "" : "Not ");
}


int main(int argc, char **argv)
{
    printf("Testing for 'int'...\n");
    test_int();

    printf("Testing for 'double'...\n");
    test_double();

    printf("Testing for 'char*'...\n");
    test_string();

    return 0;
}
