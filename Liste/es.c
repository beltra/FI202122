/* Preso il primo numero, con una malloc alloco uno spazio di memoria per il primo numero
*  È necessario però poter far riferimento anche al dato successivo. Si usa quindi una struttura dati
*  che contiene il valore e un indirizzo
*/

/* L'ultimo elemento della lista ha indirizzo null, tutti gli altri puntano all'elemento successivo */
/* È un'allocazione di memoria dinamica, ma non viene fatto in un unico momento, bensì un elemento per volta */

/* Ogni elemento è un tipo formato da */
typedef struct listint_s {
    int num;
    struct listint_s *next;
} listi_t;

typedef struct listdate_s {
    int giorno, mese, anno;
    struct listdate_s *next;
} listdate_t;

/* Per usare una lista ho bisogno di una testa */
listi_t *head = NULL;    // ogni testa va inizializzata a NULL, poichè la lista nasce sempre vuota

/* L'ultimo elemento della lista ha puntatore NULL, per segnalare che dopo non c'è altro */

/* Inserimento in testa alla lista */
// 1. Alloco la memoria
// 2. Assegno al puntatore di questo nuovo elemento l'indirizzo puntato dalla testa
// 3. Assegno alla testa l'indirizzo di questo nuovo elemento

/* Inserimento in coda alla lista (append) */
// 1. Alloco la memoria
// 2. Assegno al puntatore dell'ultimo elemento l'elemento nuovo (scorro la lista, finchè non arrivo all'attuale ultimo)
// 3. Assegno NULL al puntatore del nuovo elemento

/* Inserimento ordinato */
// 1. Alloco la memoria
// 2. Controllo in quale posizione inserire l'elemento
// 3. Assegno al nuovo elemento l'indirizzo all'elemento successivo e all'elemento precedente l'indirizzo del nuvoo elemento

/* Eliminazione di un elemento */
// 1. Cerco l'elemento precedente
// 2. Cambio il suo puntatore all'elemento successivo
// 3. Libero la memoria relativa all'elemento eliminato