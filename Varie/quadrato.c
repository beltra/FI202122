#include <stdio.h>

int main(int argc, char * argv[]) {
    int lato;
    int colonna, linea;

    scanf("%d", &lato);

    for(linea = 1; linea <= lato; linea++) {
    	for(colonna = 1; colonna <= lato; colonna++) {
    		if (linea == 1 || linea == lato) {
    			printf("#");
    		} else if (colonna == 1 || colonna == lato) {
       			printf("#");
    		}
    		else {
    			printf(" ");
    		}
    	}
    	printf("\n");
    }
 
	return 0;
}