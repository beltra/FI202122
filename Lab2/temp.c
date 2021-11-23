#include <stdio.h>
#define MAX 30

int main () {
    char seq1[MAX+1], seq2[MAX+1];
    int i, j, k, ris;

    scanf("%s", seq1);

    k = 0;
    for (i = 0; seq1[i] != '\0'; i++) {
        ris = 1;
        for (j = k - 1; j >= 0; j--) {
            if (seq1[i] == seq2[j]) {
                ris = 0;
            }
        }
        if (ris) {
            seq2[k] = seq1[i];
            k++;
        }
    }

    seq2[k] = '\0';
    printf("%d\n", k);

    return 0;
}