#include <stdio.h>

int main(int argc, char* argv[]) {
	int num, i, fatt;
	scanf("%d", &num);
	i = 1;
	fatt = 1;
	if(num >= 0) {
		for(i=1; i<=num; i++) {
			fatt *= i;
		}
	}
	else {
		scanf("%d", &num);
	}
	printf("%d! = %d\n", num, fatt);
}