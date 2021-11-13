/*
*   Scrivere un programma che genera tutte le possibili combinazioni di un quadrato 3*3 con X e O del tipo
*   XXO
*   OXO
*   OXX
*/

#include <stdio.h>

#define DIM 3
#define CMAX 8  /* 2^DIM */
#define BLACK 'X'
#define WHITE 'O'
#define PATH "./out.txt"

void printSquare(int count[], FILE *fout);

int main (int argc, char *argv[]) {
    FILE *fout;
    int counters[DIM];

    fout = fopen(PATH, "w");
    if (fout != NULL) {
        counters[0] = 0;
        counters[1] = 0;
        counters[2] = 0;

        while (counters[2] < CMAX) {
            while (counters[1] < CMAX) {
                while (counters[0] < CMAX) {
                    printSquare(counters, fout);
                    counters[0]++;
                    fprintf(fout, "\n");
                }
                counters[0] = 0;
                counters[1]++;
            }
            counters[1] = 0;
            counters[2]++;
        }
        fclose(fout);
    } else {
        printf("Error opening file %s\n", PATH);
    }

    return 0;
}

void printSquare(int count[], FILE *fout) {
    char ch;
    int i, j, quoz;

    for (i = 0; i < DIM; i++) {
        quoz = count[i];
        for (j = 0; j < DIM; j++) {
            if (quoz % 2) {
                ch = BLACK;
            }
            else {
                ch = WHITE;
            }
            fprintf(fout, "%c", ch);
            quoz /= 2;
        }
        fprintf(fout, "\n");
    }
}