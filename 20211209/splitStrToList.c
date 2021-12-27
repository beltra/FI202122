/*
*   Scrivere un sottoprogramma che riceve in ingresso una stringa dal nome src ed un carattere sep,
*   crea una lista con tutti gli elementi della stringa separati.
*/

typedef struct nodes_s {
    char *string;
    struct nodes_s *next;
} lists_t;

lists_t *append_alloc(lists_t *h, char src[], int dim) {
    lists_t *newNode;
    lists_t *p;
    char *elem;
    int i;

    elem = malloc((dim + 1)*sizeof(char));

    if (elem) {
        for (i = 0; i < dim; i++) {
            *(elem+i) = src[i];
        }
        *(elem + i) = '\0';

        newNode = malloc(sizeof(lists_t));
        if (newNode) {
            newNode->string = elem;
            newNode->next = NULL;

            if (h != NULL) {
                for (p = h; p->next != NULL; p = p->next);
                p->next = newNode;
            } else {
                h = newNode;
            }
        } else {
            printf("Failed allocating new node\n")
        }

    } else {
        printf("Failed allocating string\n");
    }

}

lists_t *splitToList(char src[], char sep) {
    int i, start, stop, dim;
    char *tmp;
    lists_t *h = NULL;

    start = -1;
    stop = start + 1;

    do {
        while (src[stop] != '\0' && src[stop] != '\0') {
            stop++;
        }
        dim = stop - start - 1;
        h = append_alloc(h, &src[start + 1], dim);
        start = stop;
        stop++;
    } while (src[start] != '\0');

    return h;
}