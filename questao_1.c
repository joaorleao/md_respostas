#include <math.h>
#include <stdio.h>

int e_primo(int num) {
  int limite;
  limite = ceil(sqrt(num + 1));

  for (int i = 2; i < limite; i++) {
    if (num % i == 0) {
      return 0;
    }
  }

  return 1;
}

int main() {
  int num;

  scanf("%d", &num);

  if (e_primo(num)) {
    printf("É primo\n");
  } else {
    printf("Não é primo\n");
  }

  return 0;
}
