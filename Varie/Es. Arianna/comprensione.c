#include <stdio.h>

#define MAX 100
#define NALPH 26

void fix_len(char* a, char* b) {
    int i, flag = 0, len;

    for (i = 0; a[i] != '\0'; i++) {
        if (b[i] == '\0' && flag == 0) {
            len = i;
            flag = 1;
        }

        if (flag == 1) {
            b[i] = b[i % len];
        }
    }
    b[i] = '\0';
}

int encrypt(char* x, char* y) {
    int i, cont = 0;
    for (i = 0; x[i] != '\0'; i++) {
        x[i] += (y[i] - '0');
        if (x[i] > 'Z') {
            x[i] -= NALPH;
            cont++;
        }
    }
    return cont;
}

/*
int decrypt(char *x, char *y) {
  int i, cont = 0;
  for (i = 0; x[i] != '\0'; i++) {
    x[i] -= (y[i] - '0');
    if (x[i] < 'A') {
      x[i] += NALPH;
      cont++;
    }
  }
  return cont;
}
*/

int decrypt(char* x, char* y) {
    int flag = 0;
    if (*x == '\0') {
        return 0;
    }

    *x -= (*y - '0');
    if (*x < 'A') {
        *x += NALPH;
        flag = 1;
    }
    return flag + decrypt(x + 1, y + 1);
}

int main() {
    char cognome[MAX], matricola[MAX];
    int res;

    printf("Inserisci il tuo cognome: ");
    scanf("%s", cognome);
    printf("Inserisci la tua matricola: ");
    scanf("%s", matricola);

    printf("%s - %s\n", cognome, matricola);
    fix_len(cognome, matricola);
    printf("%s - %s\n", cognome, matricola);
    res = encrypt(cognome, matricola);

    printf("%s\n", cognome);
    printf("%d\n", res);

    res = decrypt(cognome, matricola);
    printf("%s\n", cognome);
    printf("%d\n", res);

    return 0;
}