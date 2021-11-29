/*
*   Scrivere un programma che chiede all'utente una sequenza di valori, terminata quando l'utente inserisce 0
*   Il programma visualizza tutti i valori sopra alla media di tutti i valori
*/

#include <stdio.h>
#include <stdlib.h>

#define STOP 0

typedef struct listint_s {
    int num;
    struct listint_s *next;
} listi_t;

/* Anche la append può modificare l'inizio della lista (quando la lista è vuota), quindi restituisce la head */
listi_t *append(listi_t *head, int newval);
listi_t *push(listi_t *head, int newval);

/* Stampa tutti i valori della lista */
void view(listi_t *head);

/* Stampa solo i valori sopra una certa soglia */
void viewSel(listi_t *head, float th);

/* Libera tutta la lista */
listi_t *freeList(listi_t *head);

int main(int argc, char *argv[]) {
    listi_t *head = NULL;     // sempre inizializzata a NULL quando inizia il programma

    int tot, count, n;
    
    count = 0;
    tot = 0;
    scanf("%d", &n);
    while (n != STOP) {
        head = append(head, n);
        tot += n;
        count++;
        scanf("%d", &n);
    }

    view(head);
    viewSel(head, (float)tot/count);

    head = freeList(head);

    return 0;
}

void view(listi_t *head) {
    listi_t *p;

    /*
    p = head;
    while(p != NULL) {
        printf("%d -> ", p->num);
        p = p->next;
    }
    */

    for (p = head; p != NULL; p = p->next) {
        printf("%d -> ", p->num);
    }
    printf("|\n");
}

void viewSel(listi_t *head, float th) {
    listi_t *p;

    for (p = head; p != NULL; p = p->next) {
        if (p->num > th) {
            printf("%d ", p->num);
        }
    }
    printf("\n");
}

listi_t *push(listi_t *head, int val) {
    listi_t *newNode;

    newNode = malloc(sizeof(listi_t));
    
    if (newNode) {
        newNode->num = val;
        newNode->next = head;

        head = newNode;
    } else {
        printf("push: failed allocating memory\n");
    }

    return head;
}

listi_t *append(listi_t *head, int val) {
    listi_t *newNode;
    listi_t *p;

    newNode = malloc(sizeof(listi_t));
    
    if (newNode) {
        newNode->num = val;
        newNode->next = NULL;

        if (head == NULL) {     // Se la lista è vuota
            head = newNode;
        } else {
            // Arrivo in fondo alla lista (*p ultimo elemento)
            for (p = head; p->next != NULL; p = p->next);
            p->next = newNode;
        }
    } else {
        printf("append: failed allocating memory\n");
    }

    return head;
}

listi_t *freeList(listi_t *head) {
    listi_t *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return head;
}