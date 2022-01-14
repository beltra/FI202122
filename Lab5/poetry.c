#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENMAXVERSO 100
#define SOGLIA 0.20
#define CONDIZIONERIMA 3
#define FILENAME "futuribili.txt"

#define MINMENU 0
#define MAXMENU 9

int lunghezza(char v1[], char v2[]);

int rima(char v1[], char v2[]);

char *cesura(char v[]);

void ret(char s1[], char s2[], int *isAss, int *isAll1, int *isAll2);
int isVowel(char c);

char all(char v[]);

void printMenu();
void handleMenu(int mode);

int main(int argc, char *argv[])
{
    int mode;

    do
    {    
        printMenu();
        scanf("%d\n", &mode);
        if (mode) {
            handleMenu(mode);
        } else {
            break;
        }
    } while (mode >= MINMENU && mode <= MAXMENU);

    printf("Scegli un'opzione tra quelle disponibili\n");

    return 0;
}

void printMenu()
{
    printf("Scegli una funzione: \n");
    printf("0. per oggi ho lavorato abbastanza ... esco\n");
    printf("1. dati due versi, controlla la metrica (la lunghezza)\n");
    printf("2. dati due versi, verificare se sono in rima\n");
    printf("3. dato un verso, cercarne uno tra quanti non ancora usati, che sia in rima\n");
    printf("4. dato un verso, visualizzarne, se esiste, la cesura\n");
    printf("5. cercare un verso tra quanti non ancora usati, cui sia possibile applicare una cesura\n");
    printf("6. dati due versi, verificare se c'e assonanza\n");
    printf("7. dato un verso, cercarne uno tra quanti non ancora usati, che abbia assonanza\n");
    printf("8. dato un verso, sapere se c'e allitterazione\n");
    printf("9. data una lettera, cercare tra i versi non ancora usati uno che presenti un'allitterazione con quella lettera\n");
}

void handleMenu(int mode)
{
    char v1[LENMAXVERSO], v2[LENMAXVERSO];

    char letter;
    int found;

    int tmp1, tmp2;

    char *ris;

    FILE *versi;

    if (mode == 1)
    {
        fgets(v1, LENMAXVERSO, stdin);
        fgets(v2, LENMAXVERSO , stdin);
        if (lunghezza(v1, v2)) {
            printf("Le due lunghezze sono compatibili\n");
        } else {
            printf("Le due lunghezze non sono compatibili\n");
        }

    }
    else if (mode == 2)
    {
        fgets(v1, LENMAXVERSO, stdin);
        fgets(v2, LENMAXVERSO, stdin);
        if (rima(v1, v2))
        {
            printf("I due versi sono in rima\n");
        }
    }
    else if (mode == 3)
    {
        fgets(v1, LENMAXVERSO, stdin);
        versi = fopen(FILENAME, "r");

        if (versi)
        {
            found = 0;
            while (fgets(v2, LENMAXVERSO, versi) && !found)
            {
                if (rima(v1, v2))
                {
                    found = 1;
                    printf("Trovata rima tra %s e %s\n", v1, v2);
                }
            }
            if (!found)
            {
                printf("Nessun verso è in rima con %s\n", v1);
            }
            fclose(versi);
        }
    }
    else if (mode == 4)
    {
        fgets(v1, LENMAXVERSO, stdin);
        ris = cesura(v1);
        printf("%s\n", ris);
    }
    else if (mode == 5)
    {
        if (versi = fopen(FILENAME, "r"))
        {
            while (fgets(v2, LENMAXVERSO, versi))
            {
                ris = cesura(v2);
                printf("%s\n", ris);
            }
            fclose(versi);
        }
        else
        {
            printf("errore");
        }
    }
    else if (mode == 6)
    {
        fgets(v1, LENMAXVERSO, stdin);
        fgets(v2, LENMAXVERSO, stdin);
        ret(v1, v2, &found, &tmp1, &tmp2);
        if (found)
            printf("C'e' assonanza\n");
        else
            printf("Non e' presente assonanza\n");
    }
    else if (mode == 7)
    {
        fgets(v1, LENMAXVERSO, stdin);

        versi = fopen(FILENAME, "r");

        if (versi)
        {
            while (fgets(v2, LENMAXVERSO, versi) && !found)
            {
                ret(v1, v2, &found, &tmp1, &tmp2);
            }
            fclose(versi);
        }
        printf("La stringa dal file che ha assonanza con v1 e': %s", v2);
    }
    else if (mode == 8)
    {
        fgets(v1, LENMAXVERSO, stdin);
        //letter = all(v1);
        ret(v1, "", &tmp1, &found, &tmp2);
        if (found)
        {
            printf("Ha allitterazione\n");
        }
        else
        {
            printf("Il verso non presenta allitterazioni\n");
        }
    }
    else if (mode == 9)
    {
        scanf("%c", &letter);
        letter = tolower(letter);
        versi = fopen(FILENAME, "r");

        if (versi)
        {
            found = 0;
            while (fgets(v1, LENMAXVERSO, versi) && !found)
            {
                if (letter == all(v1))
                {
                    found = 1;
                    printf("%s ha allitterazione della lettera %c\n", v1, letter);
                }
            }
            if (!found)
            {
                printf("Nessun verso ha l'allitterazione della lettera %c\n", letter);
            }
            fclose(versi);
        }
    }
    printf("\n");
}

