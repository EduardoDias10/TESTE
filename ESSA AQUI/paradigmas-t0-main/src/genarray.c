#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int data_size;
    int size;
    void (*free_data)(void*);
    Node *current;
} Lista;

void Lista_new(Lista* lista, int data_size, void (*free_data)(void*)) {
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    lista->data_size = data_size;
    lista->free_data = free_data;
    lista->current = NULL;
}

void Lista_delete(Lista* lista) {
    Node *temp = lista->head;
    while (temp != NULL) {
        Node *next = temp->next;
        if (lista->free_data != NULL)
            lista->free_data(temp->data);
        free(temp->data);
        free(temp);
        temp = next;
    }
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    lista->current = NULL;
}

int Lista_isEmpty(Lista* lista) {
    return lista->size == 0;
}

int Lista_size(Lista* lista) {
    return lista->size;
}

void Lista_pushFront(Lista* lista, void* valor) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = malloc(lista->data_size);
    memcpy(new_node->data, valor, lista->data_size);
    new_node->next = lista->head;
    lista->head = new_node;
    if (lista->tail == NULL)
        lista->tail = new_node;
    lista->size++;
}

void Lista_pushBack(Lista* lista, void* valor) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = malloc(lista->data_size);
    memcpy(new_node->data, valor, lista->data_size);
    new_node->next = NULL;
    if (lista->tail == NULL) {
        lista->head = new_node;
        lista->tail = new_node;
    } else {
        lista->tail->next = new_node;
        lista->tail = new_node;
    }
    lista->size++;
}

int Lista_search(Lista* lista, void* chave, void* dest, int (*cmp)(void*,void*)) {
    Node *temp = lista->head;
    while (temp != NULL) {
        if (cmp(temp->data, chave) == 0) {
            memcpy(dest, temp->data, lista->data_size);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void Lista_first(Lista* lista) {
    lista->current = lista->head;
}

void Lista_last(Lista* lista) {
    lista->current = lista->tail;
}

int Lista_next(Lista* lista) {
    if (lista->current != NULL && lista->current->next != NULL) {
        lista->current = lista->current->next;
        return 1;
    }
    return 0;
}

void Lista_current(Lista* lista, void* dest) {
    if (lista->current != NULL) {
        memcpy(dest, lista->current->data, lista->data_size);
    }
}

void Lista_remove(Lista* lista, void* chave, int (*cmp)(void*,void*)) {
    Node *prev = NULL;
    Node *curr = lista->head;
    while (curr != NULL) {
        if (cmp(curr->data, chave) == 0) {
            if (prev == NULL) {
                lista->head = curr->next;
                if (lista->head == NULL)
                    lista->tail = NULL;
            } else {
                prev->next = curr->next;
                if (prev->next == NULL)
                    lista->tail = prev;
            }
            if (lista->free_data != NULL)
                lista->free_data(curr->data);
            free(curr->data);
            free(curr);
            lista->size--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void Lista_insertAfter(Lista* lista, void* dado) {
    if (lista->current == NULL) {
        Lista_pushFront(lista, dado);
    } else {
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node->data = malloc(lista->data_size);
        memcpy(new_node->data, dado, lista->data_size);
        new_node->next = lista->current->next;
        lista->current->next = new_node;
        if (lista->current == lista->tail)
            lista->tail = new_node;
        lista->size++;
    }
}

// Exemplo de função de comparação para inteiros
int cmp_int(void *a, void *b) {
    int *x = (int*)a;
    int *y = (int*)b;
    return (*x == *y) ? 0 : ((*x < *y) ? -1 : 1);
}

int main() {
    Lista lista;
    Lista_new(&lista, sizeof(int), NULL);

    int nums[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        Lista_pushBack(&lista, &nums[i]);
    }

    Lista_first(&lista);
    int val;
    while (Lista_next(&lista)) {
        Lista_current(&lista, &val);
        printf("%d ", val);
    }
    printf("\n");

    Lista_last(&lista);
    Lista_insertAfter(&lista, &(int){35});

    Lista_first(&lista);
    while (Lista_next(&lista)) {
        Lista_current(&lista, &val);
        printf("%d ", val);
    }
    printf("\n");

    Lista_remove(&lista, &(int){30}, cmp_int);

    Lista_first(&lista);
    while (Lista_next(&lista)) {
        Lista_current(&lista, &val);
        printf("%d ", val);
    }
    printf("\n");

    Lista_delete(&lista);

    return 0;
}
