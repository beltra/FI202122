int losers[N_PART], s = 0;
for (i = 0; i < N_PART; i++)
{
    if (vett[i] == 0)
    {
        losers[s] = i;
        s = s + 1;
    }
}
printf("Il numero di nazioni senza voto e': %d", s);
return 0;