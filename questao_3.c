#include <stdio.h>

int main() {
  int num, primo, qtd;

  scanf("%d", &num);
  primo = 2;
  qtd = 0;

  if (num == 0 || num == 1) {
    printf("%d^1\n", num);
    return 0;
  }

  while (num != 1) {
    if (num % primo == 0) {
      num = num / primo;
      qtd++;
    } else {
      if (qtd > 0) {
        printf("%d^%d * ", primo, qtd);
      }

      qtd = 0;
      primo++;
    }
  }

  printf("%d^%d\n", primo, qtd);
  return 0;
}
