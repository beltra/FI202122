/*
*   Es. 1
*/

#include <stdio.h>
#define LEN 80

int main(int argc, char *argv[]) {
    FILE *f1, *f2, *fout;
    char name1[LEN+1], name2[LEN+1], nameOut[LEN+1];
    int mode;

    char tmp;
    
    scanf("%s", name1);
    scanf("%s", name2);
    scanf("%s", nameOut);

    scanf("%d", &mode);
    
    if (mode != 1 && mode != 0) {
        return 0;
    }
    
    if (mode == 1) {
        f1 = fopen(name1, "r");
    } else {
        f1 = fopen(name2, "r");
    }
    if (f1) {
        if (mode == 1) {
            f2 = fopen(name2, "r");
        } else {
            f2 = fopen(name1, "r");
        }
        if (f2) {
            fout = fopen(nameOut, "w");
            if (fout) {
                while(fscanf(f1, "%c", &tmp) != EOF) {
                    fprintf(fout, "%c", tmp);
                }
                while(fscanf(f2, "%c", &tmp) != EOF) {
                    fprintf(fout, "%c", tmp);
                }
                fclose(fout);
            } else {
                printf("Error opening output file\n");
            }
            fclose(f2);
        } else {
            printf("Error opening second input file\n");
        }
        fclose(f1);
    } else {
        printf("Error opening first input file\n");
    }

    return 0;
}