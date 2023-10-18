#ifndef LISTE_INT_H
#define LISTE_INT_H

typedef struct nodo_s {
    int num;
    struct nodo_s *next;
} nodo_t;

nodo_t *append(nodo_t *head, int newval);
nodo_t *push(nodo_t *head, int newval);

/* Libera tutta la lista */
nodo_t *freeList(nodo_t *head);

nodo_t *search(nodo_t *head, int val);

nodo_t *delete (nodo_t *head, int val);

/* Stampa tutti i valori della lista */
void view(nodo_t *head);

#endif