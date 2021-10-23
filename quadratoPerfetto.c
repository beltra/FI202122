/*
*	Dato un numero in input, determinare se è
*   un quadrato perfetto
*/

#include <stdio.h>

int main (int argc, char * argv[]) {
	int num;
	int ris;
	int i, quadrato;
 	scanf("%d", &num);

 	if(num == 1) {
 		ris = 1;
 	}
 	else{
 		ris = 0;
 		for(i = 1; i <= num/2; i++) {
 			quadrato = i*i;
 			if(quadrato == num) {
 				ris = 1;
 			}
 		}
 	}

 	if (ris) {
 		printf("%d e' un quadrato perfetto\n", num);
 	}
 	else {
 		printf("%d non e' un quadrato perfetto\n", num);
 	}

 	return 0;
}