/*
*   Scrivere un sottoprogramma che riceve in ingresso una stringa dal nome src ed un carattere sep,
*   visualiza su linee successive le parti della stringa separate dal separatore.
*/

void split(char src[], char sep) {
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        if (src[i] == sep) {
            printf("\n");
        } else {
            printf("%c", src[i]);
        }
    }
    printf("\n");
}