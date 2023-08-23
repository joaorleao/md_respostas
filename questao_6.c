#include <stdio.h>

int alg_euclides_lim(int a, int b, int qtd) {
  int aux, q;
  q = a / b;
  while (qtd > 0) {
    aux = b;
    b = a % b;
    a = aux;
    q = a / b;
    qtd -= 1;
  }
  return q;
}

int main() {
  int num1, num2, a, b, q, s, t, qtd, aux, i;

  scanf("%d%d", &num1, &num2);
  a = num1;
  b = num2;

  qtd = 0;
  while (b != 0) {
    aux = b;
    b = a % b;
    a = aux;
    qtd += 1;
  }

  s = 0;
  t = 1;
  for (i = 0; i < qtd - 1; i++) {
    q = alg_euclides_lim(num1, num2, qtd - i - 2);
    aux = t;
    t = s + t * q;
    s = aux;
  }

  if ((qtd - 1) % 2 == 0) {
    s *= -1;
  } else {
    t *= -1;
  }

  printf("s = %d e t = %d\n", s, t);
  printf("%d = %d * %d + %d * %d\n", a, s, num1, t, num2);
  return 0;
}