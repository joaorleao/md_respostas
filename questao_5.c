#include <stdio.h>

int alg_euclides(int a, int b) {
  int aux;
  while (b != 0) {
    aux = b;
    b = a % b;
    a = aux;
  }
  return a;
}

int main() {
  int num1, num2;

  printf("Digite dois números inteiros: ");
  scanf("%d%d", &num1, &num2);

  printf("MDC = %d\n", alg_euclides(num1, num2));
  return 0;
}
