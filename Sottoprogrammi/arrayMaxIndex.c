/*
*	Ricevuto in ingresso un array di valori interi e qualsiasi altro parametro ritenuto strettamente necessario,
*	calcola e restituisce al chiamante, l'indice dell'elemento con valore massimo
*/

int maxNumIndex(int[], int);

int maxNumIndex (int numeri[], int dim) {
	int i, iMax;

	iMax = 0;
	for (i = 1; i < dim; i++) {
		if (numeri[i] > numeri[iMax]) {
			iMax = i;
		}
	}
 
	return iMax;
}