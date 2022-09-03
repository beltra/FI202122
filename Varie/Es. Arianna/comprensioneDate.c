#include <stdio.h>
#include <string.h>

int f(char* str) {
    if(*str != '\0') {
        int c = f(str + 1);

        int v = 0;

        if (*str != '/') {
            v = *str - '0';
            int b = c == 0;
            
            //printf("b = %d, c = %d\n", b, c);
            printf ("%d ", c*v+b);
        }

        return c + v;
    }
    else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    char tmp[9];
    printf("Innserisci la tua data di nascita: ");
    scanf("%s", tmp);

    int v = f(tmp);
    printf("\n%d\n", v);
    return 0;
}