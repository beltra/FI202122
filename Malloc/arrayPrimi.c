/*
*   Scrivere un sottoprogramma che, ricevuto in ingresso un array e qualsiasi parametro necessario, crea e restituisce al chiamante,
*   l'insieme dei valori dell'array che sono numeri primi.
*   Scrivere poi un main che chiede all'utente quanti dati vuole inserire, li acquisisce, quindi crea l'insieme dei numeri primi
*   e li visualizza in ordine inverso
*/

#include <stdio.h>
#include <stdlib.h>
#define NMAX 200

int *primi(int num[], int dim, int *np);
int isPrimo(int num);

int main (int argc, char *argv[]) {
    int dim, dimPrimi;
    int *num;
    int *nPrimi;
    int i;

    scanf("%d", &dim);

    num = malloc(dim*sizeof(int));

    if (num) {
        for (i = 0; i < dim; i++) {
            scanf("%d", num + i);
        }
        
        nPrimi = primi(num, dim, &dimPrimi);

        if (nPrimi) {
            for (i = dimPrimi - 1; i >= 0; i--) {
                printf("%d ", *(nPrimi + i));
            }
            printf("\n");
            /* La free va qua, nel chiamante */
            free(nPrimi);
        }
        free(num);
    } else {
        printf("Failed to allocate memory\n");
    }

    return 0;

    /*
    int num[NMAX];
    int dim;
    int *nPrimi;
    int dimPrimi;
    int i;

    scanf("%d", &dim);

    for (i = 0; i < dim; i++) {
        scanf("%d", &num[i]);
    }

    nPrimi = primi(num, dim, &dimPrimi);

    if (nPrimi) {
        for (i = dimPrimi -1; i >= 0; i--) {
            printf("%d ", *(nPrimi + i));
        }   
        printf("\n");
        free(nPrimi);
    }
    return 0;*/
}

int *primi(int num[], int dim, int *np) {
    int cnt;
    int *ris;
    int i;
    
    cnt = 0;

    for (i = 0; i < dim; i++) {
        /*if (isPrimo(num[i]) {
            cnt++;
        }*/
        cnt += isPrimo(num[i]);
    }

    ris = malloc(cnt*sizeof(int));

    if (ris) {
        cnt = 0;
        for (i = 0; i < dim; i++) {
            if (isPrimo(num[i])) {
                *(ris + cnt) = num[i];
                cnt++;
            }
        }
        /* NON c'è la free nel sottoprogramma, altrimenti il chiamante riceve sempre null */
    }
    else {
        printf("Failed to allocate memory\n");
    }

    /* Restituisco l'indirizzo di memoria, passo per indirizzo la dimensione */
    *np = cnt;
    return ris;
}

int isPrimo(int num) {
    int i;
    int primo;

    primo = 1;
    for (i = 2; i < num && primo; i++) {
        if (num % i == 0) {
            primo = 0;
        }
    }
    return primo;
}