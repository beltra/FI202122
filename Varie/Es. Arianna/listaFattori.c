#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_s {
    int num;
    struct nodo_s *next;
} nodo_t;

typedef nodo_t *lista_t;

lista_t append(lista_t *head, int val) {
    nodo_t *newNode;
    nodo_t *p;

    /* Creo un nuovo nodo */
    newNode = malloc(sizeof(nodo_t));

    if (newNode) {
        /* Gli assegno il valore */
        newNode->num = val;
        /* Puntatore a next nullo (ultimo nodo) */
        newNode->next = NULL;

        if (*head == NULL) {  // Se la lista è vuota
           *head = newNode;  // Nuovo elemento come testa di lista
        } else {
            // Arrivo in fondo alla lista (*p ultimo elemento)
            for (p = *head; p->next != NULL; p = p->next)
                ;
            p->next = newNode;
        }
    } else {
        printf("append: failed allocating memory\n");
    }

    return *head;
}

void printList(lista_t head) {
    /* Stampo ogni elemento della lista */
    while (head != NULL) {
        printf("%d -> ", head->num);
        head = head->next;
    }
    printf("|\n");
}

lista_t fattori(int n);

int main (int argc, char *argv[]) {
    lista_t h;
    int n;

    scanf("%d", &n);

    h = fattori(n);

    printList(h);

    return 0;
}

lista_t fattori(int n) {
    lista_t h = NULL;
    int f;

    for (f = 2; f <= n; f++) {
        while (n % f == 0) {
            append(&h, f);
            n = n / f;
        }
    }
    
    return h;
}