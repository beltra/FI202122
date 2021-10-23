#include <stdio.h>

int main(int argc, char * argv[]) {
	int anno, bisestile;

	scanf("%d", &anno);

	if(anno % 400 == 0 || (anno % 4 == 0 && anno % 100 != 0)) {
		bisestile = 1;
	}
	else {
		bisestile = 0;
	}

	printf("%d\n", bisestile);
}