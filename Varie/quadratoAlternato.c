#include <stdio.h>

int main() {
    int row, col, dim;

    printf("Inserisci la dimensione: ");
    scanf("%d", &dim);

    for (row = 0; row < dim; row++) {
        for (col = 0; col < dim; col++) {
            switch (row % 3) {
                case 0:
                    printf("* ");
                    break;
                case 1:
                    printf("+ ");
                    break;
                case 2:
                    printf("o ");
                    break;
            }
            /*
            if (row % 3 == 0) {
                printf("* ");
            } else if (row % 3 == 1) {
                printf("+ ");
            } else {
                printf("o ");
            }*/
        }
        printf("\n");
    }

    return 0;
}