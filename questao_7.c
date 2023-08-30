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

int calcular_comb_mdc(int num1, int num2, int *s, int *t) {
  int a, b, q, s1, t1, qtd, aux, i;

  a = num1;
  b = num2;

  qtd = 0;
  while (b != 0) {
    aux = b;
    b = a % b;
    a = aux;
    qtd += 1;
  }

  s1 = 0;
  t1 = 1;
  for (i = 0; i < qtd - 1; i++) {
    q = alg_euclides_lim(num1, num2, qtd - i - 2);
    aux = t1;
    t1 = s1 + t1 * q;
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
  int num1, num2, s, t, mdc;

  printf("Digite dois números inteiros: ");
  scanf("%d%d", &num1, &num2);

  mdc = calcular_comb_mdc(num1, num2, &s, &t);

  if (mdc != 1) {
    printf("Não existe inverso modular\n");
    return 0;
  }

  printf("%d\n", s);
  return 0;
}
