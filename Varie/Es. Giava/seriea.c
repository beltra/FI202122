#include <stdio.h>

typedef struct
{
    char cognome[20];
    int eta;
    int numero_maglia;
    int presenze;
    int gol;
} calciatore_t;

typedef struct
{
    calciatore_t calciatori[23];
    char nome[30];
    int punti;
} squadra_t;

typedef struct {
    squadra_t squadra[20];
} campionato_t;

int main()
{
    campionato_t serieA;
    int i, j, team, giocatore, goal = 0, age = 1000;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 23; j++)
        {
            if (serieA.squadra[i].calciatori[j].gol > goal)
            {
                goal = serieA.squadra[i].calciatori[j].gol;
                giocatore = j;
                team = i;
                age = serieA.squadra[i].calciatori[j].eta;
            }
            if (serieA.squadra[i].calciatori[j].gol == goal)
            {
                if (serieA.squadra[i].calciatori[j].eta < age)
                {
                    goal = serieA.squadra[i].calciatori[j].gol;
                    giocatore = j;
                    team = i;
                    age = serieA.squadra[i].calciatori[j].eta;
                }
            }
        }
    }
    printf("%s %d %d %s", serieA.squadra[team].calciatori[giocatore].cognome, goal, serieA.squadra[team].calciatori[giocatore].presenze, serieA.squadra[team].nome);
    return 0;
}