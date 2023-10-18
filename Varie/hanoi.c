#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 20
#define TOWER_NUM 3   // >= 3

typedef struct tower_s
{
    char *disks;
    int height;
    int id;
} tower_t;

void printTower(tower_t t)
{
    int i = 0;
    printf("Torre %d: ", t.id);
    while (t.disks[i] != '\0')
    {
        printf("%c ", t.disks[i]);
        i++;
    }
    printf("\n");
}

void hanoi(int n, int from, int to, int temp, tower_t towers[])
{
    int i;
    if (n == 0)
    {
        return;
    }
    else
    {
        // Move n-1 disks from from tower to temp tower
        hanoi(n - 1, from, temp, to, towers);
        // Move last disk from from tower to to tower
        printf("Muovo il disco %c dalla torre %d alla torre %d\n", towers[from].disks[towers[from].height - 1], from+1, to+1);
        towers[to].disks[towers[to].height] = towers[from].disks[towers[from].height - 1];
        towers[to].height++;
        towers[to].disks[towers[to].height] = '\0';
        towers[from].height--;
        towers[from].disks[towers[from].height] = '\0';
        for (i = 0; i < TOWER_NUM; i++)
        {
            printTower(towers[i]);
        }
        // Move n-1 disks from temp tower to to tower
        hanoi(n - 1, temp, to, from, towers);
    }
}

int main()
{
    tower_t towers[TOWER_NUM];
    int i;
    int height;

    int from = 0;
    int temp = 1;
    int to = 2;

    printf("Inserisci l'altezza della torre 1: ");
    scanf("%d", &height);

    // Initialize and allocate memory for all towers
    for (i = 0; i < TOWER_NUM; i++)
    {
        towers[i].disks = malloc(sizeof(char) * (height + 1));
        towers[i].height = 0;
        towers[i].id = i + 1;
        if (towers[i].disks == NULL)
        {
            printf("Errore nell'allocazione della memoria");
            exit(1);
        }
        towers[i].disks[0] = '\0';
    }

    // Populate first tower
    for (i = 0; i < height; i++)
    {
        towers[0].disks[height - i - 1] = 'A' + i;
        towers[0].height++;
    }
    towers[0].disks[height] = '\0';

    hanoi(height, from, to, temp, towers);

    for (i = 0; i < TOWER_NUM; i++)
    {
        free(towers[i].disks);
    }

    return 0;
}