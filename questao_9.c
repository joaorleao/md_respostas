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

int calcular_equacao(int a, int m, int M, int *res) {
  int Ma, M_, M_1, t;

  Ma = M / m;
  M_ = Ma % m;

  if (calcular_comb_mdc(M_, m, &M_1, &t) != 1) {
    return 0;
  }

  if (M_1 < 0) {
    M_1 += m;
  }

  *res = a * Ma * M_1;
  return 1;
}

int main() {
  int qtd_equacoes, M, i, soma, resultado, aux, a[3], m[3];

  qtd_equacoes = 3;
  M = 1;
  soma = 0;

  for (i = 0; i < qtd_equacoes; i++) {
    printf("Digite dois números inteiros: ");
    scanf("%d%d", &a[i], &m[i]);
    M *= m[i];
  }

  for (i = 0; i < qtd_equacoes; i++) {
    if (!calcular_equacao(a[i], m[i], M, &aux)) {
      printf("Sem solução\n");
      return 0;
    }

    soma += aux;
  }

  resultado = soma % M;
  printf("%d\n", resultado);

  return 0;
}
