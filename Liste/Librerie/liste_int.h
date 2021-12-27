#ifndef LISTE_INT_H
#define LISTE_INT_H

typedef struct listint_s {
    int num;
    struct listint_s *next;
} listi_t;

listi_t *append(listi_t *head, int newval);
listi_t *push(listi_t *head, int newval);

/* Libera tutta la lista */
listi_t *freeList(listi_t *head);

listi_t *search(listi_t *head, int val);

listi_t *delete(listi_t *head, int val);

/* Stampa tutti i valori della lista */
void view(listi_t *head);

#endif