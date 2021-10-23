/*
* 	Dato un numero intero, restituire la somma delle sue cifre
*/

#include <stdio.h>

int main (int argc, char * argv[]) {
	int numero, tmp;
	int somma;
	int ordGrandezza;
	
 	scanf("%d", &numero);

 	somma = 0;

 	if(numero >= 0) {
 		tmp = numero;
 	}
 	else {
 		tmp = -numero;
 	}

 	/*
 	ordGrandezza = 1;

 	while(ordGrandezza < tmp) {
 		ordGrandezza *= 10;
 	} 	

 	while (ordGrandezza >= 1) {
 		somma += tmp / ordGrandezza;
 		tmp = tmp % ordGrandezza;
 		ordGrandezza /= 10;
 	} */

 	while (tmp != 0) {
 		somma += tmp % 10;
 		tmp = tmp / 10;
 	}

 	printf("%d\n", somma);
 	return 0;
}