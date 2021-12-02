#include <stdio.h>
#include <stdlib.h>
#include "liste_int.h"

listi_t *extract(listi_t *h, int start);

listi_t *extract(listi_t *h, int start) {
    listi_t *out = NULL;
    listi_t *p;

    int bit, i;

    bit = start;
    
    for(p = h; p != NULL; p = p->next) {
        for(i = 0; i < p->num; i++) {
            out = append(out, bit);
        }

        bit = !bit;
    }

    return out;
}