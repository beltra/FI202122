#include <stdio.h>

#define MAX 101

void popola(char *s, int V[]) {
  char c;
  if (*s != '\0') {
    c = *s;
    if (c >= 'A' && c <= 'Z')
      V[c - 'A'] = 1;
    else if (c >= 'a' && c <= 'z')
      V[c - 'a'] = 1;

    popola(s + 1, V);
  }
}

int calcola (int B1[], int B2[], int B[]) {
  int i, valid = 1;
  for (i = 0; i < 26; i++) {
    if (!((B1[i] && B2[i]) || (!B1[i] && !B2[i]))) {
      valid = 0;
      B[i] = 1;
    }
  }
  return !valid;
}

int verifica (char *s1, char *s2, int *B) {
  int B1[26] = {0}, B2[26] = {0};

  popola(s1, B1);
  popola(s2, B2);

  return calcola(B1, B2, B);
}

int main() {
  int res, i, B[26] = {0};
  char s1[MAX], s2[MAX];

  printf("Inserisci la prima stringa: ");
  scanf("%s", s1);
  printf("Inserisci la seconda stringa: ");
  scanf("%s", s2);

  res = verifica(s1, s2, B);
  if (res == 0) {
    printf("Le stringhe verificano la condizione\n");
  } else {
    printf("Le stringhe non verificano la condizione\n");
    for (i = 0; i < 26; i++) {
      if (B[i] == 1)
        printf("%c ", i + 'a');
    }
    printf("\n");
  }
  return 0;
}