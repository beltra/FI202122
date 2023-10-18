#include <stdio.h>

int main() {
    int row, col, dim;
    scanf("%d", &dim);

    for (row = 0; row < dim * 2; row++) {
        for (col = 0; col < dim * 2 - 1; col++) {
            /*
            if (row < dim) {
                if (col >= row && col < dim) {
                    printf("* ");
                } else {
                    printf("  ");
                }
            } else if (row >= dim) {
                if (col < dim - 1) {
                    printf("  ");
                } else if (col < row) {
                    printf("* ");
                }
            }
            */
            if (row < dim) {
                if (col == row || col == dim - 1 || (row == 0 && col < dim)) {
                    printf("* ");
                } else {
                    printf("  ");
                }
            } else if (row >= dim) {
                if (col == row - 1 || col == dim - 1 || (row == dim * 2 - 1 && col >= dim)) {
                    printf("* ");
                } else {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
}