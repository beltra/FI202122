/*
*   Scrivere un programma che da un file con una parola per riga, chiede all'utente una parola da ricercare
*   restituisce 1 se c'è, 0 altrimenti all'interno di un file query.log
*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 50
#define DICTNAME "dizionario.txt"
#define LOGNAME "query.log"

int comparaStringhe(char s1[], char s2[]);

int main(int argc, char *argv[]) {
    FILE *fdict;
    FILE *fout;

    char word[MAXLEN+1];
    char dictWord[MAXLEN+1];
    int found;

    fdict = fopen(DICTNAME, "r");
    fout = fopen(LOGNAME, "a");

    if (fdict) {
        if (fout) {
            scanf("%s", word);

            found = 0;
            fscanf(fdict, "%s", dictWord);

            while (!feof(fdict) && !found) {
                found = !strcmp(word, dictWord);
            }

            fprintf(fout, "%s: %d", word, found);
            fclose(fout);
        } else {
            printf("Error opening log file");
        }
        fclose(fdict);
    } else {
        printf("Error opening dict file");
    }
    return 0;
}