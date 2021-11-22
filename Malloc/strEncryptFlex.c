/*
*   Scrivere un sottoprogramma che ricevuta in ingresso una stringa, ne crea e restituisce una nuova,
*   che contiene solo caratteri maiuscoli. Riceve in ingresso due stringhe con lo schema di sostituzione
*   e restituisce la stringa generata
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SRC "AEIO"
#define REP "4310"
#define LEN 50

char *encryptStr(char str[], char src[], char rep[]);

int main (int argc, char *argv[]) {
    char str[LEN +1];
    char *enc;

    fgets(str, LEN, stdin);

    enc = encryptStr(str, SRC, REP);

    if (enc) {
        printf("%s", enc);
        free(enc);
    }
}

char *encryptStr(char str[], char src[], char rep[]) {
    char *enc;
    int len;
    int i, j;
    int found;
    
    len = strlen(str);

    enc = malloc((len+1)*sizeof(char));

    if (enc) {
        for (i = 0; i <= len; i++) {
            found = 0;
            for (j = 0; src[j] != '\0' && !found; j++) {
                if (str[i] == src[j]) {
                    found = 1;
                }
            }
            if (found) {
                *(enc+i) = rep[j-1];
            } else {
                *(enc+i) = str[i];
            }
        }
        *(enc + i) = '\0';
    } else {
        printf("Failed allocating memory\n");
    }

    return enc;
}