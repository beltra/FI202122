/* Quesito 3 */

#include <stdio.h>
#include <stdlib.h>

typedef struct listi_s {
    int num;
    struct listi_s *next;
} listi_t;


listi_t *compact(listi_t *h);
listi_t *append(listi_t *head, int newval);

int main(int argc, char *argv[]) {
    listi_t *head = NULL;
    listi_t *p;
    int i, dim, val;

    scanf("%d", &dim);

    for (i = 0; i < dim; i++) {
        scanf("%d", &val);
        head = append(head, val);
    }

    head = compact(head);

    for (p = head; p; p = p->next) {
        printf("%d -> ", p->num);
    }
    printf("|\n");

    return 0;
}

listi_t *compact(listi_t *head) {
    listi_t *p, *s, *tmp;
    int valid;
    int val;

    for (p = head; p && p->next; p = p->next) {
        valid = 1;
        val = p->next->num;

        if (val == 0) {
            valid = 0;
        }

        for (s = head; s->next != p && valid; s = s->next) {
            if (val == s->num) {
                valid = 0;
            }
        }
        
        if (!valid) {
            tmp = p->next;
            p->next = p->next->next;
            
            free(tmp);
        }
    }

    return head;
}

listi_t *append(listi_t *head, int val) {
    listi_t *newNode;
    listi_t *p;

    /* Creo un nuovo nodo */
    newNode = malloc(sizeof(listi_t));
    
    if (newNode) {
        /* Gli assegno il valore */
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