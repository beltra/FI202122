/*
*   Ricevuta in ingresso una stringa con caratteri dell'alfabeto inglese, la renda tutta maiuscola (modificandola)
*/

#define LOWERA 'a'
#define LOWERZ 'z'
#define UPPERA 'A'

void toUppercase(char str[]);

void toUppercase(char str[]) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= LOWERA && str[i] <= LOWERZ) {
            str[i] = UPPERA + (str[i] - LOWERA);
        }
    }
}