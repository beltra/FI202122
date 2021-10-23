#include <stdio.h>

int main(int argc, char * argv[]) {
    int lato;
    int charx, chary;
    char character;
    int colonna, linea;

    scanf("%d %d %d %c", &lato, &charx, &chary, &character);

    for(linea = 1; linea <= lato; linea++) {
    	for(colonna = 1; colonna <= lato; colonna++) {
    		if (linea == chary && colonna == charx) {
    			printf("%c", character);
            }
    		else {
    			printf("#");
    		}
    	}
    	printf("\n");
    }
 
	return 0;
}