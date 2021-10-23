/*
*   Acquisita un stringa di al più 20 caratteri, calcola e visualizza la stringa ottenuta invertendo
*   l'ordine dei caratteri e omettendo le vocali. La stringa contiene solo caratteri minuscoli.
*/

#include <stdio.h>

#define MAX_LEN 20

int main (int argc, char * argv[]) {
    char str[MAX_LEN + 1];
    int i, j;
    char tmp;

    gets(str);
    
    j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (!(tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u')) {
            str[j] = str[i];
            j++;
        }
    }

    for (i = 0; i < j/2; i++) {
        tmp = str[j -1 - i];
        str[j -1 - i] = str[i];
        str[i] = tmp;
    }

    str[j] = '\0';

    printf("%s\n", str);
    
    return 0;
}