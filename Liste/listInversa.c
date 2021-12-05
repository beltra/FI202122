/*
*   Scrivere un sottoprogramma che, ricevuta in ingresso una lista, la restituisce con gli elementi in ordine inverso
*/

#include <stdio.h>
#include <stdlib.h>
#include "liste_int.h"

listi_t *reverse(listi_t *h);

int main (int argc, char *argv[]) {

    return 0;
}

listi_t *reverse(listi_t *h) {
    listi_t *p;
    listi_t *hNew = NULL;

    for (p = h; p != NULL; p = p->next) {
        hNew = push(hNew, p->num);                                       
    }
    
    h = freeList(h);

    return hNew;
}