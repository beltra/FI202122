/*
*	Quadro di parole
*/

#include <stdio.h>
#define MAX_LEN 25
#define MAX_NUM 20
#define FRAME '*'

typedef struct word_s {
    char word[MAX_LEN+1];
    int len;
} word_t;

int main (int argc, char * argv[]) {
    int num;
    word_t phrase[MAX_NUM];
    int i, j, maxLen, len[MAX_NUM];

    /* Get the number of words */
    do {
        scanf("%d", &num);
    } while (num > MAM_NUM || num < 0);

    /* For every word in input, put it in the corresponding place in the array*/
    maxLen = 0;
    for (i = 0; i < num; i++) {
        scanf("%s", phrase[i].word);
        /* Calculate and store the length of each word and save the biggest one */
        for (len[i] = 0; phrase[i].word[len[i]] != '\0'; len[i]++);
        if (len[i] > maxLen) {
            maxLen = len[i];
        }
    }

    /* For every line and every column */
    for (i = 0; i < num + 2; i++) {
        for (j = 0; j < maxLen + 2; j++) {
            /* If it's the frame print the frames's character */
            if (i == 0 || i == num + 1 || j == 0 || j == maxLen + 1) {
                printf("%c", FRAME);
            }
            /* If it's a word, print it's characters */
            else if (j - 1 < len[i-1]) {
                printf("%c", phrase[i-1].word[j-1]);
            }
            /* Else print spaces */
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}