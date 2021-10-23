/*
*   Acquisire i punti di un poligono di al massimo 10 lati
*/

#include <stdio.h>
#define LEN 5
#define MAX_LATI 10

typedef struct punto_s {
    int x, y;
    char name[LEN+1];
} punto_t;

int main(int argc, char * argv[]) {
    punto_t poligono[MAX_LATI];     /* Array di 10 elementi con struttura punto_s */
    int i, num;

    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        scanf("%d %d", &poligono[i].x, &poligono[i].y);
        scanf("%s", poligono[i].nome);
    }    
}