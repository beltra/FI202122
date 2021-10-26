/*
*   Es. 5
*/

#include <stdio.h>

int isCoprimi(int, int);

/* Call example */
int main () {
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%d\n", isCoprimi(a, b));

    return 0;
}

int isCoprimi (int a, int b) {
    int isOK, i, min;

    /* Find the minor between the two values */
    if (a < b) {
        min = a;
    } else {
        min = b;
    }

    /* Handle the case where one of the two numbers is 0 and the other is different from 1 */
    if ((a == 0 && b != 1) || (b == 0 && a != 1)) {
        return 0;
    }

    /* For every number lower than the minor of the two, check if it's a divisor for both */
    isOK = 1;
    for (i = 2; i < min && isOK; i++) {
        if (a % i == 0 && b % i == 0) {
            isOK = 0;
        }
    }

    return isOK;
}