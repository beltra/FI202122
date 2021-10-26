/*
*   Sottoprogramma che restituisce il numero di coppie di numeri che soddisfano num[i] == num[j] && i < j
*/

int coppie (int[], int);

int coppie (int in[], int len) {
    int count, i, j;

    count = 0;
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            if (in[i] == in[j] && i < j) {
                count++;
            }
        }
    }

    return count;
}