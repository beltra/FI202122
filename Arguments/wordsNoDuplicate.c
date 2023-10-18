/*
*   Scrivere un programma che acquisisce da riga di comando il nome di un file di testo che 
*   contiene una serie di vocaboli separati da uno spazio. Visualizza i vocaboli in esso contenuti
*   e quante volte ciascuno compare.
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
listwords_t *freeList(listwords_t *h);

int main(int argc, char *argv[]) {
    char* fileName;


    FILE *fin;
    listwords_t *h, *p;

    if (argc == 2) {
        fileName = argv[1];

        fin = fopen(fileName, "r");

        if (fin) {
            h = listWords(fin);

            for(p = h; p != NULL; p = p->next) {
                printf("%s\t%d\n", p->word, p->count);
            }

            h = freeList(h);
            fclose(fin);
        } else {
            printf("Errore nell'apertura del file\n");
        }

    } else {
        printf("Specificare un nome file\n");
    }

    return 0;
}

listwords_t *listWords(FILE *fin) {
    listwords_t *out = NULL;
    listwords_t *index;
    char w[MAXLEN+1];

    while (fscanf(fin, "%s", w) != EOF) {
        // printf("Looking for %s\n", w);
        index = search(out, w);
        if (index) {
            // printf("%s count++\n----\n", index->word);
            (index->count)++;
        } else {
            // printf("%s not found\n----\n", w);
            out = append(out, w);
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

    for (p = h; p != NULL; p = p->next) {
        if (strcmp(word, p->word) == 0) {
            // printf("%s found\n", p->word);
            return p;
        }
    }

    return NULL;
}

listwords_t *freeList(listwords_t *head) {
    listwords_t *tmp;

    /* Scorro tutta la lista e elimino ogni elemento */
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return head;
}