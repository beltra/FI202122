/*
*   Scrivere un programma che acquisisce il nome di un file di testo (max 80 char) e visualizza il numero
*   di valori numerici presenti nel file
*/

#include <stdio.h>
#define LEN 80

#define ZERO '0'
#define NOVE '9'

int main(int argc, char *argv[]) {
    FILE *fin;
    char fileName[LEN +1];
    int tmp;
    char tmpCH;
    int count;

    int isNumber;
    char ch;

    scanf("%s", fileName);

    if (fin = fopen(fileName, "r")) {
        fscanf(fin, "%d", &tmp);
        count = 1;
        while (!feof(fin)) {
            if (fscanf(fin, "%d", &tmp) == 1) {
                printf("%d\n", tmp);
                count++;
            } else {                            // Se non è un intero, non "consuma" il file
                fscanf(fin, "%c", &tmpCH);      // Bisogna leggere la stringa successiva
            }
        }

        /*
        count = 0;
        isNumber = 0;
        while(fscanf(fin, "%c", &ch) != EOF) {
            if (isNumber == 1 && (ch < ZERO || ch > NOVE)) {
                isNumber = 0;
                count++;
            } else if (isNumber == 0 && (ch >= ZERO && ch <= NOVE)) {
                isNumber = 1;
            }
        }
        count += isNumber;
        */

        fclose(fin);
        printf("%d\n", count);
    } else {
        printf("Error opening file %s\n", fileName);
    }

    return 0;
}