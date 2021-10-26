/*
*   Sottoprogramma che data in ingresso l'ora attuale, restituisce i millisecondi trascorsi dalla mezzanotte
*/

#define SECINMIN 60
#define MININHR  60
#define MILLISINSEC 1000

int millis(int h, int m, int s);    /* Si possono omettere i nomi dei parametri nei prototipo */

int millis(int h, int m, int s) {
    int millis;

    millis = (s + m * SECINMIN + h * MININHR * SECINMIN) * MILLISINSEC;

    return millis;
}