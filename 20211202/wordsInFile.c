/*
*   Scrivere un sottoprogramma che riceve un riferimento a un file che contiene una frase
*   per riga e restituisce al chiamante una lista di vocaboli (di al più 30 caratteri) presenti nel file 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 30

typedef struct lists_s {
    char word[MAXLEN+1];
    struct lists_s *next;
} lists_t;

lists_t *words(FILE *fin);
lists_t *append(lists_t *h, char word[]);

lists_t *words(FILE *fin) {
    lists_t *out = NULL;
    char w[MAXLEN+1];

    while (fscanf(fin, "%s", w) != EOF) {
        out = append(out, w);
    }

    return out;
}

lists_t *append(lists_t *h, char word[]) {
    lists_t *newNode, *p;
    int i;

    newNode = malloc(sizeof(lists_t));

    if (newNode) {
        for (i = 0; word[i] != '\0'; i++) {
            newNode->word[i] = word[i];
        }
        newNode->word[i] = '\0';

        strcpy(newNode->word, word);
        
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