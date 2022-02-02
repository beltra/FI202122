int main ()
{
    int i, j;
    for (i = 0; i < N_PART; i++)
    {
        for (j = 0; j < N_PART; j++)
        {
            if (VP[i][j] != 0 || VG[i][j] != 0)
                printf("Una nazione ha votato per se stessa\n");
        }
    }
}