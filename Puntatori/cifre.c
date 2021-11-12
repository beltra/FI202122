int cifre (int n) {
    if (n < 10) {
        return 1;
    }
    else {
        return 0;
    }
}

/* 
*   Se n < 10, il programma si interrompe alla return 1. Se n >= 10,
*   l'else è irrilevante, poichè se si arriva nella situazione in cui si può eseguire return 0, significa che n >= 10
*/

/* Sarebbe più opportuno scrivere */
int cifre (int n) {
    if (n < 10) {
        return 1;
    }
    
    return 0;
}

/* Similmente */
/* In questo modo si evita la variabile "sentinella", poichè il programma viene interrotto da return */
/* In casi più complicati è meglio procedere senza troppe return, utilizzando invece variabili che immagazzinano il risultato */

int identita(int mat[][SIZE], int dim) {
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            if ((i == j && mat[i][j] != 1) || (i != j && mat[i][j] != 0)) {
                return 0;
            }
        }
    }
    return 1;
}