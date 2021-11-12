/*
*   Esistono anche due altri modi di aprire un file, "rb" e "wb", che permettono di accedere direttamente al
*   binario contenuto nel file
*/

fread(tipo* /* Dove li metto*/, size_t /* Dimensione del singolo dato*/, int /* Quanti elementi */, fin /* Da dove leggo */);

/*
*   Per avere la dimensione di un tipo di dato si usa
*/

sizeof(/* nome tipo*/);

/* restituisce una variabile di tipo size_t */

/* Quindi per es. */

fread(v, sizeof(int), 5, fin);

/* È inutile usare un ciclo for per mettere 5 valori in un array */
/* Solitamente si scrive all'inzio del file il numero di dati utili, per poi leggerli con una fread */

/* Per scrivere dati in binario invece si usa */

fwrite(indirizzo, sizeof(/*Tipo*/), int /*Numero dati*/, FILE* /* stream */);
