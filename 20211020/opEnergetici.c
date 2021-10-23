/*
*   Es. 5
*/

#include <stdio.h>
#define LABEL_LEN 50

/* Definisce una struttura dati che contiene il prezzo dell'energia elettrica e del gas, oltre a un'etichetta identificativa */
typedef struct energyOp_s {
    float elec;     /* €/KWh */
    float gas;      /* €/m3  */
    char label[LABEL_LEN + 1];
} energyOp_t;

int main (int argc, char * argv[]) {
    energyOp_t op1, op2;
    float elecUsed, gasUsed;
    float op1Price, op2Price;

    /* Acquisisce i dati relativi alle due aziende */
    scanf("%f %f %s", &op1.elec, &op1.gas, op1.label);
    scanf("%f %f %s", &op2.elec, &op2.gas, op2.label);

    /* Acquisice le quantità di energia elettrica e gas consumate */
    scanf("%f %f", &elecUsed, &gasUsed);

    op1Price = elecUsed * op1.elec + gasUsed * op1.gas;
    op2Price = elecUsed * op2.elec + gasUsed * op2.gas;

    /* Restituisce l'azienda più conveniente */
    if (op1Price < op2Price) {
        printf("%s\n", op1.label);
    }
    else {
        printf("%s\n", op2.label);
    }

    return 0;
}