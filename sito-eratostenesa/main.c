#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  unsigned long long int range = 0;
  unsigned long long int root = 0;

  printf("Podaj zakres do którego znać chcesz liczby pierwsze wszystkie: ");
  scanf("%llu", &range);
  root = sqrt(range);

  unsigned long long int* tablica = malloc(range * sizeof(*tablica));

  int base;
  for(unsigned long long int i = 2; i <= root; i++) {
    if(tablica[i] != 0) {
      base = tablica[i];

      for(unsigned long long int k = 2; k * base <= range; k++) {
        tablica[k * base] = 0;
      }
    }
  }
  for(unsigned long long int i = 2; i <= range; i++) {
    if(tablica[i])
      printf("%llu\n", tablica[i]);
  }
}
