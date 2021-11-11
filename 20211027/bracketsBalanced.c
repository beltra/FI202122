/*
*   Es. 2
*/

#include <stdio.h>
#define LEN 50
#define APERTA '('
#define CHIUSA ')'

int parentesiBil(char[]);

/* Call example */
int main (int argc, char *argv[]) {
    char input[LEN+1];

    gets(input);

    printf("%d\n", parentesiBil(input));
    return 0;
}

int parentesiBil(char str[]) {
    int numOpened, i;

    numOpened = 0;

    /* Count how many brackets were opened and closed */
    for (i = 0; str[i] != '\0' && numOpened >= 0; i++) {
        if (str[i] == APERTA) {
            numOpened++;
        } else if (str[i] == CHIUSA) {
            numOpened--;
        } else {
            annidamento = -1;   /* If the character is not a bracket */
        }
    }

    if (numOpened == 0) {
        return 1;
    } else {
        return 0;
    }
}