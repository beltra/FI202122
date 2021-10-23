/*
*   Es. 3
*/

#include <stdio.h>
#define MAX_REP 9
#define MAX_LEN 50
#define ZERO '0'

int main (int argc, char * argv[]) {
    char compr[MAX_LEN + 1], str[MAX_LEN/2 * 9 + 1];
    char ch;
    int i, j, len, rep;

    gets(compr);

    len = 0;
    for (i = 0; compr[i] != '\0'; i += 2) {
        /* Get character and repetitions from the compressed string */
        ch = compr[i];
        rep = compr[i+1] - ZERO;
        /* Add the number of equal characters to the expanded string */
        for (j = 0; j < rep; j++) {
            str[len] = ch;
            len++;
        }
    }

    str[len] = '\0';        /* Terminate the string */

    printf("%s\n", str);
}