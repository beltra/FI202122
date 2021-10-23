#define MAXL 30
#define OPTMIN 0
#define OPTMAX 4
#define USATO 1
#define NONUSATO 0
int main(int argc, char *argv[])
{
    char parola1[MAXL + 1], parola2[MAXL + 1];
    char concatenata[MAXL * 2 + 1];
    int trovato[MAXL];
    int i, j, dim1, dim2, size, half;
    int isOK, scelta;
    do
    {
        do
        {
            printf("* *********************************************************\n");
            printf("* **************************MENU * **************************\n");
            printf("1. verifica se una stringa e’ palindrome\n");
            printf("2. verifica se due stringhe sono anagrammi\n");
            printf("3. concatena due stringhe, mettendo prima la piu’ corta\n");
            printf("4. concatena due stringhe, mettendo prima la piu’ lunga\n");
            printf("0. termina\n");
            printf("* *********************************************************\n");
            scanf("%d", &scelta);
        } while (!(scelta >= OPTMIN && scelta <= OPTMAX));
        if (scelta == 1)
        {
            scanf("%s", parola1);
            for (dim1 = 0; parola1[dim1] != ‘\0’; dim1++)
                ;
            size = dim1 - 1;
            half = dim1 / 2;
            isOK = 1;
            for (i = 0; i < half && isOK == 1; i++)
                if (parola1[i] != parola1[size - i])
                    isOK = 0;
            printf("%d\n", isOK);
        }
        else if (scelta == 2)
        {
            scanf("%s", parola1);
            scanf("%s", parola2);
            for (i = 0; i < MAXL; i++)
                trovato[i] = NONUSATO;
            isOK = 1;
            for (i = 0; parola1[i] != ‘\0’ && isOK; i++)
            {
                isOK = 0;
                for (j = 0; parola2[j] != ‘\0’ && isOK == 0; j++)
                    if (parola1[i] == parola2[j] && trovato[j] == NONUSATO)
                    {
                        trovato[j] = USATO;
                        isOK = 1;
                    }
            }
            printf("%d\n", isOK);
        }
        else if (scelta == 3)
        {
            scanf("%s", parola1);
            scanf("%s", parola2);
            for (dim1 = 0; parola1[dim1] != ‘\0’; dim1++)
                ;
            for (dim2 = 0; parola2[dim2] != ‘\0’; dim2++)
                ;
            if (dim1 <= dim2)
            {
                for (i = 0; parola1[i] != ‘\0’; i++)
                    concatenata[i] = parola1[i];
                for (j = 0; parola2[j] != ‘\0’; j++, i++)
                    concatenata[i] = parola2[j];
                concatenata[i] = ‘\0’;
            }
            else
            {
                for (i = 0; parola2[i] != ‘\0’; i++)
                    concatenata[i] = parola2[i];
                for (j = 0; parola1[j] != ‘\0’; j++, i++)
                    concatenata[i] = parola1[j];
                concatenata[i] = ‘\0’;
            }
            printf("%s\n", concatenata);
        }
        else if (scelta == 4)
        {
            scanf("%s", parola1);
            scanf("%s", parola2);
            for (dim1 = 0; parola1[dim1] != ‘\0’; dim1++)
                ;
            for (dim2 = 0; parola2[dim2] != ‘\0’; dim2++)
                ;
            if (dim1 >= dim2)
            {
                for (i = 0; parola1[i] != ‘\0’; i++)
                    concatenata[i] = parola1[i];
                for (j = 0; parola2[j] != ‘\0’; j++, i++)
                    concatenata[i] = parola2[j];
                concatenata[i] = ‘\0’;
            }
            else
            {
                for (i = 0; parola2[i] != ‘\0’; i++)
                    concatenata[i] = parola2[i];
                for (j = 0; parola1[j] != ‘\0’; j++, i++)
                    concatenata[i] = parola1[j];
                concatenata[i] = ‘\0’;
            }
            printf("%s\n", concatenata);
        }
    } while (scelta != 0);
    printf("bye\n");
    return 0;
}