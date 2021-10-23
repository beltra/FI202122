/*
*   Acquisita in ingresso una stringa di max 50 caratteri minuscoli, si restituisca
*   la stringa ruotata di 1 posizione
*/

#include <stdio.h>

#define LEN 50
#define ROT 1

int main(int argc, char * argv[]) {
    char str[LEN + 1];
    int i, len;
    char tmp[ROT];
    
    gets(str);

    for (len = 0; str[len] != '\0'; len++);

    for (i = 0; i < ROT; i++) {
        tmp[i] = str[len -1 - i];
    }

    for (i = len - 1; i > 0; i--) {
        str[i] = str[i - ROT];
    }

    for (i = 0; i < ROT; i++) {
        str[i] = tmp[i];
    }

    printf("%s\n", str);
    return 0;
}