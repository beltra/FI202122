#include <stdio.h>

/*
#    ######
#    #
#    #
###########
     #    #
     #    #
######    #

*/

int main() {
    int row, col, dim;

    scanf("%d", &dim);

    if (dim % 2 == 1) {
        dim++;
    }

    for (row = 0; row < dim + 3; row++) {
        for (col = 0; col < dim * 2 + 3; col++) {
            if (row == 0) {
                if (col == 0 || (col >= dim + 1 && col <= dim * 2 + 3)) {
                    printf("#");
                } else {
                    printf(" ");
                }
            } else if (row == dim + 2) {
                if (col == dim * 2 + 2 || (col >= 0 && col <= dim + 1)) {
                    printf("#");
                } else {
                    printf(" ");
                }
            } else if (row == dim / 2 + 1) {
                printf("#");
            } else if (row < dim / 2 + 1) {
                if (col == 0 || col == dim + 1) {
                    printf("#");
                } else {
                    printf(" ");
                }
            } else {
                if (col == dim + 1 || col == dim * 2 + 2) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}