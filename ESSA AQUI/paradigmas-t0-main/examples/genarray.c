#include <stdio.h>
#include <string.h>

#include "genarray.h"

void test_int() {
    GenericArray intarray;

    GenericArray_new(&intarray, sizeof(int));
    
    for (int i = 0; i < 10; i++) {
        GenericArray_append(&intarray, &i);
    }
    for (int i = 0; i < 10; i++) {
        int valor;
        GenericArray_get(&intarray, i, &valor);
        printf("%d ", valor);
    }
    printf("\n");

    GenericArray_delete(&intarray);
}

void test_double() {
    GenericArray dblarray;

    GenericArray_new(&dblarray, sizeof(double));
    
    for (double i = 0; i < 5; i += 0.5) {
        GenericArray_append(&dblarray, &i);
    }
    for (int i = 0; i < GenericArray_size(&dblarray); i++) {
        double valor;
        GenericArray_get(&dblarray, i, &valor);
        printf("%g ", valor);
    }
    printf("\n");

    GenericArray_delete(&dblarray);
}

void test_string() {
    char *nomes[] = {"Ana", "Maria", "Rafael", "André"};
    GenericArray strarray;
    GenericArray_new(&strarray, sizeof(char*));
    
    for (int i = 0; i < 4; i++) {
        char* nome = strdup(nomes[i]);
        GenericArray_append(&strarray, &nome);
    }
    for (int i = 0; i < 4; i++) {
        char* nome;
        GenericArray_get(&strarray, i, &nome);
        printf("%s ", nome);
    }
    printf("\n");

    GenericArray_delete(&strarray);
}


int main(int argc, char **argv)
{
    test_int();
    test_double();
    test_string();
    return 0;
}
