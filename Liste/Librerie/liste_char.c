#include <stdio.h>
#include <stdlib.h>
#include "liste_char.h"

listc_t *push(listc_t *head, char val) {
    listc_t *newNode;

    newNode = malloc(sizeof(listc_t));
    
    if (newNode) {
        newNode->num = val;
        newNode->next = head;

        head = newNode;
    } else {
        printf("push: failed allocating memory\n");
    }

    return head;
}

listc_t *append(listc_t *head, char val) {
    listc_t *newNode;
    listc_t *p;

    newNode = malloc(sizeof(listc_t));
    
    if (newNode) {
        newNode->num = val;
        newNode->next = NULL;

        if (head == NULL) {     // Se la lista è vuota
            head = newNode;
        } else {
            // Arrivo in fondo alla lista (*p ultimo elemento)
            for (p = head; p->next != NULL; p = p->next);
            p->next = newNode;
        }
    } else {
        printf("append: failed allocating memory\n");
    }

    return head;
}

listc_t *freeList(listc_t *head) {
    listc_t *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return head;
}

listc_t *search(listc_t *head, char val) {
    listc_t *p;

    /* Scorro tutta la lista */
    for (p = head; p != NULL; p = p->next) {
        /* Se trovo l'elemento cercato ritorno il suo indirizzo */
        if (p->num == val) {
            return p;
        }
    }

    return NULL;
}

listc_t *delete(listc_t *head, char val) {
    listc_t *p, *del;

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

void view(listc_t *head) {
    listc_t *p;

    for (p = head; p != NULL; p = p->next) {
        printf("'%c' -> ", p->num);
    }
    printf("|\n");
}