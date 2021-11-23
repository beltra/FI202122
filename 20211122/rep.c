/*
*   Scrivere un sottoprogramma che riceve in ingresso una stringa s e un intero n (non negativo).
*   Il sottoprogramma restiutisce una nuova stringa ottenuta cnocatenando n copie di s.
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 50

char *rep(char str[], int n);

int main(int argc, char *argv[]) {
    char str[LEN + 1], *strRep;
    int num;

    scanf("%s", str);
    scanf("%d", &num);

    strRep = rep(str, num);

    if (strRep) {
        printf("%s\n", strRep);
        free(strRep);
    }
    return 0;
}

char *rep(char str[], int n) {
    char *strRep;
    int len, i, j;

    for (len = 0; str[len] != '\0'; len++);

    strRep = malloc((len*n + 1)*sizeof(char));

    if (strRep) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < len; j++) {
                *(strRep + j + i * len) = str[j];
            }
        }
        *(strRep + len * n) = '\0';        
    } else {
        printf("Failed allocating memory\n");
    }

    return strRep;
}