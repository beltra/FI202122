#include <stdio.h>

int main() {
	int cont, found, num;
	found = 0;
	
	for(cont = 0; cont < 5 && found == 0; cont++) {
		scanf("%d", &num);
		if (num == 6) {
			found = 1;
		}
	}

	if (found) {
		printf("%d\n", cont);
	} else {
		printf("6 non inserito\n");
	}
	
	return 0;
}