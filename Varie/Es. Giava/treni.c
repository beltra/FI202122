#include <stdio.h>
#define MAXTRENI 30
#define MAXGIORNI 31

int main()
{
    int i, j, k = 0, somma = 0, indice, ritardi[MAXTRENI][MAXGIORNI];
    for (i = 0; i < MAXTRENI; i++)
    {
        for (j = 0; j < MAXGIORNI; j++)
        {
            if (ritardi[i][j] == -1)
                k = k + 1;
        }
        if (k > somma)
        {
            indice = i;
            somma = k;
        }
        k = 0;
    }
    printf("IL treno con più ritardi e' quello: %d", indice);
    int treniCancellati[MAXTRENI], s = 0;
    for (i = 0; i < MAXTRENI; i++)
    {
        for (j = 0; j < MAXGIORNI; j++)
        {
            if (ritardi[i][j] == -1)
            {
                treniCancellati[s] = i;
                s = s + 1;
                printf(" %d", i);
                break;
            }
        }
    }
    return 0;
}


#define NT 5
#define NG 5

    int ritardi[NT][NG] = {{9, 0, 4, 0, 2},
                           {-1, 1, 7, 6, -1},
                           {2, 6, 3, -1, 6},
                           {9, 2, 6, 5, 2},
                           {0, 9, -1, -1, 4}};

int main()
{

    int indice_max_cancellazioni = 0;
    int max_cancellazioni = 0;

    int contatore_cancellazioni;
    int i, t, g;
    int treniCancellati[NT];
    int num_cancellati = 0;
    int treno_cancellato;

    for (t = 0; t < NT; t++)
    {
        contatore_cancellazioni = 0;
        for (g = 0; g < NG; g++)
            if (ritardi[t][g] == -1)
                contatore_cancellazioni++;

        if (contatore_cancellazioni >= max_cancellazioni)
        {
            max_cancellazioni = contatore_cancellazioni;
            indice_max_cancellazioni = t;
        }
    }
    printf("Il treno con il maggior numero di cancellazioni è stato il %d\n",
           indice_max_cancellazioni);

    for (t = 0; t < NT; t++)
    {
        treno_cancellato = 0;
        for (g = 0; g < NG && treno_cancellato == 0; g++)
            if (ritardi[t][g] == -1)
                treno_cancellato = 1;

        if (treno_cancellato)
        {
            treniCancellati[num_cancellati] = t;
            num_cancellati++;
        }
    }

    printf("I treni cancellati sono: ");
    for (i = 0; i < num_cancellati; i++)
    {
        printf("%d ", treniCancellati[i]);
    }
    printf("\n");
}