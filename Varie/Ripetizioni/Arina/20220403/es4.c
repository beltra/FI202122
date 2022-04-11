#include <stdio.h>

int main() {
    int num, div, cont;

    scanf("%d", &num);

    cont = 0;
    for (div = 2; div <= num && cont <= 3; div++) {
        if (num % div == 0) {
            cont++;
            if (cont == 2 || cont == 3) {
                printf("%d ", div);
            }
        }
    }

    return 0;
}