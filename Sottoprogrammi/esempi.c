/*
*	Scrivere un sottoprogramma che ricevuta in ingresso una stringa, calcola e restituisce la sua dimensione.
*/

int strlen(char string[]) {
	int len;
	for(len = 0; string[len] != '\0'; len++);
	return len;
}