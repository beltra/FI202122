/*
*   Acquisita in ingresso una stringa di max 50 caratteri minuscoli, si restituisca
*   la stringa ruotata di 1 posizione
*/

#include <stdio.h>

#define LEN 50

int main(int argc, char * argv[]) {
    char str[LEN + 1];
    int i, len;
    char tmp;
    
    gets(str);

    for (len = 0; str[len] != '\0'; len++);

    tmp = str[0];

    for (i = len - 1; i > 0; i--) {
        str[i] = str[i - 1];
    }

    str[0] = tmp;

    printf("%s\n", str);
    return 0;
}