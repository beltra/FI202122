#include <stdio.h>
#include <stdlib.h>
#include "liste_int.h"

listi_t *push(listi_t *head, int val) {
    listi_t *newNode;

    /* Creo un nuovo nodo */
    newNode = malloc(sizeof(listi_t));
    
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

listi_t *append(listi_t *head, int val) {
    listi_t *newNode;
    listi_t *p;

    /* Creo un nuovo nodo */
    newNode = malloc(sizeof(listi_t));
    
    if (newNode) {
        /* Gli assegno il valore */
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

listi_t *freeList(listi_t *head) {
    listi_t *tmp;

    /* Scorro tutta la lista e elimino ogni elemento */
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return head;
}

listi_t *search(listi_t *head, int val) {
    listi_t *p;

    /* Scorro tutta la lista */
    for (p = head; p != NULL; p = p->next) {
        /* Se trovo l'elemento cercato ritorno il suo indirizzo */
        if (p->num == val) {
            return p;
        }
    }

    return NULL;
}

listi_t *delete(listi_t *head, int val) {
    listi_t *p, *del;

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

void view(listi_t *head) {
    listi_t *p;

    /* Stampo ogni elemento della lista */
    for (p = head; p != NULL; p = p->next) {
        printf("%d -> ", p->num);
    }
    printf("|\n");
}