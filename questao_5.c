#include <stdio.h>

int main() {
  int a, b, aux;

  scanf("%d%d", &a, &b);

  while (b != 0) {
    aux = b;
    b = a % b;
    a = aux;
  }

  printf("MDC = %d\n", a);
  return 0;
}
