#include <stdio.h>

int main() {
  int num1, num2, mdc, mmc, primo, divide1, divide2;

  scanf("%d%d", &num1, &num2);
  mdc = 1;
  mmc = 1;
  primo = 2;

  while (num1 != 1 || num2 != 1) {
    divide1 = num1 % primo == 0;
    divide2 = num2 % primo == 0;

    if (divide1) {
      num1 /= primo;
    }

    if (divide2) {
      num2 /= primo;
    }

    if (divide1 && divide2) {
      mdc *= primo;
    }

    if (divide1 || divide2) {
      mmc *= primo;
    }

    if (!divide1 && !divide2) {
      primo++;
    }
  }

  printf("MDC: %d\nMMC: %d\n", mdc, mmc);
  return 0;
}
