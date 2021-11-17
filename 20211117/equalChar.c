/*
*   Ricevuti in ingresso due nomi di file di testo, il programma visualizza il nome del file più lungo (--- se uguali)
*   e visualizza il numero di caratteri uguali in posizione uguale
*/

#include <stdio.h>

#define LEN 80

int main(int argc, char *argv[]) {
    FILE *fin1;
    FILE *fin2;

    char fin1Name[LEN +1];
    char fin2Name[LEN+1];
    int count;
    char *tmp1, *tmp2;

    scanf("%s", fin1Name);
    scanf("%s", fin2Name);

    fin1 = fopen(fin1Name, "r");
    fin2 = fopen(fin2Name, "r");

    if (fin1) {
        if (fin2) {
            count = 0;
            fscanf(fin1, "%c", &tmp1);
            fscanf(fin2, "%c", &tmp2);
            while (!feof(fin1) && !feof(fin2)) {
                if (tmp1 == tmp2) {
                    count++;
                }
                fscanf(fin1, "%c", &tmp1);
                fscanf(fin2, "%c", &tmp2);
            }

            if (feof(fin1) && !feof(fin2)) {
                printf("%s\n", fin2Name);
            } else if (feof(fin2) && !feof(fin1)) {
                printf("%s\n", fin1Name);
            } else {
                printf("---\n");
            }

            printf("%d", count);
            
            fclose(fin2);
        } else {
            printf("Error opening second input file");
        }
        fclose(fin1);
    } else {
        printf("Error opening first input file");
    }
    return 0;
}