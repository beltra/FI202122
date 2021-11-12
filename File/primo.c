/*
*   Scrivere un sottoprogramma che riceve in ingresso due stream (fsrc e fdst) e il numero n di dati da leggere,
*   legge il file sorgente e scrive nella destinazione solo i numeri primi
*/

void primi(FILE *fsrc, FILE *fdst, int numVal) {
    int i, val;
    for (i = 0; i < numVal; i++) {
        fscanf(fsrc, "%d", &val);
        if (primo(val)) {
            fprintf(fdst, "%d\n", val);
        }
    }
}