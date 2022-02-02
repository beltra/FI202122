int vett[N_PART], max = 0, ind;
for (i = 0; i < N_PART; i++)
{
    for (j = 0; j < N_PART; j++)
    {
        vett[i] = VG[j][i] + VP[j][i];
    }
    if (vett[i] > max)
    {
        max = vett[i];
        ind = i;
    }
}
printf("La nazione vincitrice è %d", ind);
printf("totalizzando %d", max);