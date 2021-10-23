/* 
*	Dati tre numeri in input, determinare se possono essere lati di un triangolo rettangolo (1 se sì, 0 se no)
*/

#include <stdio.h>

int main (int argc, char * argv[]) {
	int a, b, c;
	int ris;

 	scanf("%d %d %d", &a, &b, &c);

 	if(a > 0 && b > 0 && c > 0) {
 		if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b) {
 			ris = 1;
  		}
  		else {
  			ris = 0;
  		}
 	}
 	else {
 		ris = 0;
 	}

 	printf("%d\n", ris);
 	return 0;
}