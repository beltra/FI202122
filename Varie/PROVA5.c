#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    unsigned int giorno;
    unsigned int mese;
    unsigned int anno;
} data_t;

typedef struct
{
    unsigned int ora;
    unsigned int minuti;
} ora_t;

typedef ora_t *Ora_t;

typedef struct //coppia di coordinate
{
    float Lat;
    float Long;

} coordinate_t;

typedef struct nodoO_s //nodi orizzontali
{
    coordinate_t coordinate;
    //lista_tempo_t *nextV;//punatore altra lista (verticale)
    struct nodoV_s *nextV;
    struct nodoO_s *nextO; //puntatore all'elemento successivo orizzontale
} nodoO_t;

typedef nodoO_t *lista_posizioni_t; //lista nodi orizzontali

typedef struct nodoV_s //nodi verticali
{
    data_t data;
    ora_t Ora;
    int id_rilevatore;
    float PM;
    int cont;
    struct nodoV_s *nextV;
} nodoV_t;

typedef nodoV_t *lista_tempo_t; //lista nodi verticali

//generare un file con dati per 4 operatori su excel
//creo funzione che prendo da file e metto nelle due liste dati
lista_posizioni_t *leggi_file(char path1[], lista_posizioni_t *p_lista)
{
    char temp[50];        //variabile temporanea dove sovrascriver� prima riga file, tanto poi non utilizzata
    nodoO_t *currO;       //puntatore a nodo corrente orizzontale
    nodoO_t *nuovo_nodoO; //nuovo nodo orizzontale
    int i = 0;
    nodoV_t *currV;       //puntatore a nodo corrente orizzontale
    nodoV_t *nuovo_nodoV; //nuovo nodo orizzontale
    float latitudine, longitudine;
    int ANNO, MESE, GIORNO, ORA, MINUTI, ID;
    float pm;
    int trovata = 0;

    //apro il file in lettura
    FILE *fout;               //dichiaro file
    fout = fopen(path1, "r"); //apertura in lettura file

    if (fout == NULL) //controllo apertura
    {
        printf("errore nell'apertura del file");
    }

    while (feof(fout) == 0) //prendo le coordinate dal file e le inserisco nel nuovo nodo orizzontale
    {
        //prendo coordinata nodoO 1 e scorro tutta la lista, quando trovo lo stesso luogo aggiungo nodo verticale
        //aggiunto il nodo verticale scorro tutta la lista ancora e creo nuovo nodo verticale solo se abbiamo la stessa data/ora
        if (i == 0) //prima riga file excel-> la salvo in variabile temporanea poich� non � da utilizzare
        {
            fscanf(fout, "%s %s %s %s", temp, temp, temp, temp);
        }
        if (i == 1) //seconda riga file excel
        {
            fscanf(fout, "%s %s %s %s %s %s %s %s %s", temp, temp, temp, temp, temp, temp, temp, temp, temp); //salvo altri dati in variabile temp
        }
        if (i > 1) //tutte le altre righe del file excel,salvo i dati nelle variabili
        {
            fscanf(fout, "%d %f %f %d %d %d %d %d", &ID, &latitudine, &longitudine, &ANNO, &MESE, &GIORNO, &ORA, &MINUTI); //salvo coordinate nelle variabili
            //coordinate_t* coordinate=(coordinate_t*)malloc(sizeof(coordinate_t));//alloco dinamicamente dato poi
            nodoO_t *nuovo_nodoO = malloc(sizeof(nodoO_t)); //alloco dinamicamente nuovo nodo orizzontale
            nodoV_t *nuovo_nodoV = malloc(sizeof(nodoV_t)); //alloco dinamicamente nuovo nodo verticale
        }
        i++;

        if (*p_lista == NULL) //lista vuota posso farsi che puntatori puntino a data zona struttura
        {
            *p_lista = nuovo_nodoO;
            nuovo_nodoO->coordinate.Lat = latitudine; //inserisco i dati nella lista posizioni e nel primo nodo della lista tempi
            nuovo_nodoO->coordinate.Long = longitudine;
            nuovo_nodoO->nextV = nuovo_nodoV;
            nuovo_nodoV->data.anno = ANNO;
            nuovo_nodoV->data.mese = MESE;
            nuovo_nodoV->data.giorno = GIORNO;
            nuovo_nodoV->Ora.ora = ORA;
            nuovo_nodoV->Ora.minuti = MINUTI;
            nuovo_nodoV->cont = 1;
            nuovo_nodoV->PM = pm;
            nuovo_nodoO->nextO = nuovo_nodoO;
        }
        else //lista non vuota-> controllo se non ci siano la stessa posizione (stesso luogo)
        {
            currO = *p_lista;
            while (currO->nextO != NULL) //scorro la lista cercando la posizione
            {
                if ((longitudine != currO->coordinate.Long && latitudine != currO->coordinate.Lat) || (longitudine == currO->coordinate.Long && latitudine != currO->coordinate.Lat) || (longitudine != currO->coordinate.Long && latitudine == currO->coordinate.Lat)) //posizione assente
                    currO = currO->nextO;                                                                                                                                                                                                                               //continuo a scorrere la lista, non ho trovato l stessa posizione
                else                                                                                                                                                                                                                                                    //posizione gia inserita
                    trovata = 1;
            }
        }
        if (trovata == 0) //posizione assente: inserisco i dati nella lista posizioni e nel primo nodo della lista tempi
        {
            nuovo_nodoO->coordinate.Lat = latitudine;
            nuovo_nodoO->coordinate.Long = longitudine;
            nuovo_nodoO->nextV = nuovo_nodoV;
            nuovo_nodoV->data.anno = ANNO;
            nuovo_nodoV->data.mese = MESE;
            nuovo_nodoV->data.giorno = GIORNO;
            nuovo_nodoV->Ora.ora = ORA;
            nuovo_nodoV->Ora.minuti = MINUTI;
            nuovo_nodoV->cont = 1;
            nuovo_nodoV->PM = pm;
            currO->nextO = nuovo_nodoO; //puntatore a un eventuale nodo posizione successivo
        }
        else //posizione presente: controllo di non avere dati rilevati nello stesso momento
        {
            currV = currO->nextV;
            while (currV->nextV != NULL)
            {
                if (currV->data.anno != ANNO || currV->data.mese != MESE || currV->data.giorno != GIORNO || currV->Ora.ora != ORA || currV->Ora.minuti != MINUTI)
                {
                    currV = currV->nextV; //scorro fino alla fine supponendo che i dati siano forniti in ordine cronologico
                }
                else
                {
                    currV->cont++;                                //incremento il numero di rilevamenti effettuati nello stesso posto alla stessa ora
                    currV->PM = (currV->PM + pm) / (currV->cont); //media rlevamento
                }
            }
            if (currV->nextV == NULL) //tempo assente
            {
                currV->nextV = nuovo_nodoV;
                nuovo_nodoV->data.anno = ANNO;
                nuovo_nodoV->data.mese = MESE;
                nuovo_nodoV->data.giorno = GIORNO;
                nuovo_nodoV->Ora.ora = ORA;
                nuovo_nodoV->Ora.minuti = MINUTI;
                nuovo_nodoV->cont = 1;
                nuovo_nodoV->PM = pm;
            }
        }
    }
    fclose(fout);
    return p_lista;
}

