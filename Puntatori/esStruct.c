/*
*   Passaggio di strutture
*/

void cercaDate(data_t nascita[], data_t dataRif, int *stessoGiorno, int *stessaData) {

}

/*
*   Passare intere strutture è identico a passare una qualunque altra variabile o array di variabili
*   Ciò significa copiare nel record di attivazione l'intera struttura.
*   È quindi preferibile passare per indirizzo le strutture.
*/

/* Ricevuto in ingresso un array di date e la sua dimensione, restituire la più vecchia e la più recente */

void finestraDate(data_t date[], int dim, data_t *minDate, data_t *maxDate) {
    int i;
    data_t min, max;

    min = date[0];
    max = date[0];
    for (i = 0; i < dim; i++) {
        if (antecedente(date[i], min)) {
            max = date[i];
        } else if (antecedente(max, date[i])) {
            min = date[i];
        }
    }

    *minDate.d = min.d  
    *minDate.m = min.m
    *minDate.y = min.y

    /* Ciò è equivalente a */
    minDate -> d = min -> d
    minDate -> m = min -> m
    minDate -> y = min -> y
}

int antecedente(date_t date1, date_t date2) {

    /* Scrivere date1 < date2 è SBAGLIATO, poichè confronta gli indirizzi di date1 e date2 */

    if ((date1.d > date2.d && date1.m == date2.m && date1.y == date2.y ) || 
        (date1.m > date2.m && date1.y == date2.y) || (date1.y > date2.y))
    {
        return 0;
    }
    else if ((date1.d < date2.d && date1.m == date2.m && date1.y == date2.y ) || 
            (date1.m < date2.m && date1.y == date2.y) || (date1.y < date2.y))
    {
        return 1;
    }
}

