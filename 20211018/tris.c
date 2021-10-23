/*
*   Acquisita in ingresso una stringa di 9 caratteri composta esclusivamente da x e o
*   La stringa rappresenta una particolare configurazione del gioco del tris, dove i primi 3 caratteri
*   corrispondono alla prima riga e così via.
*   Si converta la stringa ricevuta in ingresso in un modello del dato che raprpesenti lo schema di gioco del tris
*   (array bidimensionale quadrato di dimensione 3). Si determini quindi se la configurazione è vincente
*/

#include <stdio.h>

#define LEN 9
#define DIM 3

int main(int argc, char * argv[]) {
    char gameStr[LEN + 1];
    char game[DIM][DIM];
    int i, j, winning, possibleTris;
    char curChar;
    
    gets(gameStr);

    for (i = 0; i < LEN; i++) {
        game[i / 3][i % 3] = gameStr[i];
    }

    /* Controllo le righe */
    winning = 0;
    for (i = 0; i < DIM && winning == 0; i++) {
        curChar = game[i][0];
        possibleTris = 1;
        for (j = 1; j < DIM && possibleTris; j++) {
            if (game[i][j] != curChar) {
                possibleTris = 0;
            }
        }
        winning = possibleTris;
    }

    /* Controllo le colonne */
    if (winning == 0) {
        for (i = 0; i < DIM && winning == 0; i++) {
            curChar = game[0][i];
            possibleTris = 1;
            for (j = 1; j < DIM && possibleTris; j++) {
                if (game[j][i] != curChar) {
                    possibleTris = 0;
                }
            }
            winning = possibleTris;
        }
    }
    
    /* Controllo la diagonale principale */
    if (winning == 0) {
        curChar = game[0][0];
        possibleTris = 1;
        for (i = 1; j < DIM && possibleTris; i++) {
            if (game[i][i] != curChar) {
                possibleTris = 0;
            }
        }
        winning = possibleTris;
    }

    /* Controllo la diagonale secondaria */
    if (winning == 0) {
        curChar = game[0][DIM - 1];
        possibleTris = 1;
        for (i = 1; i < DIM && possibleTris; i++) {
            if (game[i][DIM -1 - i] != curChar) {
                possibleTris = 0;
            }
        }
        winning = possibleTris;
    }

    printf("%d\n", winning);
    return 0;
}