//funzione che riceve la lista e le coordinate da cercare e calcoa media dell'ultima ora e fornisce un elenco di orari
void Media(lista_posizioni_t p_lista, float LAT, float LONG)
{
    int trovata = 0, j, i;
    nodoO_t *curr;
    nodoV_t *attuale;
    curr = p_lista;
    float Apm[15];
    data_t DATA[15];
    ora_t ORA[15];
    float media;
    int k = 1;

    while (curr->nextO != NULL)
    {
        if (curr->coordinate.Lat == LAT && curr->coordinate.Long == LONG) //la posizione inserita e presente
            trovata = 1;
        else
            printf("Non ci sono rilevazioni nella posizione inserita!");
    }

    attuale = curr->nextV; //primo nodo della lista verticale
    if (trovata == 1)      //se la posizione e presente devo calcolare la media dei valori nell'utima ora rilevata e stampare tutti i valori
    {
        while (attuale->nextV != NULL) //scorro la lista e salvo i valori negli array
        {
            for (i = 0; i < 15; i++)
            {
                Apm[i] = attuale->PM;
                DATA[i] = attuale->data;
                ORA[i] = attuale->Ora;
                attuale = attuale->nextV;
            }
        }
    }

    if (k < 15)
    {
        for (i = 15; i > 0; i--)
        {
            if (ORA[i].ora + ORA[i].minuti - ORA[i - k].ora - ORA[i - k].minuti > 1) //la rilevazione precedente e stata fatta a pi� di un'ora di distanza
            {
                media = Apm[i];
            }
            else
            {
                media = (Apm[i] + Apm[i - k]) / k;
                k++;
            }
        }
    }
    printf("La media delle rilevazioni datte nel punto di coordinate %f %f nell'ultima ora e' %f", LAT, LONG, media);
    for (i = 0; i < 15; i++)
    {
        printf("La lista delle rilevazioni e': %f, %d, %d\n", Apm[i], DATA[i].giorno, ORA[i].ora);
    }
}

int main()
{
    lista_posizioni_t *lista, *p_lista;
    float latitudine, longitudine; //coordinate
    int n = 1;

    lista = leggi_file("input.csv", *p_lista);
    while (n == 1)
    {
        printf("Inserisci le coordinate di un luogo: ");
        scanf("%f", &latitudine);
        scanf("%f", &longitudine);
        Media(lista, latitudine, longitudine);
        printf("Vuoi inserire una nuova posizione? (1=SI; 2=NO)");
        scanf("%d", &n);
    }
    return 0;
}