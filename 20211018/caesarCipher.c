/*
*   Acquisita in ingresso una stringa di massimo 50 caratteri, la cifri usando il cifrario di cesare
*/

#include <stdio.h>

#define DELTA 3
#define LEN 50
#define INIZIO 'a'
#define LETTERE 26

int main(int argc, char * argv[]) {
    char str[LEN + 1];
    int i;
    
    gets(str);

    for(i = 0; str[i] != '\0'; i++) {
        str[i] = INIZIO + ((str[i] - INIZIO) + DELTA) % LETTERE;
    }
    printf("%s\n", str);
    return 0;
}