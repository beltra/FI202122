/*
*   Stringhe senza ripetizioni
*/

#include <stdio.h>
#define MAX_LEN 30

int main (int argc, char * argv[]) {
    char str[MAX_LEN+1];
    char out[MAX_LEN+1];
    int i, j, len, outLen, found;

    /* Get the input string */
    gets(str);

    /* Compute the string length */
    for (len = 0; str[len] != '\0'; len++);

    /* For every character in the string append it to the out string only if different from the others in the string */
    out[0] = str[0];
    outLen = 1;
    for (i = 0; i < len; i++) {
        found = 0;
        for (j = 0; j < outLen && found == 0; j++) {
            if (str[i] == out[j]) {
                found = 1;
            }
        }
        if (!found) {
            out[outLen] = str[i];
            outLen++;
        }        
    }
    
    /* Terminate and print the output string */
    out[outLen] = '\0';
    printf("%s\n", out);

    return 0;
}