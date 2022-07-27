#include <stdio.h>
#include <string.h>
#define MAX 20

void boh(char *s, int i, int j) {
    char temp;
    if (i < j) {
        temp = s[i]; 
        s[i] = s[j]; 
        s[j] = temp;
        boh(s, i + 1, j - 1);
    }
}

void mah(char *s, int n, int len) {
    boh(s, 0, n - 1);   // 654321       345216
    boh(s, n, len - 1); // 612345       345612
    boh(s, 0, len - 1); // 543216       216543
}

int main() {
    char matr[MAX];
    int len;

    printf("Inserici la matricola: ");
    scanf("%s", matr);

    len = strlen(matr);

    boh(matr, 0, 0);
    printf("%s\n", matr); // 123456

    boh(matr, 0, len - 1);
    printf("%s\n", matr); // 654321

    mah(matr, 1, len);
    printf("%s\n", matr); // 543216

    mah(matr, len / 2, len);
    printf("%s\n", matr); // 216543

    return 0;
}