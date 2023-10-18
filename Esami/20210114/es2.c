/* Quesito 3 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_s {
    int num;
    struct nodo_s *next;
} nodo_t;


nodo_t *compact(nodo_t *h);
nodo_t *append(nodo_t *head, int newval);

int main(int argc, char *argv[]) {
    nodo_t *head = NULL;
    nodo_t *p;
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

nodo_t *compact(nodo_t *head) {
    nodo_t *p, *s, *tmp;
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

nodo_t *append(nodo_t *head, int val) {
    nodo_t *newNode;
    nodo_t *p;

    /* Creo un nuovo nodo */
    newNode = malloc(sizeof(nodo_t));
    
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