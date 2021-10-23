#include <stdio.h>

#define ENDVAL 20

int main(int argc, char * argv[])
{
	int min, max;
	int val, cont, tot;
	float avg;

	/* Acquisisci il primo numero e inizializza le variabili */
	scanf("%d", &val);
	min = val;
	max = val;
    tot = val;
	cont = 1;  

	/* Acquisisci tutti gli altri numeri fino al valore di stop e aggiorna man mano le variabili */
    scanf("%d", &val);
    while (val != ENDVAL) {
        if(val < min)
			min = val;
		else if(val > max)
			max = val;
		tot = tot + val;
		cont++;

        scanf("%d", &val);
    }
	
	/* Calcola la media */
	avg = tot / cont;

	/* Stampa i risultati */
	printf("%d %d %f\n", min, max, avg);

	return 0;

}