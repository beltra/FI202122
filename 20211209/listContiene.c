/*
*   Scrivere un sottoprogramma che, ricevuto in ingresso due teste di lista (di interi), restituisca 1 se una lista è strettamente
*   contenuta nell'altra (0 altrimenti), è indifferente se la prima è contenuta nella seconda o viceversa. Ciascuna lista non contiene elementi ripetuti
*   e non è definito alcun ordinamento.
*/

typedef struct nodei_s {
    int num;
    struct nodei_s *next;
} listi_t;

int contiene(listi_t *h1, listi_t *h2) {
    int ris, found;
    int len1, len2;
    listi_t *p1, *p2;

    for (p1 = h1; p1 != NULL; p1 = p1->next) {
        len1++;
    }
    for (p2 = h2; p2 != NULL; p2 = p2->next) {
        len2++;
    }

    if (len1 > len2) {
        p1 = h2;
        p2 = h1;    
        ris = 1;
        
    } else if (len2 > len1) {
        p1 = h1;
        p2 = h2;
        ris = 1;
    }       
    else if (len2 == len1) {
        ris = 0;
    }

    while (p1 != NULL && ris) {
        found = 0;
        while (p2 != NULL && !found) {
            if (p1->num == p2->num) {
                found = 1;
            }
            p2 = p2->next;
        }
        ris = found;
        
        p1 = p1->next;
    }

    return ris;
}