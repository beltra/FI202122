/*
*   Definire un tipo adatto a rappresentare date e uno per
*   rappresentare una persona con nome, cognome, data di nascita, inserimento, studente
*/

typedef struct date_s {
    int giorno, mese, anno;
} date_t;

typedef struct persona_s {
    char nome[LEN+1], cognome[LEN+1];
    char matricola[LENM+1];
    date_t dataN, dataIn;
    int studente;
} persona_t;