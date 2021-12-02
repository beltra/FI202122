#include <stdio.h>
#include <stdlib.h>
#include "liste_int.h"

listi_t *listapicchi(listi_t *h);

int main() {
    listi_t *h = NULL, *out = NULL;

    h = append(h, 1);
    h = append(h, 5);
    h = append(h, 13);
    h = append(h, 11);
    h = append(h, 11);
    h = append(h, 4);
    h = append(h, -3);
    h = append(h, 1);
    h = append(h, -5);

    out = listapicchi(h);

    view(out);

    return 0;
}

listi_t *listapicchi(listi_t *h) {
    /* Controlla solo il valore successivo */
    /*
    listi_t *out = NULL, *p;

    p = h;
    while (p != NULL && p->next != NULL) {
        if(p->num > p->next->num) {
            out = append(out, p->num);
        }
        p = p->next;
    }

    // Aggiungi l'ultimo elemento della lista
    if (p != NULL) {
        out = append(out, p->num);
    }
    */

    /* Controlla tutti i valori successivi */
    listi_t *out = NULL, *p1, *p2;
    int valid;

    for (p1 = h; p1 != NULL && p1->next != NULL; p1 = p1->next) {
        valid = 1;
        for (p2 = p1->next; p2 != NULL && valid; p2 = p2->next) {
            if (p2->num >= p1->num) {
                valid = 0;
            }
        }
        if (valid) {
            out = append(out, p1->num);
        }
    }

    // Aggiungi l'ultimo elemento della lista
    if (p1 != NULL) {
        out = append(out, p1->num);
    }

    return out;
}