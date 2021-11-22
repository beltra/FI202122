/*
*   Es. 5
*/

#include <stdio.h>
#include <stdlib.h>

int cat(int n);

int main (int argc, char *argv[]) {
    int num;
    int i;

    do {
        scanf("%d", &num);
    } while (num < 0);

    for (i = 0; i <= num; i++) {
        printf("%d\n", cat(i));
    }

    return 0;
}

int cat(int n) {
    int ris;
    int i;

    if (n == 0) {
        return 1;
    }

    ris = 0;
    for (i = 0; i < n; i++) {
        ris += cat(i) * cat (n-i-1);
    }

    return ris;
}