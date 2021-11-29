#include <stdio.h>
#include <stdlib.h>
#include "liste_float.h"

void view(listf_t *head) {
    listf_t *p;

    for (p = head; p != NULL; p = p->next) {
        printf("%d -> ", p->num);
    }
    printf("|\n");
}

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
    return head;
}

listf_t *delete(listf_t *head, float val) {
    return head;
}