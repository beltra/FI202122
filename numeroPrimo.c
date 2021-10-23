#include <stdio.h>
#include <stdlib.h>

int main() {

	int num, primo;
	int i;
	
	printf("Inserisci un numero\n");

	scanf("%d", &num);

	primo = 1;

	/*i = 2;

	while(i < num) {
		if (num % i == 0) {
			primo = 0;
			i = num;
		}
		else {
			i++;
		}
	}*/

	for(i = 2; i < num; i++) {
		if (num % i == 0) {
			primo = 0;
			i = num;
		}
	}

	if (primo) {
		printf("%d e' primo\n", num);
	}
	else {
		printf("%d non e' primo\n", num);
	}

}