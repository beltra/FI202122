int k, contatore = 0, somma = 0;
for (i = 0; i < N_PART; i++)
{
    for (j = 0; j < N_PART; j++)
    {
        if (VG > 0 || VG <= 10)
        {
            for (k = 0; k < N_PART; k++)
            {
                if (VG[i][k] == VG[i][j] && k != j)
                {
                    printf("Qualcuno ha votato con un stesso voto\n");
                    contatore = 1;
                }
                if (contatore == 0)
                    somma = somma + 1;
                contatore = 0;
            }
        }
    }
    if (somma == 10)
        printf("La votazione è avventuta correttamente\n");
    else
        printf("La votazione non è avventuta correttamente\n");
    somma = 0;
}
