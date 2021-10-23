#define MAXL 30
#define OPTMIN 0
#define OPTMAX 4
#define USATO 1
#define NONUSATO 0
#define CORTAPRIMA 1
#define LUNGAPRIMA 0

int selezionemenu(int, int);
void menu(void);
int lunghezza(char[]);
int palindrome(char[]);
int anagramma(char[], char[]);
void concatena(char[], char[], char[], int);

int main(int argc, char *argv[])
{
    char parola1[MAXL + 1], parola2[MAXL + 1];
    char concatenata[MAXL * 2 + 1];
    int isOK, scelta;
    do
    {
        scelta = selezionemenu(OPTMIN, OPTMAX);
        if (scelta == 1)
        {
            scanf("%s", parola1);
            isOK = palindrome(parola1);
            printf("%d\n", isOK);
        }
        else if (scelta == 2)
        {
            scanf("%s", parola1);
            scanf("%s", parola2);
            isOK = anagramma(parola1, parola2);
            printf("%d\n", isOK);
        }
        else if (scelta == 3)
        {
            scanf("%s", parola1);
            scanf("%s", parola2);
            concatena(parola1, parola2, concatenata, CORTAPRIMA);
            printf("%s\n", concatenata);
        }
        else if (scelta == 3)
        {
            scanf("%s", parola1);
            scanf("%s", parola2);
            concatena(parola1, parola2, concatenata, LUNGAPRIMA);
            printf("%s\n", concatenata);
        }
    } while (scelta != 0);
    printf("bye\n");
    return 0;
}
void menu(void)
{
    printf("* *********************************************************\n");
    printf("* **************************MENU * **************************\n");
    printf("1. verifica se una stringa e’ palindrome\n");
    printf("2. verifica se due stringhe sono anagrammi\n");
    printf("3. concatena due stringhe, mettendo prima la piu’ corta\n");
    printf("4. concatena due stringhe, mettendo prima la piu’ lunga\n");
    printf("0. termina\n");
    printf("* *********************************************************\n");
}
int selezionemenu(int min, int max)
{
    int scelta;
    do
    {
        menu();
        scanf("%d", &scelta);
    } while (!(scelta >= min && scelta <= max));
    return scelta;
}
int lunghezza(char s[])
{
    int i;
    for (i = 0; s[i] != ‘\0’; i++)
        ;
    return i;
}
int palindrome(char s[])
{
    int size, half, i;
    int isPal;
    size = lunghezza(s);
    half = size / 2;
    size--;
    isPal = 1;
    for (i = 0; i < half && isPal == 1; i++)
        if (s[i] != s[size - i])
            isPal = 0;
    return isPal;
}
int anagramma(char s1[], char s2[])
{
    int trovato[MAXL], i, j;
    int isOK;
    for (i = 0; i < MAXL; i++)
        trovato[i] = NONUSATO;
    isOK = 1;
    for (i = 0; s1[i] != ‘\0’ && isOK; i++)
    {
        isOK = 0;
        for (j = 0; s2[j] != ‘\0’ && isOK == 0; j++)
            if (s1[i] == s2[j] && trovato[j] == NONUSATO)
            {
                trovato[j] = USATO;
                isOK = 1;
            }
    }
    return isOK;
}
void concatena(char s1[], char s2[], char ris[], int ordine)
{
    /* da realizzare */
}