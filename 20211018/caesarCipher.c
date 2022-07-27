/*
 *   Acquisita in ingresso una stringa di massimo 50 caratteri, la cifri usando il cifrario di cesare
 */

#include <stdio.h>

#define DELTA 3
#define LEN 50
#define INIZIO 'a'
#define LETTERE 26

void cipher(char *ch, int key);

int main(int argc, char *argv[]) {
  char str[LEN + 1];

  gets(str);

  cipher(str, DELTA);

  printf("%s\n", str);
  return 0;
}


void cipher(char *str, int delta) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    str[i] = INIZIO + ((str[i] - INIZIO) + delta) % LETTERE;
  }
}


void cipher(char *ch, int delta) {
  if (*ch == '\0') {
    return;
  }
  *ch = INIZIO + ((*ch - INIZIO) + delta) % LETTERE;
  cipher(ch + 1, delta);
}