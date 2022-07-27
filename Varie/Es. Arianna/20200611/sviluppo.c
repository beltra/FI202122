#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 20

typedef struct data_s {
    int giorno;
    int mese;
    int anno;
} data_t;

typedef struct postazione_s {
    char lettera;
    int numero;
} postazione_t;

typedef struct prenotazione_t {
    char nome[MAXLEN + 1];
    char cognome[MAXLEN + 1];
    data_t data;
    int nLettini;
    int ombrellone;
    postazione_t posto;
} prenotazione_t;

typedef struct nodo_s {
    prenotazione_t prenotazione;
    struct nodo_s *next;
} nodo_t;

typedef nodo_t *lista_t;

int inserisci(lista_t *listaPren, prenotazione_t newPren) {
    nodo_t *p, *newNode;

    /* Controllo se non esiste una prenotazione per lo stesso giorno nello stesso posto */
    if (*listaPren != NULL) {
        for (p = *listaPren; p->next != NULL; p = p->next) {
            if (p->prenotazione.data.giorno == newPren.data.giorno &&
                p->prenotazione.data.mese == newPren.data.mese &&
                p->prenotazione.data.anno == newPren.data.anno &&
                p->prenotazione.posto.lettera == newPren.posto.lettera &&
                p->prenotazione.posto.numero == newPren.posto.numero) {
                return 0;
            }
        }
    }

    newNode = malloc(sizeof(nodo_t));

    if (newNode) {
        newNode->prenotazione = newPren;
        newNode->next = NULL;

        if (*listaPren == NULL) {
            *listaPren = newNode;
        } else {
            p->next = newNode;
        }
    } else {
        printf("inserisci: failed allocating memory\n");
        return -1;
    }
    return 1;
}

data_t affollata(lista_t lista, int *maxLettini) {
    data_t data;
    int max;

    max = -1;
    while (lista->next != NULL) {
        if (lista->prenotazione.ombrellone == 1 && lista->prenotazione.nLettini > max) {
            max = lista->prenotazione.nLettini;
            data = lista->prenotazione.data;
        }
        lista = lista->next;
    }

    *maxLettini = max;
    return data;
}