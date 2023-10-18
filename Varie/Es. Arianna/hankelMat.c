#include <stdio.h>

#define MAX 10

int leggi(char path[], int Matrice[][MAX], int *pn) {
  FILE *fin;
  int i, j;

  fin = fopen(path, "r");

  if (fin == NULL) {
    printf("Errore apertura file\n");
    return -1;
  }

  fscanf(fin, "%d", pn);

  for(i = 0; i < *pn; i++) {
    for(j = 0; j < *pn; j++) {
      fscanf(fin, "%d", &Matrice[i][j]);
    }
  }

  return 0;
}

int is_Hankel(int Matrice[][MAX], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 1; j <= i; j++) {
      if (Matrice[i][0] != Matrice[i-j][j]) {
        return 0;
      }
    }
    for (j = 1; j <= n - 1 - i; j++) {
      if (Matrice[i][n-1] != Matrice[i+j][n-1-j]) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int Matrice[MAX][MAX];
  int n, res;

  res = leggi("input.txt", Matrice, &n);

  if (res == -1) {
    printf("Errore nella lettura del file\n");
    return -1;
  }

  res = is_Hankel(Matrice, n);

  if (res == 1) {
    printf("La matrice e' di Hankel\n");
  } else {
    printf("La matrice non e' di Hankel\n");
  }

  return 0;
}