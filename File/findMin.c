/*
*   Scrivere un sottoprogramma che riceve in ingresso una stringa con il nome di un file e 
*   il numero di valori che contiene. Ne restituisce il valore massimo
*/

#include <stdio.h>

int max(char nomeFile[], int maxNum) {
    FILE* fp;
    int min, val;
    int i, ok;

    fp = fopen(nomeFile, "r");

    if (fp != NULL) {
        if(fscanf(fp, "%d", &min) > 0) {
            while (fscanf(fp, "%d", &val) > 0) {
                if (val < min) {
                    min = val;
                }
            }
        }
        fclose(fp);

        /* oppure */
        /*
        if(fscanf(fp, "%d", &min) > 0) {
            ok = fscanf(fp, "%d", &val);
            while (ok > 0) {
                if (val < min) {
                    min = val;
                }
                ok = fscanf(fp, "%d", &val); 
            }
        }
        fclose(fp);
        */

        /*
        *   Esiste un sottoprogramma che restituisce 0 se non è stata raggiunta la fine del file, 1 altrimenti.
        *   Questo sottoprogramma va usato solo dopo una lettura, generalmente per capire se un dato acquisito è valido.
        */

        /*
        fscanf(fp, "%d", &val);
        if (!feof(fp)) {
            fscanf(fp, "%d", &val);
            while (!feof(fp)) {
                if (val < min) {
                    min = val;
                }
                fscanf(fp, "%d", &val);
            }
        }
        */

        /* 
        *    NON si usa il do while, gli unici due modi da usare sono il primo e l'ultimo.
        *    BISOGNA controllare la corretta aprertura del file e chiuderlo alla fine.
        */        
    }
    else {
        printf("Errore accesso file %s", nomeFile);
        min = 0;
    }

    return min;
}