/*
*   Scrivere un programma che acquisisca 5 numeri interi da tastiera e li inserisce in una lista.
*   Il programma chiede un ulteriore numero N, se questo è presente nella lista, lo elimina e aggiunge alla fine il suo quadrato
*/

#include <stdio.h>
#include <stdlib.h>
#include "liste_int.h"

#define NUM 5

int main (int argc, char *argv[]) {
    listi_t *head = NULL;
    int i, n;

    for (i = 0; i < NUM; i++) {
        scanf("%d", &n);
        head = append(head, n);
    }

    scanf("%d", &n);

    if (search(head, n)) {
        head = delete(head, n);
        head = append(head, n*n);
    } else {
        printf("%d not in list\n", n);
    }

    view(head);

    freeList(head);

    return 0;
}