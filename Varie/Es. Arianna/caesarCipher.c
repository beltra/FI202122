/*
 *   Acquisita in ingresso una stringa di massimo 50 caratteri, la cifri usando il cifrario di cesare
 */

#include <stdio.h>

#define LEN 50
#define FIRSTLOWER 'a'
#define FIRSTUPPER 'A'
#define LETTERS 26

void cipher(char *ch, int key);

int main(int argc, char *argv[]) {
  char str[LEN + 1];
  int key;

  fgets(str, LEN + 1, stdin);
  scanf("%d", &key);

  cipher(str, key);

  printf("%s\n", str);
  return 0;
}
/*
void cipher(char *str, int delta) {
  int i;

  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= FIRSTLOWER && str[i] <= FIRSTLOWER + LETTERS) {
      str[i] = FIRSTLOWER + ((str[i] - FIRSTLOWER) + key) % LETTERS;
    } else if (str[i] >= FIRSTUPPER && str[i] <= FIRSTUPPER + LETTERS) {
      str[i] = FIRSTUPPER + ((str[i] - FIRSTUPPER) + key) % LETTERS;
    }
  }
}
*/

void cipher(char *ch, int delta) {
  if (*ch == '\0') {
    return;
  }

  if (*ch >= FIRSTLOWER && *ch <= FIRSTLOWER + LETTERS) {
    *ch = FIRSTLOWER + ((*ch - FIRSTLOWER) + delta) % LETTERS;
  } else if (*ch >= FIRSTUPPER && *ch <= FIRSTUPPER + LETTERS) {
    *ch = FIRSTUPPER + ((*ch - FIRSTUPPER) + delta) % LETTERS;
  }

  cipher(ch + 1, delta);
}