#include <stdio.h>

int main(int argc, char* argv[]) {
    int num;
    char segno;

    scanf("%d", &num);

    if (num < 0) {
        segno = '-';
    }
    else if (num > 0) {
        segno = '+';        
    }
    else {
        segno = ' ';
    }

    /*
    if (num) {
        segno = num > 0 ? '+' : '-'; 
    }
    else {
        segno = ' ';
    } */

    printf("%c\n", segno);

    return 0;
}