/* Quesito 4 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cercacerniera(char s1[], char s2[]);
char *cerniera(char s1[], char s2[], int inizio);

int main(int argc, char *argv[]) {
    char *s1, *s2;
    char *out;
    int inizio;

    if (argc == 3) {
        s1 = argv[1];
        s2 = argv[2];
    }

    inizio = cercacerniera(s1, s2);

    if (inizio >= 0) {
        out = cerniera(s1, s2, inizio);
        printf("%s\n", out);
        free(out);
    }

    return 0;
}

int cercacerniera(char s1[], char s2[]) {
    int pos;
    int i, j, valid;
    int len1, len2, dim;

    pos = -1;

    len1 = strlen(s1);
    len2 = strlen(s2);

    for (dim = 1; dim < len1 && dim < len2; dim++) {
        valid = 1;
        for (i = dim - 1; i >= 0 && valid; i--) {
            if (s1[i] != s2[len2 - dim + i]) {
                valid = 0;
            }
        }

        if (valid) {
            pos = len2 - dim;
        }   
    }

    return pos;
}

char *cerniera(char s1[], char s2[], int inizio) {
    char *out;

    int lenOut, len1, len2, lenSub;
    int i, j;

    len1 = strlen(s1);
    len2 = strlen(s2);

    lenSub = len2 - inizio;

    lenOut = len2 - lenSub + len1 - lenSub;

    out = malloc(lenOut*sizeof(char));

    if (out) {
        j = 0;
        for (i = lenSub; i < len1; i++) {
            out[j] = s1[i];
            j++;
        }
        for (i = 0; i < inizio; i++) {
            out[j] = s2[i];
            j++;
        }
        
        *(out + j) = '\0';

    } else {
        printf("cerniera: failed allocating memory\n");
    }

    return out;
}