char *cesura(char v1[])
{
    int trovato;
    int i, len;
    char *ces;

    trovato = 0;

    for (i = 0; v1[i] != '\0' && !trovato; i++)
        if (ispunct(v1[i]))
            trovato = 1;

    len = i;

    ces = malloc(sizeof(char) * len);

    if (ces)
    {
        for (i = 0; i < len; i++)
            ces[i] = v1[i];

        ces[len-1] = '\0';
    }
    else
    {
        printf("cesura: failed allocating memory\n");
    }

    if (len != strlen(v1))
        return ces;

    return NULL;
}

int lunghezza(char verso1[], char verso2[])
{
    int ris;
    int len1, len2, diff;
    len1 = strlen(verso1);
    len2 = strlen(verso2);
    ris = 1;
    diff = len2 - len1;
    if (diff < 0)
    {
        if (-(len1 * SOGLIA) >= diff)
            ris = 0;
    }
    else if (diff > 0)
    {
        if ((len2 * SOGLIA) <= diff)
            ris = 0;
    }
    return ris;
}

int rima(char v1[], char v2[])
{
    int len1, len2;
    int i, j, rima, count;

    for (len1 = 0; v1[len1] != '\0'; len1++)
    {
        v1[len1] = tolower(v1[len1]);
    }

    for (len2 = 0; v2[len2] != '\0'; len2++)
    {
        v2[len2] = tolower(v2[len2]);
    }

    rima = 1;
    count = 0;
    i = len1 - 1;
    j = len2 - 1;

    while (rima == 1 && i != 0 && j != 0 && count <= CONDIZIONERIMA)
    {
        if (v1[i] == v2[j])
            count++;
        else
            rima = 0;

        i--;
        j--;
    }

    return rima;
}

void ret(char s1[], char s2[], int *isAss, int *isAll1, int *isAll2)
{
    int len1, len2, i, j, cont;
    char ch;
    int conta;

    for (len1 = 0; s1[len1] != '\0'; len1++)
        ;
    for (len2 = 0; s2[len2] != '\0'; len2++)
        ;
    cont = 0;
    *isAss = 1;
    j = 0;
    for (i = 0; i < len1 && cont < 2; i++)
    {
        if (isVowel(s1[len1 - 1 - i]))
        {
            //printf("Lettera del primo s: %c", s1[len1 - i -1]);
            for (; j < len2 && *isAss && cont < 2; j++)
            {
                //printf("For 2: %c\n", s2[len2 - j -1]);
                if (isVowel(s2[len2 - 1 - j]))
                {
                    if (s2[len2 - j - 1] != s1[len1 - i - 1] && cont < 1)
                        *isAss = 0;
                    else if (s2[len2 - j - 1] == s1[len1 - i - 1])
                        cont++;
                }
            }
        }
    }

    ch = s1[0];
    conta = 1;
    for (i = 1; i < len1 && conta < 3; i++)
    {
        if (s1[i] == ch && isspace(s1[i - 1]))
            conta++;
        else if (isspace(s1[i - 1]))
        {
            conta = 1;
            ch = s1[i];
        }
    }
    if (conta == 3)
        *isAll1 = 1;
    else
        *isAll1 = 0;

    ch = s2[0];
    conta = 1;
    for (i = 1; i < len2 && conta < 3; i++)
    {
        if (s2[i] == ch && isspace(s2[i - 1]))
            conta++;
        else if (isspace(s2[i - 1]))
        {
            conta = 1;
            ch = s2[i];
        }
    }
    if (conta == 3)
        *isAll2 = 1;
    else
        *isAll2 = 0;
}

int isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 1;
    return 0;
}

char all(char v[])
{
    int *count;
    char *letters;

    int numLetters;
    int i, j, k;
    int found;

    int max, tot;
    char maxLetter;

    letters = malloc(strlen(v) * sizeof(char));

    if (letters) {
        numLetters = 0;
        for (i = 0; v[i] != '\0'; i++)
        {
            v[i] = tolower(v[i]);
            found = 0;
            for (j = 0; j < numLetters && !found; j++)
            {
                if (v[i] == letters[j] && !isspace(v[i]))
                {
                    found = 1;
                }
            }
            if (!found && !isspace(v[i]))
            {
                *(letters + numLetters) = v[i];
                numLetters++;
            }
        }
    } else {
        printf("allitteration: failed allocating memory\n");
    }

    count = malloc(numLetters * sizeof(int));

    if(count) {
        for (i = 0; i < numLetters; i++)
        {
            *(count + i) = 0;
        }

        for (i = 0; v[i] != '\0'; i++)
        {
            for (j = 0; j < numLetters; j++)
            {
                if (v[i] == letters[j])
                {
                    *(count + j) += 1;
                }
            }
        }

        max = *count;
        maxLetter = *letters;
        tot = 0;
        for (i = 0; i < numLetters; i++)
        {
            if (*(count + i) > max)
            {
                max = *(count + i);
                maxLetter = *(letters + i);
            }
            /*printf("%c: ", *(letters + i));
            printf("%d - ", *(count + i));*/
            tot += *(count + i);
        }

        if (max >= tot / 5)
        {
            return maxLetter;
        }
    } else {
        printf("allitteration: failed allocating memory\n");
    }   

    return 0;
}