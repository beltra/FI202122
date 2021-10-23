/*
*   Acquisire una stringa di al più 20 caratteri, calcolare e visualizzare la stringa allo specchio
*/

#include <stdio.h>

#define MAX_LEN 20

int main (int argc, char * argv[]) {
    char str[MAX_LEN + 1];
    int i, len;
    char tmp;

    gets(str);

    for (len = 0; str[len] != '\0'; len++);

    for (i = 0; i < len/2; i++) {
        tmp = str[len -1 - i];
        str[len -1 - i] = str[i];
        str[i] = tmp;
    }

    printf("%s\n", str);
 
    return 0;
}