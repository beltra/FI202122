/*
*   Scrivere un sottoprogramma che, ricevuta in ingresso una lista, la restituisce con gli elementi in ordine inverso
*/

#include <stdio.h>
#include <stdlib.h>
#include "liste_int.h"

nodo_t *reverse(nodo_t *h);

int main (int argc, char *argv[]) {

    return 0;
}

nodo_t *reverse(nodo_t *h) {
    nodo_t *p;
    nodo_t *hNew = NULL;

    for (p = h; p != NULL; p = p->next) {
        hNew = push(hNew, p->num);                                       
    }
    
    h = freeList(h);

    return hNew;
}