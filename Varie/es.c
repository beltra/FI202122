#include <stdio.h>

int main() {
    int last;
    int val;
    int sum;

    scanf("%d", &val);
    last = val;
    sum = val;

    while (val != -1) {
        scanf("%d", &val);
        if (val >= last) {
            printf("+\n");
        } else {
            printf("-\n");
        }
        last = val;
        sum += val;
    }

    printf("somma: %s\n", somma);

    return 0;
}