/*
*   Acquisiti in ingresso 10 valori interi e un ulteriore numero intero che rappresenta un obiettivo da raggiungere
*   determini se tra i 10 valori ne esiste una coppia che sommati da come risultato l'obiettivo
*/ 

#include <stdio.h>

#define DIM 10

int main (int argc, char *argv[]) {
    int num[DIM];
    int obj;
    int i, j, ris;

    for (i = 0; i < DIM; i++) {
        scanf("%d", &num[i]);
    }

    scanf("%d", &obj);

    ris = 0;
    for (i = 0; i < DIM - 1 && ris == 0; i++) {
        for (j = i + 1; j < DIM && ris == 0; j++) {
            if (num[i] + num[j] == obj) {
                ris = 1;
            }
        }
    }

    printf("%d\n", ris);
    return 0;
}