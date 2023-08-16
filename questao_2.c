#include <math.h>
#include <stdio.h>
#include <time.h>

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
  time_t comeco, agora;

  num = 1;
  time(&comeco);
  agora = comeco;

  while (agora - comeco < 60) {
    if (e_primo(num)) {
      printf("%d\n", num);
    }

    num++;
    time(&agora);
  }

  return 0;
}
