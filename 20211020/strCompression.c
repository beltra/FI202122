/*
*   Es. 3
*/

#include <stdio.h>
#define MAX_REP 9
#define MAX_LEN 50
#define ZERO '0'

int main (int argc, char * argv[]) {
    char str[MAX_LEN + 1], compr[MAX_LEN*2 + 1];
    char prev;
    int i, j, len, rep;

    gets(str);

    for (len = 0; str[len] != '\0'; len++);

    prev = str[0];
    rep = 1;
    j = 0; /* The position we are writing to in the compr string */
    for (i = 1; i <= len; i++) {
        if (str[i] == prev && rep < MAX_REP) {
            rep++;      /* Update the counter */
        }
        else {
            /* Write to the compressed string */
            compr[j] = prev;
            compr[j + 1] = ZERO + rep;
            j += 2;
            rep = 1;
        }
        prev = str[i];      /* Update the last character analyzed */
    }

    compr[j] = '\0';        /* Terminate the string */

    printf("%s\n", compr);
}