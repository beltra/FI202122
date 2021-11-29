#ifndef LISTE_CHAR_H
#define LISTE_CHAR_H

typedef struct listc_s {
    char num;
    struct listc_s *next;
} listc_t;

/* Anche la append può modificare l'inizio della lista (quando la lista è vuota), quindi restituisce la head */
listc_t *append(listc_t *head, char newval);
listc_t *push(listc_t *head, char newval);

/* Stampa tutti i valori della lista */
void view(listc_t *head);

/* Libera tutta la lista */
listc_t *freeList(listc_t *head);

listc_t *search(listc_t *head, char val);

listc_t *delete(listc_t *head, char val);


