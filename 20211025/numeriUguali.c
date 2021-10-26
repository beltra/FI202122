/*
*   Ricevuti in ingresso tre array, due in ingresso, uno in uscita, ritorni al chiamante i numeri
*   compresi in entrambi i due array di input
*/

void numeriUguali(int in1[], int len1, int in2[], int len2, int out[], int *lenOut);

void numeriUguali(int in1[], int len1, int in2[], int len2, int out[], int *lenOut) {
    int i, j, trovato;

    for (i = 0; i < len1; i++) {
        trovato = 0;
        for (j = 0; j < len2 && !trovato; j++) {
            if (in1[i] == in2[j]) {
                trovato = 1;
                out[*lenOut] = in1[i];
                *lenOut++;
            }
        }
    }

}
