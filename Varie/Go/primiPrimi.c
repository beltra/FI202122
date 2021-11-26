#include <stdio.h>

int isPrime(int n);

int main(int argc, char *argv[]) {
    int n, cnt, i;

    scanf("%d", &n);

    i = 2;
    cnt = 0;
    while (cnt < n) {
        if (isPrime(i)) {
            printf("%d\n", i);
            cnt++;
        }
        i++;
    }
    return 0;
}

int isPrime(int n) {
    int i;

    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}