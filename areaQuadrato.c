/*
*   Definire un tipo che contiene due coordinate e un'etichetta di 5 caratteri per identificare il punto.
*   Chiedere all'utente di inserire due coordinate e restituire l'area del rettangolo
*/

#include <stdio.h>
#define LEN 5

typedef struct punto_s {
    int x, y;
    char name[LEN+1];
} punto_t;

int main(int argc, char * argv[]) {
    punto_t p1, p2;
    punto_t dx, sx;
    int area, w, h;

    scanf("%d %d", &p1.x, &p1.y);
    scanf("%s", p1.name);
    
    scanf("%d %d", &p2.x, &p2.y);
    scanf("%s", p2.name);

    w = p1.x - p2.x;
    if (w < 0) {
        w = -w;
        sx = p2;    /* E' preferibile fare una copia campo per campo */
        dx = p1;    /* (con le stringhe NON si può fare) */
    }

    h = p1.y - p2.y;
    if (h < 0) {
        h = -h;
    }

    area = w * h;
    printf("%d", area);
    return 0;
}
