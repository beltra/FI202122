#include <stdio.h>
#include <stdlib.h>
#include "liste_int.h"

void view(listi_t *head) {
    listi_t *p;

    for (p = head; p != NULL; p = p->next) {
        printf("%d -> ", p->num);
    }
    printf("|\n");
}

listi_t *push(listi_t *head, int val) {
    listi_t *newNode;

    newNode = malloc(sizeof(listi_t));
    
    if (newNode) {
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

    newNode = malloc(sizeof(listi_t));
    
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

listi_t *freeList(listi_t *head) {
    listi_t *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return head;
}

listi_t *search(listi_t *head, int val) {
    listi_t *p;

    for (p = head; p != NULL; p = p->next) {
        if (p->num == val) {
            return p;
        }
    }
}

listi_t *delete(listi_t *head, int val) {
    return head;
}