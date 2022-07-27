#include <stdio.h>
#define N 5

void media_mobile(float *A, int m, float MM[]) {
    int i;
    float somma;
    for (i = 0; i < m - 1; i++)
        somma += A[i];

    for (i = m; i < N; i++) {
        somma = somma + A[i];
        MM[i + 1 - m] = somma / m;
        somma = somma - A[i + 1 - m];
    }
}

void stampa(float *V, int n) {
    if (n > 0) {
        printf("%f ", *V);
        stampa(V + 1, n);
    }
}

int main() {
    float A[N];
    float MediaMobile[N];
    int m;
    int i;

    printf("Inserisci l'array A: ");
    for (i = 0; i < N; i++)
        scanf("%f", A + i);

    printf("Inserisci l'ordine m: ");
    scanf("%d", &m);

    if (m > N) {
        printf("Errore m > N!");
        return -1;
    }
    if (m < 1) {
        printf("Errore m < 1!");
        return -1;
    }

    media_mobile(A, m, MediaMobile);
    stampa(MediaMobile, N);

    return 0;
}