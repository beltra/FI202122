#include <stdio.h>
#include <stdlib.h>

int main() {

	int num, primo;
	int i;
	
	printf("Inserisci un numero\n");

	scanf("%d", &num);

	primo = 1;

	/*i = 2;

	while(i < num && primo) {
		if (num % i == 0) {
			primo = 0;
		}
		else {
			i++;
		}
	}*/

	for(i = 2; i < num && primo; i++) {
		if (num % i == 0) {
			primo = 0;
			printf("%d non e' primo\n", num);
		}
	}

	if (primo) {
		printf("%d e' primo\n", num);
	}

	return 0;
}