#include <stdio.h>
#include <stdlib.h>

#define BITS_IN_ASCII 8
#define BASE 2

char *char2ascii(char ch);

int main () {
    char ch;

    scanf("%c", &ch);
    printf("%s\n", char2ascii(ch));
}

char *char2ascii(char ch) {
    char *ascii;
    int pos;
    int val;

    ascii = malloc((BITS_IN_ASCII + 1) * sizeof(char));
    
    if (ascii) {
        val = ch;
        pos = BITS_IN_ASCII - 1;

        while (pos >= 0) {
            ascii[pos] = (val % BASE) + '0';
            val /= BASE;

            pos--;
        }
        ascii[BITS_IN_ASCII] = '\0';
    } else {
        printf("Failed allocating memory\n");
    }

    return ascii;    
}



