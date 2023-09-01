#include <stdio.h>

int calcular_comb_mdc(int num1, int num2, int *s, int *t) {
  int a, b, s1, t1, qtd, aux, i;

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

  s1 = 0;
  t1 = 1;
  for (i = 0; i < qtd - 1; i++) {
    aux = t1;
    t1 = s1 + t1 * q[qtd - i - 2];
    s1 = aux;
  }

  if ((qtd - 1) % 2 == 0) {
    s1 *= -1;
  } else {
    t1 *= -1;
  }

  *s = s1;
  *t = t1;
  return a;
}

int main() {
  int num1, num2, num3, s, t, mdc, x;

  printf("Digite três números inteiros: ");
  scanf("%d%d%d", &num1, &num2, &num3);

  mdc = calcular_comb_mdc(num1, num3, &s, &t);

  if (mdc != 1) {
    printf("A congruência não tem solução\n");
    return 0;
  }

  x = (s * num2) % num3;

  if (x < 0) {
    x += num3;
  }

  printf("%d\n", x);
  return 0;
}
