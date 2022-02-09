#include <stdio.h>
#define MAX_STANZE 10
#define N_MAX_APPARTAMENTI 20

typedef enum
{
    bagno,
    cucina,
    camera
} tipo_stanza;

typedef struct
{
    int dim_metri_quadr;
    tipo_stanza tipo;
    int numero_balconi;
} Stanza;

typedef struct
{
    char indirizzo[20];
    int costo_m_quadro;
    int numero_stanze[10];
    int bagni;
    Stanza stanze[MAX_STANZE];
} Appartamento;

Appartamento agenzia_immobiliare[N_MAX_APPARTAMENTI];

int main ()
{
    int i, j, costo = 10000000000, parziale = 0, indice;
    char copia_ind[20];
    for (i = 0; i < N_MAX_APPARTAMENTI; i++)
    {
        if (agenzia_immobiliare[i].bagni >= 2)
        {
            for (j = 0; j < MAX_STANZE; j++)
            {
                parziale = parziale + agenzia_immobiliare[i].stanze[j].dim_metri_quadr * agenzia_immobiliare[i].costo_m_quadro;
            }
            if (parziale < costo)
            {
                costo = parziale;
                copia_ind = agenzia_immobiliare[i].indirizzo;
            }
        }
        parziale = 0;
    }
    printf("%s", copia_ind);
    printf(" %d", costo);
    return 0;
}