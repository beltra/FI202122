#include <stdio.h>
#define LEN 50


int main () {
    FILE* fp;

    char nomefile[LEN+1];

    fp = fopen(nomefile, "r");

    if (fp != NULL) {
        /* ... */
        fclose(fp);
    } else {
        printf("Problema accesso file %s\n", nomefile);
    }

    /* oppure */

    if (fp = fopen(nomefile, "r")) {
        /* ... */
        fclose(fp);
    } else {
        printf("Problema accesso file %s\n", nomefile);
    }

    return 0;
}
