/*
*   Scrivere un programma che riceve da riga di comando un nome di un file sorgente e uno di destinazione
*   e un numero. Copia nel file dst n caratteri dal file sorgente.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fin;
    FILE *fout;

    char *inName, *outName;
    int n;

    char tmp;
    int i;

    if (argc == 4) {
        inName = argv[1];
        outName = argv[2];
        n = atoi(argv[3]);

        fin = fopen(inName, "r");

        if (fin) {
            fout = fopen(outName, "w");
            if (fout) {
                for (i = 0; i < n; i++) {
                    fscanf(fin, "%c", &tmp);
                    fprintf(fout, "%c", tmp);
                }
                fclose(fout);
            } else {
                printf("Error opening dst file\n");
            }
            fclose(fin);
        } else {
            printf("Error opening src file\n");
        }

    } else {
        printf("Wrong arguments\n");
    }

    return 0;
}