/*
*   Es. 2
*/

#include <stdio.h>
#define MAX_LEN 500

int main (int argc, char * argv[]) {
    char str[MAX_LEN + 1];
    char prev;
    int i, j, len, rep;

    gets(str);

    for (len = 0; str[len] != '\0'; len++);

    prev = str[len - 1];
    rep = 1;
    for (i = len - 2; i >= 0; i--) {
        if (str[i] == prev) {
            rep++;      /* Update the counter */
        }
        else {
            printf("%c", prev);
            printf("%d", rep);
            rep = 1;
        }
        prev = str[i];      /* Update the last character analyzed */
    }

    printf("\n");
}