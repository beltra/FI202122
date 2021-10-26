/*
*   Es. 1
*/

#include <stdio.h>
#define LEN 50

int numParentesi(char[]);

/* Call example */
int main (int argc, char *argv[]) {
    char input[LEN];

    gets(input);

    printf("%d\n", numParentesi(input));
    return 0;
}

int numParentesi(char str[]) {
    int numOpen, max, i;

    numOpen = 0;
    max = 0;
    
    /* Count how many brackets were opened and how many were closed */
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            numOpen++;
        } else if (str[i] == ')') {
            numOpen--;
        }
        if (numOpen > max) {
            max = numOpen;
        }
    }

    return max;
}