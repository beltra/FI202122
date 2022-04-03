#include <stdio.h>

int main() {
    int num, div, numCont, divCont, validCont;

    validCont = 0;

    for (numCont = 0; numCont < 44; numCont++) {
        scanf("%d", &num);
        divCont = 0;
        for (div = 2; div <= num; div++) {
            if (num % div == 0) {
                divCont++;
            }
        }
        if (divCont >= 3) {
            validCont++;
        }
    }

    printf("%d\n", validCont);

    return 0;
}