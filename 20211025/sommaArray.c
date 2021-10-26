/*
*   Sottoprogramma che ricevuta in ingresso un array di numeri reali, calcola e trasmette al chiamante un array di valori
*   In cui ogni valore è dato dalla somma del valore corrispondente nel primo array con tutti i numeri precedenti
*/

void sommaPrecedenti(float in[], int len, float *out);

void sommaPrecedenti(float in[], int len, float out[]) {
    float tmpSum;
    int i, j;
    
    for (i = 0; i < len; i++) {
        tmpSum = in[i];

        for (j = 1; j < i; j++) {
            tmpSum += in[j];
        }

        out[i] = tmpSum;
    }
}