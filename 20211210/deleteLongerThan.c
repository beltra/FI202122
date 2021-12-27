/*
*   Scrivere un sottoprogramma che, ricevuta in ingresso una testa di lista per la gestione
*   di stringhe dalla lunghezza a priori ignota ed un numero n intero, elimina dalla lista
*   tutti gli elementi contententi una stringa più lunga di n caratteri (o che contiene il carattere -)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lists_t *deleteLongerThan(lists_t *h, int n);
lists_t *deleteElem(lists_t *h, char str[]);

lists_t *deleteLongerThan(lists_t *h, int n) {
    int toDelete, len;
    lists_t *p;

    for (p = h; p != NULL; p = p->next) {
        len = strlen(p->string);
        if (len > n) {
            h = deleteElem(h, p->string);
        }
    }

    return h;
}

lists_t *deleteElem(lists_t *h, char str[]) {
    lists_t *p, *tmp;

    if (strcmp(h->string, str) == 0) {
        tmp = h;
        h = h->next;
        free(tmp->string);
        free(tmp);
    } else {
        for (p = h; p->next != NULL; p = p->next) {
            if (strcmp(str, p->next->string) == 0) {
                tmp = p->next;
                p->next = p->next->next;
                free(tmp->string);
                free(tmp);
            }
        }
    }

    return h;
}