typedef struct Node {
    void *data;
    struct Node *next;
    struct Node *prev;
} Node;

void Lista_new(Lista *lista, int data_size, void (*free_data)(void*)) {
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    lista->data_size = data_size;
    lista->free_data = free_data;
}

void Lista_delete(Lista *lista) {
    Node *current = lista->head;
    while (current != NULL) {
        Node *next = current->next;
        if (lista->free_data != NULL)
            lista->free_data(current->data);
        free(current->data);
        free(current);
        current = next;
    }
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}

int Lista_isEmpty(Lista *lista) {
    return lista->size == 0;
}

int Lista_size(Lista *lista) {
    return lista->size;
}

void Lista_pushFront(Lista *lista, void *valor) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = malloc(lista->data_size);
    memcpy(new_node->data, valor, lista->data_size);
    new_node->next = lista->head;
    new_node->prev = NULL;
    if (lista->head != NULL)
        lista->head->prev = new_node;
    lista->head = new_node;
    if (lista->tail == NULL)
        lista->tail = new_node;
    lista->size++;
}

void Lista_pushBack(Lista *lista, void *valor) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = malloc(lista->data_size);
    memcpy(new_node->data, valor, lista->data_size);
    new_node->next = NULL;
    new_node->prev = lista->tail;
    if (lista->tail != NULL)
        lista->tail->next = new_node;
    lista->tail = new_node;
    if (lista->head == NULL)
        lista->head = new_node;
    lista->size++;
}

int Lista_search(Lista *lista, void *chave, void *dest, int (*cmp)(void *, void *)) {
    Node *current = lista->head;
    while (current != NULL) {
        if (cmp(current->data, chave) == 0) {
            memcpy(dest, current->data, lista->data_size);
            return 1; // Encontrou
        }
        current = current->next;
    }
    return 0; // Não encontrou
}

void Lista_first(Lista *lista) {
    lista->current = lista->head;
}

void Lista_last(Lista *lista) {
    lista->current = lista->tail;
}

int Lista_next(Lista *lista) {
    if (lista->current != NULL) {
        lista->current = lista->current->next;
        return 1; // Próximo elemento válido
    }
    return 0; // Fim da lista
}

int Lista_previous(Lista *lista) {
    if (lista->current != NULL) {
        lista->current = lista->current->prev;
        return 1; // Elemento anterior válido
    }
    return 0; // Início da lista
}

void Lista_current(Lista *lista, void *dest) {
    if (lista->current != NULL) {
        memcpy(dest, lista->current->data, lista->data_size);
    }
}

void Lista_remove(Lista *lista, void *chave, int (*cmp)(void *, void *)) {
    Node *current = lista->head;
    while (current != NULL) {
        if (cmp(current->data, chave) == 0) {
            if (current == lista->head) {
                lista->head = current->next;
                if (lista->head != NULL)
                    lista->head->prev = NULL;
            } else if (current == lista->tail) {
                lista->tail = current->prev;
                if (lista->tail != NULL)
                    lista->tail->next = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            if (lista->free_data != NULL)
                lista->free_data(current->data);
            free(current->data);
            free(current);
            lista->size--;
            return;
        }
        current = current->next;
    }
}

void Lista_removeCurrent(Lista *lista) {
    if (lista->current != NULL) {
        Node *current = lista->current;
        if (current == lista->head) {
            lista->head = current->next;
            if (lista->head != NULL)
                lista->head->prev = NULL;
        } else if (current == lista->tail) {
            lista->tail = current->prev;
            if (lista->tail != NULL)
                lista->tail->next = NULL;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        if (lista->free_data != NULL)
            lista->free_data(current->data);
        free(current->data);
        free(current);
        lista->size--;
    }
}

void Lista_insertAfter(Lista *lista, void *dado) {
    if (lista->current != NULL) {
        Node *new_node = malloc(sizeof(Node));
        new_node->data = malloc(lista->data_size);
        memcpy(new_node->data, dado, lista->data_size);
        new_node->next = lista->current->next;
        new_node->prev = lista->current;
        if (lista->current->next != NULL)
            lista->current->next->prev = new_node;
        else
            lista->tail = new_node;
        lista->current->next = new_node;
        lista->size++;
    }
}

void Lista_insertBefore(Lista *lista, void *dado) {
    if (lista->current != NULL) {
        Node *new_node = malloc(sizeof(Node));
        new_node->data = malloc(lista->data_size);
        memcpy(new_node->data, dado, lista->data_size);
        new_node->next = lista->current;
        new_node->prev = lista->current->prev;
        if (lista->current->prev != NULL)
            lista->current->prev->next = new_node;
        else
            lista->head = new_node;
        lista->current->prev = new_node;
        lista->size++;
    }
}

