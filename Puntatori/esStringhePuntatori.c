#include <stdio.h>

void f (char s[]) {
    int i;

    for(i = 0; s[i] != '\0'; i++) {

    }
}

/* 
 * È equivalente scrivere char *s al posto di char s[] 
 * In realtà rende il codice meno chiaro, poichè è necessario lavorare con gli indirizzi per accedere agli elementi di un array
 */

void f (char s[]) {
    int i;

    for(i = 0;*(s + i) != '\0'; i++) {
        
    }
}

