void view(listc_t *head) {
    listc_t *p;

    for (p = head; p != NULL; p = p->next) {
        printf("%d -> ", p->num);
    }
    printf("|\n");
}

listc_t *push(listc_t *head, char val) {
    listc_t *newNode;

    newNode = malloc(sizeof(listc_t));
    
    if (newNode) {
        newNode->num = val;
        newNode->next = head;

        head = newNode;
    } else {
        printf("push: failed allocating memory\n");
    }

    return head;
}

listc_t *append(listc_t *head, char val) {
    listc_t *newNode;
    listc_t *p;

    newNode = malloc(sizeof(listc_t));
    
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

listc_t *freeList(listc_t *head) {
    listc_t *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return head;
}

listc_t *search(listc_t *head, char val) {
    return head;
}

listc_t *delete(listc_t *head, char val) {
    return head;
}