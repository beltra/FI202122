/*
*   Scrivere un sottoprogramma ricorsivo che ricevuto in ingresso un numero intero restituisce la cifra più alta della rappresentazione decimale.
*   Per esempio, ricevuto 1232, restituisce 3.
*/

#include <stdio.h>
#define BASE 10

int cifraMaggiore(int num);

int main () {
    int num;
    scanf("%d", &num);

    printf("%d\n", cifraMaggiore(num));

    return 0;
}

int cifraMaggiore(int num) {
    int cifra, maxSucc;

    if (num == 0) {
        return 0;
    }

    if (num < 0) {
        num = -num;
    }

    cifra = num % BASE;
    maxSucc = cifraMaggiore(num / BASE);

    if (cifra > maxSucc) {
        return cifra;
    } else {
        return maxSucc;
    }
}