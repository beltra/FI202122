#include <stdio.h>

#define MAXDIM 10
#define LEN 60

int main(int argc, char *argv[]) {
    int h, w;
    float mat[MAXDIM][MAXDIM];
    int i, j;

    FILE *fin;
    char fileName[LEN+1];

    scanf("%s", fileName);

    scanf("%d %d", &h, &w);

    if (fin = fopen(fileName, "rb")) {
        fread(mat, sizeof(float), h * w, fin);
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                printf("%f ", mat[i][j]);
            }
            printf("\n");
        }    
        fclose(fin);     
    } else {
        printf("Error opening file ./%s\n", fileName);
    }
}
