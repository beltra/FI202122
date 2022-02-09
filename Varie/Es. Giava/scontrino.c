#include <stdio.h>
#include <stdlib.h>

typedef struct product_s {
    int qty;
    char name[100];
    float unitPrice;
} product_t;

int main() {
    int num, i;
    float tot;
    char tmp;
    product_t scontrino[10];

    scanf("%d", &num);

    tot = 0;
    for (i = 0; i < num; i++) {
        scanf("%d", &scontrino[i].qty);
        scanf("%c", &tmp);
        scanf("%s", scontrino[i].name);
        scanf("%f", &scontrino[i].unitPrice);
        tot += scontrino[i].qty * scontrino[i].unitPrice;
    }

    printf("Qty\tProduct\tPrice\tTot\n");
    for (i = 0; i < num; i++) {
        printf("%d\t%s\t%.2f\t%.2f\n", scontrino[i].qty, scontrino[i].name, scontrino[i].unitPrice, scontrino[i].qty * scontrino[i].unitPrice);
    }
    printf("Totale: %.2f\n", tot);
    return 0;
}