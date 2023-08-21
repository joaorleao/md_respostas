#include <stdio.h>

int euclides(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return alg_euclides(b, a % b);
  }
}

void coeficientes(int a, int b, int n, int x) {
  int y;
  y = euclides(a, b);

  if (n < 0 || n > b) {
    if (a * n + b * x == x) {
      n = n % b;
    }
  } else {
    printf("%d  %d\n", n, x);
    if (a * n + b * x == y) {
      printf("S=%d, T=%d", n, x);
      return;
    } else if (a * n - b * x == y) {
      printf("TESTE\n");
      printf("S=%d, T=-%d", n, x);
      return;
    } else if (-a * n + b * x == y) {
      printf("S=-%d, T=%d", n, x);
    } else {
      if (n == b) {
        x++;
        n = 1;
        coeficientes(a, b, n, x);
      } else {
        n++;
        coeficientes(a, b, n, x);
      }
    }
  }
}

int main() {
  int a, b;

  scanf("%d%d", &a, &b);
  coeficientes(a, b, 1, 1);

  return 0;
}
