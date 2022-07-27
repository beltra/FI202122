/*
 *   Scrivere un sottoprogramma che riceve in ingresso una stringa con il nome di un file e
 *   il numero di valori che contiene. Ne restituisce il valore massimo
 */

#include <stdio.h>

int max(char nomeFile[], int maxNum) {
    FILE* fp;
    int max, val;
    int i;

    if (fp = fopen(nomeFile, "r")) {
        fscanf(fp, "%d", &max);

        for (i = 1; i < maxNum; i++) {
            fscanf(fp, "%d", &val);
            if (val > max) {
                max = val;
            }
        }

        fclose(fp);
    } else {
        printf("Errore accesso file %s", nomeFile);
        max = 0;
    }

    return max;
}
