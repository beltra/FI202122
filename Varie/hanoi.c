#define MAX_HEIGHT 20

void main() {
    char towerA[20], towerB[20], towerC[20];
    int height;

    printf("Inserisci l'altezza della torre: ");
    scanf("%d", &height);

    malloc(towerA, height);

    return 0;
}