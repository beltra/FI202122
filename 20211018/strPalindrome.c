/*
*   Acquisita in ingresso una stringa di al massimo 50 caratteri (minuscoli), determini se questa è palindroma
*/

#include <stdio.h>

#define LEN 50

int main(int argc, char * argv[]) {
    char str[LEN + 1];
    int i, len, palindroma;
    
    gets(str);

    for (len = 0; str[len] != '\0'; len++);
    
    palindroma = 1;
    for (i = 0; i < len/2 && palindroma == 1; i++) {
        if (str[i] != str[len - i - 1]) {
            palindroma = 0;
        }
    }
    printf("%d\n", palindroma);
    return 0;
}