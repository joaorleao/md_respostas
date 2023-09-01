#include <stdio.h>

int main() {
  int num1, num2, a, b, s, t, qtd, aux, i;

  printf("Digite dois números inteiros: ");
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

  a = num1;
  b = num2;
  i = 0;
  int q[qtd];

  while (b != 0) {
    q[i++] = a / b;
    aux = b;
    b = a % b;
    a = aux;
  }

  s = 0;
  t = 1;
  for (i = 0; i < qtd - 1; i++) {
    aux = t;
    t = s + t * q[qtd - i - 2];
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
