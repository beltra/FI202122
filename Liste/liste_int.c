#include "liste_int.h"

#include <stdio.h>
#include <stdlib.h>

nodo_t *push(nodo_t *head, int val) {
    nodo_t *newNode;

    /* Creo un nuovo nodo */
    newNode = malloc(sizeof(nodo_t));

    if (newNode) {
        /* Lo metto prima della head */
        newNode->num = val;
        newNode->next = head;

        head = newNode;
    } else {
        printf("push: failed allocating memory\n");
    }

    return head;
}

nodo_t *append(nodo_t *head, int val) {
    nodo_t *newNode;
    nodo_t *p;

    /* Creo un nuovo nodo */
    newNode = malloc(sizeof(nodo_t));

    if (newNode) {
        /* Gli assegno il valore */
        newNode->num = val;
        newNode->next = NULL;

        if (head == NULL) {  // Se la lista è vuota
            head = newNode;
        } else {
            // Arrivo in fondo alla lista (*p ultimo elemento)
            for (p = head; p->next != NULL; p = p->next)
                ;
            p->next = newNode;
        }
    } else {
        printf("append: failed allocating memory\n");
    }

    return head;
}

nodo_t *insPos(nodo_t *head, int val, int pos) {
    nodo_t *newNode;
    nodo_t *p;

    int cnt;

    /* Creo un nuovo nodo */
    newNode = malloc(sizeof(nodo_t));

    if (newNode) {
        /* Gli assegno il valore */
        newNode->num = val;
        
        if (head == NULL) {  // Se la lista è vuota
            if (pos == 1) {
                newNode->next = NULL;
                head = newNode;
            } else {
                printf("insPos: invalid position\n");
                free(newNode);
            }
        } else {
            // Arrivo in fondo alla lista (*p ultimo elemento)
            for (p = head, cnt = 0; p != NULL; p = p->next, cnt++)
                ;
            if (pos > cnt) {
                printf("insPos: invalid position\n");
                free(newNode);
            } else if (pos == 1) {
                newNode->next = head;
                head = newNode;
            } else {
                // Scorro la lista fino alla posizione
                for (p = head, cnt = 0; cnt < pos - 1; p = p->next, cnt++)
                    ;
                newNode->next = p->next;
                p->next = newNode;
            }
        }
    } else {
        printf("append: failed allocating memory\n");
    }

    return head;
}

nodo_t *freeList(nodo_t *head) {
    nodo_t *tmp;

    /* Scorro tutta la lista e elimino ogni elemento */
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return head;
}

nodo_t *search(nodo_t *head, int val) {
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

nodo_t *delete (nodo_t *head, int val) {
    nodo_t *p, *del;

    /* Se l'elemento cercato è il primo */
    if (head->num == val) {
        del = head;
        head = head->next;
        free(del);

        return head;
    } else {
        for (p = head; p->next != NULL; p = p->next) {
            /* Mi fermo all'elemento precedente a quello con il valore richiesto */
            if (p->next->num == val) {
                /* Cambio il puntatore dell'elemento precedente a quello successivo a quello cercato */
                del = p->next;
                p->next = p->next->next;
                /* Elimino l'elemento cercato */
                free(del);

                return head;
            }
        }
    }

    return head;
}

void view(nodo_t *head) {
    nodo_t *p;

    /* Stampo ogni elemento della lista */
    for (p = head; p != NULL; p = p->next) {
        printf("%d -> ", p->num);
    }
    printf("|\n");
}