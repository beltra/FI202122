/*
*   Es. 3
*/

#include <stdio.h>
#define MAXLEN 30

void rimuoviDuplicati(int [], int, int*, int*);

/* Call example */
int main ()  {
    int in[MAXLEN], out[MAXLEN];
    int i, len, outLen, tmp;

    /* Get some numbers, stop at the first negative one */
    len = 0;
    scanf("%d", &tmp);
    while (tmp > 0 && len < MAXLEN) {
        in[len] = tmp;
        scanf("%d", &tmp);
        len++;        
    }

    /* Call the subroutine */
    rimuoviDuplicati(in, len, out, &outLen);

    /* Print the results */
    for (i = 0; i < outLen; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");

    return 0;
}

void rimuoviDuplicati(int in[], int inLen, int out[], int *len) {
    int outLen;
    int i, j, found;

    outLen = 0;

    /* For every number */
    for (i = 0; i < inLen; i++) {
        /* Check if it already appeared */
        found = 0;
        for (j = 0; j < outLen && found == 0; j++) {
            if (in[i] == out[j]) {
                found = 1;
            }
        }
        /* If not, add it to the output array */
        if (!found) {
            out[outLen] = in[i];
            outLen++;
        }        
    }

    /* Save the length */
    *len = outLen;
}