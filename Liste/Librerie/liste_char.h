#ifndef LISTE_CHAR_H
#define LISTE_CHAR_H

typedef struct listc_s {
    char num;
    struct listc_s *next;
} listc_t;

listc_t *append(listc_t *head, char newval);
listc_t *push(listc_t *head, char newval);

/* Libera tutta la lista */
listc_t *freeList(listc_t *head);

listc_t *search(listc_t *head, char val);

listc_t *delete(listc_t *head, char val);

/* Stampa tutti i valori della lista */
void view(listc_t *head);


