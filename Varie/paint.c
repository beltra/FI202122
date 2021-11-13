#include <stdio.h>

#define BLACK 1
#define WHITE 0
#define SIZE 10

void visualizza(int [][SIZE], int);
void propaga(int [][SIZE], int, int, int);

int main(int argc, char * argv[])
{
  int mat[SIZE][SIZE];
  int i, j;
  int posx, posy;

  /* contenuto casuale */
  for(i = 0; i < SIZE; i++)
    for(j = 0; j < SIZE; j++)
      mat[i][j] = (mat[i][j] % 2)*(mat[i][j] % 2);

  visualizza(mat, SIZE);
  do
    scanf("%d%d", &posx, &posy);
  while(!(posx >= 0 && posx < SIZE) || !(posy >= 0 && posy < SIZE));
  propaga(mat, SIZE, posx, posy);
  visualizza(mat, SIZE);
  return 0;
}

void visualizza(int m[][SIZE], int dim)
{
  int i, j;

  for(i = 0; i < SIZE; i++){
    for(j = 0; j < SIZE; j++)
      printf("%d", m[i][j]);
    printf("\n");
  }
  return;
}

void propaga(int m[][SIZE], int dim, int riga, int col)
{
  /* il passo base e' implicito: se la casella e' nera non c'e' nulla da fare */
  if(m[riga][col] == WHITE){
    m[riga][col] = BLACK;
    if(riga > 0 && m[riga-1][col] == WHITE)
      propaga(m, dim, riga-1, col);
    if(riga < SIZE-1 && m[riga+1][col] == WHITE)
      propaga(m, dim, riga+1, col);
    if(col > 0 && m[riga][col-1] == WHITE)
      propaga(m, dim, riga, col-1);
    if(col < SIZE-1 && m[riga][col+1] == WHITE)
      propaga(m, dim, riga, col+1);
  }
  return;
}