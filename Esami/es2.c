#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int anno, mese;
    float valutazione;
} recensione_t;

recensione_t *creaArray(char *fileName, int *nDati);

int main(int argc, char *argv[]) {
    char name[55];
    recensione_t *recensioni;

    int nDati, i;

    gets(name);

    recensioni = creaArray(name, &nDati);

    for (i = 0; i < nDati; i++) {
        printf("%d ", recensioni[i].anno);
        printf("%d ", recensioni[i].mese);
        printf("%f\n", recensioni[i].valutazione);
    }
    printf("\n");

    return 0;
}

recensione_t *creaArray(char *fileName, int *num) {
    FILE *fin;
    recensione_t *reviews;
    int nDati, i, pos, tmpInt;
    char tmpCh;
    float tmpFl;

    fin = fopen(fileName, "r");

    if (fin) {
        nDati = 0;
        while (fscanf(fin, "%c", &tmpCh) != EOF) {
            if (tmpCh == '\n') {
                nDati++;
            }
        }

        reviews = malloc(nDati * sizeof(recensione_t));

        if (reviews) {
            rewind(fin);

            for (i = 0; i < nDati; i++) {
                for (pos = 0; pos < 3; pos++) {
                    if (pos == 0) {
                        fscanf(fin, "%d", &reviews[i].anno);
                    } else if (pos == 1) {
                        fscanf(fin, "%d", &reviews[i].mese);
                    } else if (pos == 2) {
                        fscanf(fin, "%f", &reviews[i].valutazione);
                    }
                }
            }
        }
        fclose(fin);
    } else {
        printf("Failed opening file\n");
    }

    *num = nDati;
    return reviews;
}