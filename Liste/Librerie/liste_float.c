#include <stdio.h>
#include <stdlib.h>
#include "liste_float.h"

listf_t *push(listf_t *head, float val) {
    listf_t *newNode;

    newNode = malloc(sizeof(listf_t));
    
    if (newNode) {
        newNode->num = val;
        newNode->next = head;

        head = newNode;
    } else {
        printf("push: failed allocating memory\n");
    }

    return head;
}

listf_t *append(listf_t *head, float val) {
    listf_t *newNode;
    listf_t *p;

    newNode = malloc(sizeof(listf_t));
    
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

listf_t *freeList(listf_t *head) {
    listf_t *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return head;
}

listf_t *search(listf_t *head, float val) {
    listf_t *p;

    /* Scorro tutta la lista */
    for (p = head; p != NULL; p = p->next) {
        /* Se trovo l'elemento cercato ritorno il suo indirizzo */
        if (p->num == val) {
            return p;
        }
    }

    return NULL;
}

listf_t *delete(listf_t *head, float val) {
    listf_t *p, *del;

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

void view(listf_t *head) {
    listf_t *p;

    for (p = head; p != NULL; p = p->next) {
        printf("%f -> ", p->num);
    }
    printf("|\n");
}