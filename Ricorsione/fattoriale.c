/* Il seguente sottoprogramma chiama se stesso per restituire il fattoriale di un numero */

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    
    return n * factorial(n-1);
}

/* Il che è equivalente a */
int factorial(int n) {
    int i, ris;

    ris = 1;
    for (i = 2; i <= n; i++) {
		ris *= i;
	}
    
    return ris;
}


/*  
*   In tutti i sottoprogrammi per ricorsione, è necessario che ci sia un operazione che modifica l'argomento del sottoprogramma (n-1)
*   e una condizione che interrompe la ricorsione (n == 0 || n == 1)
*/