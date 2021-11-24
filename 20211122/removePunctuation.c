/*
*   Scrivere un sottoprogramma che riceve in ingresso una stringa contentente un parargrafo di testo
*   scritto in italiano. Il sottoprogramma modifica la stringa eliminando da essa tutti i segni
*   di interpunzione, osssia quei caratteri che differiscono da a-z, A-Z, 0-9 e spazio.
*   Il sottoprogramma resituisce il numero di caratteri eliminati.
*/

#include <stdio.h>
#include <stdlib.h>

#define LOWA 'a'
#define LOWZ 'z'
#define UPPA 'A'
#define UPPZ 'Z'
#define NUM0 '0'
#define NUM9 '9'
#define SPACE ' '

#define LEN 100

int removePunctuation(char str[]);
int toDelete(char ch);

int main(int argc, char *argv[]) {
    char str[LEN + 1];
    int cnt; 

    fgets(str, LEN, stdin);

    cnt = removePunctuation(str);

    if (str) {
        printf("%d\n%s\n", cnt, str);
    }

    return 0;
}

int removePunctuation(char str[]) {
    /*
    int len, origLen, i;
    char *risStr;

    len = 0;
    origLen = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (!toDelete(str[i])) {
            len++;
        }
        origLen++;
    }

    risStr = malloc((len + 1) * sizeof(char));

    if (risStr) {
        len = 0;
        for (i = 0; str[i] != '\0'; i++) {
            if (!toDelete(str[i])) {
                *(risStr + len) = str[i];
                len++; 
            }
        }
        *(risStr + len) = '\0';
    } else {
        printf("Failed allocating memory\n");
    }

    for (i = 0; i <= origLen; i++) {
        str[i] = risStr[i];
    }

    free(risStr);

    return (origLen - len);
    */

    int cnt, i;

    cnt = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (!toDelete(str[i])) {
            str[i - cnt] = str[i];
        } else {
            cnt++;
        }
    }
    str[i-cnt] = '\0';

    return cnt;
}

int toDelete(char ch) {
    int isLow, isUpp, isNum, isSpace;

    isLow = (ch >= LOWA && ch <= LOWZ);
    isUpp = (ch >= UPPA && ch <= UPPZ);
    isNum = (ch >= NUM0 && ch <= NUM9);
    isSpace = (ch == SPACE);
    
    return !isLow && !isUpp && !isNum && !isSpace;
}