#include <stdio.h>
#include <stdlib.h>

/* Definisco la struttura nodo */
typedef struct nodo_s {
    int num;
    struct nodo_s *next;
} nodo_t;

typedef nodo_t *lista_t;

/* Inserisce elementi all'inizio della lista (restituisce la testa di lista) */
lista_t push(lista_t *head, int val) {
    nodo_t *newNode;

    /* Creo un nuovo nodo */
    newNode = malloc(sizeof(nodo_t));

    if (newNode) {
        /* Lo metto prima della head */
        newNode->num = val;
        newNode->next = *head;

        *head = newNode;
    } else {
        printf("push: failed allocating memory\n");
    }
    return *head;
}

/* Inserisce elementi alla fine della lista (restituisce la testa di lista) */
lista_t append(lista_t *head, int val) {
    nodo_t *newNode;
    nodo_t *p;

    /* Creo un nuovo nodo */
    newNode = malloc(sizeof(nodo_t));

    if (newNode) {
        /* Gli assegno il valore */
        newNode->num = val;
        /* Puntatore a next nullo (ultimo nodo) */
        newNode->next = NULL;

        if (*head == NULL) {  // Se la lista è vuota
            *head = newNode;  // Nuovo elemento come testa di lista
        } else {
            // Arrivo in fondo alla lista (*p ultimo elemento)
            for (p = *head; p->next != NULL; p = p->next)
                ;
            p->next = newNode;
        }
    } else {
        printf("append: failed allocating memory\n");
    }

    return *head;
}

/* Inserisce elementi in una posizione specifica della lista (restituisce la testa di lista) */
lista_t insPos(lista_t *head, int val, int pos) {
    nodo_t *newNode;
    nodo_t *p;

    int cnt;

    /* Creo un nuovo nodo */
    newNode = malloc(sizeof(nodo_t));

    if (newNode) {
        /* Gli assegno il valore */
        newNode->num = val;

        if (*head == NULL) {  // Se la lista è vuota
            if (pos == 1) {
                newNode->next = NULL;
                *head = newNode;
            } else {
                printf("insPos: invalid position\n");
                free(newNode);
            }
        } else {
            // Arrivo in fondo alla lista (*p ultimo elemento)
            for (p = *head, cnt = 0; p != NULL; p = p->next, cnt++)
                ;
            if (pos > cnt) {
                printf("insPos: invalid position\n");
                free(newNode);
            } else if (pos == 1) {
                newNode->next = *head;
                *head = newNode;
            } else {
                // Scorro la lista fino alla posizione
                for (p = *head, cnt = 0; cnt < pos - 1; p = p->next, cnt++)
                    ;
                newNode->next = p->next;
                p->next = newNode;
            }
        }
    } else {
        printf("insPos: failed allocating memory\n");
    }

    return *head;
}

/* Elimino l'intera lista liberando la memoria */
lista_t freeList(lista_t *head) {
    nodo_t *p;

    /* Scorro tutta la lista e elimino ogni elemento */
    while (*head != NULL) {
        p = *head;
        *head = (*head)->next;
        free(p);
    }
    /*
    while (*head != NULL) {
        p = (*head)->next;
        free(*head);
        *head = p;
    }*/
    return *head;
}

lista_t freeListRec(lista_t *head) {
    nodo_t *p;
    if (*head == NULL) {
        return *head;
    } else {
        p = (*head)->next;
        free(*head);
        *head = freeListRec(&p);
        return *head;
    }
}

/* Cerco un nodo con un determinato valore (restituisce l'indirizzo del nodo) */
nodo_t *searchVal(lista_t head, int val) {
    nodo_t *p;

    /* Scorro tutta la lista */
    for (p = head; p != NULL; p = p->next) {
        /* Se trovo l'elemento cercato ritorno il suo indirizzo */
        if (p->num == val) {
            return p;
        }
    }

    return NULL;
}

lista_t searchPos(lista_t head, int pos) {
    nodo_t *p;
    int cnt;

    for (p = head, cnt = 0; cnt < pos - 1; p = p->next, cnt++)
        ;
    return p;
}

/* Elimino un nodo per valore (restituisce la testa di lista) */
lista_t deleteVal(lista_t *head, int val) {
    nodo_t *p, *del;

    /* Se l'elemento cercato è il primo */
    if ((*head)->num == val) {
        del = *head;
        *head = (*head)->next;
        free(del);

        return *head;
    } else {
        for (p = *head; p->next != NULL; p = p->next) {
            /* Mi fermo all'elemento precedente a quello con il valore richiesto */
            if (p->next->num == val) {
                /* Cambio il puntatore dell'elemento precedente a quello successivo a quello cercato */
                del = p->next;

                if (p->next->next == NULL) {
                    p->next = NULL;
                    free(del);
                    return *head;
                } else {
                    p->next = p->next->next;
                    free(del);
                }
            }
        }
    }

    return *head;
}

lista_t deletePos(lista_t *head, int pos) {
    nodo_t *p, *del;
    int cnt;

    for (p = *head, cnt = 0; p != NULL; p = p->next, cnt++)
        ;
    if (pos > cnt) {
        printf("deletePos: invalid position\n");
        return 0;
    } else if (pos == 1) {
        del = *head;
        *head = (*head)->next;
        free(del);

        return *head;
    } else {
        // Scorro la lista fino alla posizione
        for (p = *head, cnt = 0; cnt < pos - 2; p = p->next, cnt++)
            ;
        del = p->next;
        p->next = p->next->next;
        free(del);
        return *head;
    }
}

/* Stampa la lista */
void printList(lista_t head) {
    /* Stampo ogni elemento della lista */
    while (head != NULL) {
        printf("%d -> ", head->num);
        head = head->next;
    }
    printf("|\n");
}

int main(int argc, char *argv[]) {
    lista_t h = NULL;
    nodo_t *p;
    int i;

    /* Inserisco elementi in testa */
    for (i = 1; i <= 5; i++) {
        h = push(&h, i);
    }
    printList(h);

    /* Inserisco elementi in coda */
    for (i = 1; i < 6; i++) {
        append(&h, i);
    }
    printList(h);

    /* Cerco un elemento per valore */
    printf("Cerco l'elemento con valore 5\n");
    p = searchVal(h, 5);
    printf("Trovato: %d in %p\n", p->num, p);
    /* Cerco un elemento per posizione */
    printf("Cerco l'elemento con posizione 4\n");
    p = searchPos(h, 4);
    printf("Trovato: %d in %p\n", p->num, p);

    /* Inserisco un elemento in posizione */
    h = insPos(&h, 0, 1);
    insPos(&h, 99, 8);
    insPos(&h, 88, 50);  // Fuori dalla lista (dà errore)
    printList(h);

    /* Elimino un elemento per valore */
    h = deleteVal(&h, 5);
    printList(h);
    /* ELimino un elemento per posizione */
    deletePos(&h, 5);
    printList(h);

    /* Elimino tutta la lista */
    freeListRec(&h);
    printf("%p\n", h);

    return 0;
}