/*
*   Scrivere un sottoprogramma che, ricevuto in ingresso una frase e un carattere ch, restituisce una nuova stringa
*   che contiene i caratteri compresi tra la prima e la seconda occorrenza del carattere ch, escluso.
*   Se non ci sono due occorrenze di ch, restituisce NULL
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 50

char *crop(char str[], char ch);

int main(int argc, char *argv[]) {
    char str[LEN + 1], *strCrop;
    char ch;

    fgets(str, LEN, stdin);
    scanf("%c", &ch);

    strCrop = crop(str, ch);

    if (strCrop) {
        printf("%s\n", strCrop);
        free(strCrop);
    }
    return 0;
}

char *crop(char str[], char ch) {
    char *strCrop;
    int start, end;
    int i;
    
    start = -1;
    end = -1;
    for (i = 0; str[i] != '\0' && (start == -1 || end == -1); i++) {
        if (str[i] == ch) {
            if (start == -1) {
                start = i + 1;
            } else {
                end = i - 1;
            }
        }
    }

    if (start == -1 || end == -1) {
        return NULL;
    }

    strCrop = malloc((end - start + 2) * sizeof(char));

    if (strCrop) {
        for (i = start; i <= end; i++) {
            *(strCrop + i - start) = str[i];
        }
        *(strCrop + end - start + 1) = '\0';
    } else {
        printf("Failed allocating memory\n");
    }

    return strCrop;
}