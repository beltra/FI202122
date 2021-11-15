#include <stdio.h>

#define MAXDIM 10
#define LEN 60

int main(int argc, char *argv[]) {
    int h, w;
    int mat[MAXDIM][MAXDIM];
    int i, j;

    FILE *fout;
    char fileName[LEN+1];

    scanf("%s", fileName);

    scanf("%d%d", &h, &w);

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            scanf("%d", &mat[i][j]);
        }
    }    

    if (fout = fopen(fileName, "wb")) {
        fwrite(mat, sizeof(int), h * w, fout);
        fclose(fout);     
    } else {
        printf("Error opening file ./%s\n", fileName);
    }
}
