/*
*   Scrivere un sottoprogramma che riceve un riferimento a un file che contiene parole seguite da uno spazio
*   e restituisce al chiamante una lista di vocaboli (di al più 30 caratteri) presenti nel file seguiti dal
*   numero di occorrenze di quel vocabolo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 30

typedef struct listword_s {
    char word[MAXLEN+1];
    int count;
    struct listword_s *next;
} listwords_t;

listwords_t *listWords(FILE *fin);
listwords_t *append(listwords_t *h, char word[]);
listwords_t *search(listwords_t  *h, char word[]);

listwords_t *listWords(FILE *fin) {
    listwords_t *out = NULL;
    listwords_t *index;
    char w[MAXLEN+1];

    while (fscanf(fin, "%s", w) != EOF) {
        index = search(out, w);
        if (index) {
            (index->count)++;
        } else {
            out = append(out, word);
        }
    }

    return out;
}

listwords_t *append(listwords_t *h, char word[]) {
    listwords_t *newNode, *p;
    int i;

    newNode = malloc(sizeof(listwords_t));

    if (newNode) {
        strcpy(newNode->word, word);
        newNode->count = 1;
        newNode->next = NULL;

        if (h == NULL) {
            h = newNode;
        } else {
            for (p = h; p->next != NULL; p = p->next);
            p->next = newNode;
        }
    } else {
        printf("append: failed allocating memory\n");
    }

    return h;
}

listwords_t *search(listwords_t  *h, char word[]) {
    listwords_t *p;
    int found;

    found = 0;
    for (p = h; p != NULL && !found; p = p->next) {
        if (strcmp(word, p->word) == 0) {
            found = 1;
        }
    }

    if (found) {
        return p;
    }

    return NULL;
}