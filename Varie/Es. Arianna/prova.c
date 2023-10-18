/*
 *   Scrivere un sottoprogramma che riceve in ingresso una stringa con il nome di un file e
 *   il numero di valori che contiene. Ne restituisce il valore massimo
 */

#include <stdio.h>

int main() {
  int max, val;
  int i;

  scanf("%d", &max);

  for (i = 1; i < 5; i++) {
    scanf("%d", &val);
    if (val > max) {
      max = val;
    }
  }
  printf("%d\n", max);
  return 0;
}


int main() {
  int max, val;
  int i;
  int num[10];

  for (i = 0; i < 10; i++) {
    scanf("%d", &num[i]);

  for (i = 1; i < 10; i++) {
    if (num[i] > max) {
      max = num[i];
    }
  }
}
