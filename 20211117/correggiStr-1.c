/*
*   Acquisita una stringa di al più 50 caratteri, contenente due vocaboli non separati da uno spazio
*   Il programma restituisce la stringa corretta, dopo aver cercato le parole esistenti in un file voc.txt
*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 50
#define DICTNAME "voc.txt"

int main(int argc, char *argv[]) {
    FILE *fdict1, *fdict2;

    char str[MAXLEN+1];
    char tmp1Str[MAXLEN+1];
    char tmp2Str[MAXLEN+1];

    char *tmp;
    int found;
    int i, j, len;

    scanf("%s", str);
    len = strlen(str);

    fdict1 = fopen(DICTNAME, "r");

    if (fdict1) {            
        found = 0;
        while (!found && fscanf(fdict2, "%s", tmp2Str) != EOF) {
            tmp = &str[strlen(tmp1Str)];

            fdict2 = fopen(DICTNAME, "r");
            if (fdict2) {
                while(!found && fscanf(fdict2, "%s", tmp2Str) != EOF) {
                    if (!strcmp(tmp2Str, tmp)) {
                        found = 1;
                        printf("%s %s", tmp1Str, tmp2Str);
                    }
                }
                fclose(fdict2);
            } else {
                printf("Error opening dict file");
            }
        }

        printf("%s %s\n", tmp1Str, tmp2Str);
        fclose(fdict1);
    } else {
        printf("Error opening dict file");
    }
    return 0;
}