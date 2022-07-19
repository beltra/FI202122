typedef struct data_s {
  int numero;
  char carattere;
  float virgola;
} data_t;

int main() {
  data_t d;
  scanf("%d %c %f", &d.numero, &d.carattere, &d.virgola);
  
  printf("%d %c %f\n", d.numero, d.carattere, d.virgola);

  return 0;
}