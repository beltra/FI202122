/*
*   Es. 4
*/

#include <stdio.h>
#define MAXLEN 30

void calcolaMinori(int[], int, int*);

/* Call example */
int main ()  {
    int in[MAXLEN], out[MAXLEN];
    int i, len, tmp;

    /* Get some numbers, stop at the first negative one */
    len = 0;
    scanf("%d", &tmp);
    while (tmp > 0 && len < MAXLEN) {
        in[len] = tmp;
        scanf("%d", &tmp);
        len++;        
    }

    /* Call the subroutine */
    calcolaMinori(in, len, out);

    /* Print the results */
    for (i = 0; i < len; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");

    return 0;
}

void calcolaMinori(int val[], int len, int *min) {
    int i, j, count;

    /* For every number */
    for (i = 0; i < len; i++) {
        count = 0;
        /* Count how many other numbers are lower */
        for (j = 0; j < len; j++) {
            if (val[j] < val[i]) {
                count++;
            }
        }
        min[i] = count;
    }
}