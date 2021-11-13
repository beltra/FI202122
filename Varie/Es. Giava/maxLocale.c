#include <stdio.h>

#define MAXLEN 100

int main (int argc, char * argv[]) {
    int num[MAXLEN];
    int max[MAXLEN];
    int len;
    int i, j, found;

    do {
        scanf("%d", &len);
    } while (len <= 0 || len > MAXLEN);

    for (i = 0; i < len; i++) {
        scanf("%d", &num[i]);
    }

    j = 0;
    for (i = 1; i < len - 1; i++) {
        if (num[i] > num[i-1] && num[i] > num[i+1]) {
            max[j] = i;
            j++;
        }
    }

    if (j > 0) {
        printf("Max locale in: ");
        for (i = 0; i < j; i++) {
            printf("%d", max[i]);
        }
        printf("\n");
    } else {
        printf("No max locali\n");
    }

    return 0;
}