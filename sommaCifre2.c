/*
*	Si scriva un programma che acquisito un numero intero, visualizzi la somma delle sue cifre
*/

#include <stdio.h>
#define BASE 10

int main (int argc, char * argv[]) {
	int numero, tmp;
	int somma;
	int ordGrandezza;
	
 	scanf("%d", &numero);

 	/*
 	tmp = (numero >= 0) ? numero : -numero;
	*/

	if (numero >= 0) {
 		tmp = numero;
 	}
 	else {
 		tmp = -numero;
 	}
	
	somma = 0;   /* inizializzo le variabili quando servono */ 
 	
 	while (tmp > 0) {
 		somma += tmp % BASE;
 		tmp = tmp / BASE;
 	}

 	printf("%d\n", somma);
 	return 0;
}