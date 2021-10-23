#include <stdio.h>

int main (int argc, char * argv[]) {
    int n1, d1, n2, d2;

    /* Acquisisci i due numeri */
    scanf("%d %d", &n1, &d1);
    scanf("%d %d", &n2, &d2);

    /* Metto a denominatore comune */
    if (d1 != d2) {
        n1 *= d2;
        n2 *= d1;
    }
    
    /* Confronto i numeratori */
    if (n1 > n2) {
        printf("1 > 2\n");
    } else if (n2 > n1) {
        printf("2 > 1\n");
    } else {
        printf("1 = 2\n");
    }

    return 0;
}