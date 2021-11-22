/*
*   Es. 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 50

int *conta(char info[], char cars[]);

int main(int argc, char *argv[]) {
    char input[LEN+1], chars[LEN+1];
    
    int i;
    int *cnt;

    scanf("%s", input);
    scanf("%s", chars);

    cnt = conta(input, chars);

    if (cnt) {
        for (i = 0; chars[i] != '\0'; i++) {
            printf("%d ", *(cnt + i));
        }
        printf("\n");
        free(cnt);
    }

    return 0;
}

int *conta(char info[], char cars[]) {
    int i, j, len, tmp, *cnt;

    len = strlen(cars);

    cnt = malloc(len*sizeof(int));

    if (cnt) {
        for (j = 0; j < len; j++) {
            *(cnt + j) = 0;
        }
        for (i = 0; info[i] != '\0'; i++) {
            tmp = 0;
            for (j = 0; j < len; j++) {
                if (info[i] == cars[j]) {
                    *(cnt + j) += 1;
                }
            }
        }
    } else {
        printf("Failed allocating memory");
    }

    return cnt;

}