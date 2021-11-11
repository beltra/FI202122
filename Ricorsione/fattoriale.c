/*
*   Scrivere un sottoprogramma che ricevuto in ingresso un numero, ne restituisca il suo fattoriale
*/

int fattoriale(int num);

int fattoriale(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }

    

    return num * fattoriale(num - 1);
}