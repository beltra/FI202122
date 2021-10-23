/*
* 	Dati due numeri interi positivi a e b, restituire il primo multiplo di a maggiore di b
*/

#include <stdio.h>

int main (int argc, char * argv[]) {
	int a, b;
	int multiplo;
	
 	scanf("%d %d", &a, &b);

 	/*
 	multiplo = a;

 	while(multiplo < b) {
 		multiplo += a;
 	}
 	*/

 	multiplo = ((b/a) + 1) * a;
 	multiplo = b + a - (b % a)
 

 	printf("%d\n", multiplo);
 	return 0;
}