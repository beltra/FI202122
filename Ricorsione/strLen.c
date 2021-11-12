/*
*   Scrivere un sottoprogramma che, data in ingresso una stringa, restituisce la sua lunghezza, in modo ricorsivo.
*/

int strlen(char str[]) {
    int l;
    if (str[0] == '\0') {
        l = 0;
    } else {
        l = 1 + strlen(&str[1]);
    }
    return l;
}