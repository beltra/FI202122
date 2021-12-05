/*
*   Esempio di utilizzo parametri da riga di comando
*/

#include <stdio.h>
#include <stdlib.h>
#

int main(int argc, char *argv[])
{
    char *nomeprog;
    char *srcFile, *dstFile;

    /* È utile salvare in variabili i prametri, per usarli poi nel programma */
    /* NON è una copia, assegna l'indirizzo a un'altra variabile indirizzo con un nome utile */
    nomeprog = argv[0];
    srcFile = argv[1];
    dstFile = argv[2];

    return 0;
}

void printHelp();

int main(int argc, char *argv[]) {
    char *op1, *op2;
    int val1, val2;

    if (argc == 3) {
        op1 = argv[1];
        op2 = argv[2];

        val1 = atoi(op1);
        val2 = atoi(op2);

    } else {
        printHelp();
    }

    return 0;
}

void printHelp() {
    printf("È necessario passare due interi\n");
}