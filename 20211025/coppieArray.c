/*
*   Sottoprogramma che ricevuti in ingresso un array di numeri e tutti i parametri necessari
*   restituisce il numero di coppie di numeri che soddisfano num[i] == num[j] && i < j
*/

int contaCoppie(int[], int);

int contaCoppie(int in[], int len) {    /* L'array viene passato per riferimento, la lunghezza per copia */
    int count, i, j;

    count = 0;
    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (in[i] == in[j]) {
                count++;
            }
        }
    }

    return count;
}