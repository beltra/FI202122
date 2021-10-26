/*
*   Es. 2
*/

#include <stdio.h>
#define LEN 50

int parentesiBil(char[]);

/* Call example */
int main (int argc, char *argv[]) {
    char input[LEN+1];

    gets(input);

    printf("%d\n", parentesiBil(input));
    return 0;
}

int parentesiBil(char str[]) {
    int numOpened, numClosed, i;

    numOpened = 0;
    numClosed = 0;

    /* Count how many brackets were opened and closed */
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            numOpened++;
        } else if (str[i] == ')') {
            numClosed++;
        }
    }

    if (numOpened == numClosed) {
        return 1;
    } else {
        return 0;
    }
}