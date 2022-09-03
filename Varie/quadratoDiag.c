#include <stdio.h>

int main() {
    int row, col, dim;
    scanf("%d", &dim);

    for (row = 0; row < dim; row++) {
        for (col = 0; col < dim; col++) {
            if (row == col) {
                printf("o ");
            } else if (row > col) {
                printf("* ");
            } else if (row < col) {
                printf("+ ");
            }
        }
        printf("\n");
    }
}