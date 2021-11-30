#ifndef LISTE_FLOAT_H
#define LISTE_FLOAT_H

typedef struct listf_s {
    float num;
    struct listf_s *next;
} listf_t;

listf_t *append(listf_t *head, float newval);
listf_t *push(listf_t *head, float newval);

/* Libera tutta la lista */
listf_t *freeList(listf_t *head);

listf_t *search(listf_t *head, float val);

listf_t *delete(listf_t *head, float val);

/* Stampa tutti i valori della lista */
void view(listf_t *head);

#endif