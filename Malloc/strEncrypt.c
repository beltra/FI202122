/*
*   Scrivere un sottoprogramma che ricevuta in ingresso una stringa, ne crea e restituisce una nuova,
*   che contiene solo caratteri maiuscoli, in cui vengono sostituite A -> 4, O -> 0, I -> 1, E -> 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

char *encryptStr(char str[]);

int main (int argc, char *argv[]) {
    char str[LEN +1];
    char *enc;

    fgets(str, LEN, stdin);

    enc = encryptStr(str);

    if (enc) {
        printf("%s", enc);
        free(enc);
    }
}

char *encryptStr(char str[]) {
    char *enc;
    int len;
    int i;
    
    len = strlen(str);

    enc = malloc((len+1)*sizeof(char));

    if (enc) {
        for (i = 0; i <= len; i++) {
            if (str[i] == 'A') {
                *(enc+i) = '4';
            } else if (str[i] == 'O') {
                *(enc+i) = '0';
            } else if (str[i] == 'E') {
                *(enc+i) = '3';
            } else if (str[i] == 'I') {
                *(enc+i) = '1';
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

/* Scrivere una versione che riceva in ingresso due stringhe con lo schema di sostituzione */

#define SUB "AEIO"
#define REP "4310"