/* SPDX-License-Identifer: MIT */

#ifndef PARADIGMAS_UTIL_H_
#define PARADIGMAS_UTIL_H_

/**
 * Troca os valores de duas variáveis de qualquer tipo.
 */
void swap(void *a, void *b, int size);

/**
 * Procura por um elemento, de um tipo qualquer, em um array.
 */
void* linear_search(
    void *key,  /* o valor a ser encontrado */
    void *base, int n,  /* o array e o número de elementos do array */
    int elem_sz,  /* o tamanho dos elementos do array */
    int (*cmpfn)(void*, void*)  /* a função de comparação */
);


#endif /* PARADIGMAS_UTIL_H_ */
