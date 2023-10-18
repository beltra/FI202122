#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct
{
    int giorno;
    int mese;
    int anno;
} data_t;

typedef struct
{
    char casa[MAX];
    char avversario[MAX];
    data_t data;
    int gol_casa;
    int gol_avversario;
} partita_t;

typedef struct nodo_s {
    partita_t partita;
    struct nodo_s* next;
} nodo_t;

typedef nodo_t* lista_t;

int punteggio(lista_t lista, char squadra[]) {
    int punti = 0;

    // scorro la lista
    while (lista != NULL) {
        if (strcmp(lista->partita.casa, squadra) == 0) {
            if (lista->partita.gol_casa > lista->partita.gol_avversario)
                punti += 3;

            else if (lista->partita.gol_casa == lista->partita.gol_avversario)
                punti += 1;
        }

        else if (strcmp(lista->partita.avversario, squadra) == 0) {
            if (lista->partita.gol_casa < lista->partita.gol_avversario)
                punti += 3;

            else if (lista->partita.gol_casa == lista->partita.gol_avversario)
                punti += 1;
        }

        lista = lista->next;
    }

    return punti;
}

int cancella(lista_t* lista, int anno, char squadra[]) {
    nodo_t *p, *c, *temp;
    int n_cancellazioni = 0;

    c = *lista;
    if (strcmp(c->partita.casa, squadra) == 0 && c->partita.data.anno < anno && c->partita.gol_avversario - c->partita.gol_casa >= 3) {  // Devo eliminare il primo elemento della lista
        temp = c;
        *lista = c->next;
        free(temp);
        n_cancellazioni++;
    }

    while (c->next != NULL) {
        if (strcmp(c->next->partita.casa, squadra) == 0 && c->next->partita.data.anno < anno && c->next->partita.gol_avversario - c->next->partita.gol_casa >= 3) {
            n_cancellazioni++;
            temp = c->next;
            c->next = c->next->next;
            free(temp);
        } else {
            c = c->next;
        }
    }

    return n_cancellazioni;
}
