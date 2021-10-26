/*
*	Scrivere un sottoprogramma che ricevuta in ingresso una stringa, calcola e restituisce la sua dimensione.
*	Scrivere un sottoprogramma che riceve in ingresso un array di valori interi e qualsiasi parametro ritenuto strettamente
*	necessario. Restituisce 1 se l'array non ha valori primi, 0 altrimenti.
*/

int strlen(char[]);

int strlen(char str[]) {
	int len;
	for(len = 0; str[len] != '\0'; len++);
	return len;
}

int senzaPrimi(int[], int);

int senzaPrimi(int num[], int len) {
	/*
	int i, j, isOK;
	isOK = 1;
	for (i = 0; i < len && isOK; i++) {
		if (primo(valori[i])) {
			isOK = 0;
		}	
		
		//isOK = !primo(valori[i]);
	}
	return isOK;
	*/

	int i, j;

	for (i = 0; i < len; i++) {
		if (primo(valori[i])) {
			return 0;	/* Interrompe l'esecuzione del sottoprogramma e restituisce 0 */
		}
	}
	return 1;

}

/* Passaggio parametri per copia-indirizzo */
/* Quando un parametro è un array, non viene copiato nella parte di memoria dedicata al sottoprogramma, bensì viene
   passata la posizione (indirizzo) in memoria dei dati -> c'è accesso diretto all'array -> NON si può modificare */

int primo(int);

int primo(int num) {
	int isOK;

	isOK = 1;
	if (num % 2 == 0) {
		isOK = 0;
	} else {
		for (i = 3; i < num/2 && isOK; i +=2 ) {
			if (num % i == 0) {
				isOK = 0;
			}
		}
	}
	return isOK;
}