/*
*	Dato un numero in input restituire 0
*   se dispari, 1 se pari
*/

#include <stdio.h>

int main (int argc, char * argv[]) {
	int val;
 	scanf("%d", &val);

 	if(val % 2 == 0) {
 		printf("1\n");
 	}
 	else{
 		printf("0\n");
 	}
 	return 0;
}