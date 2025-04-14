#include <stdio.h>

long long int fat(long long int num) {
  if (num <= 1) return 1;
  return num * fat(num - 1);
}

long long int elevado(long long int base, long long int exp) {
  if (exp == 1) return base;
  return base * elevado(base, exp - 1);
}

int main() {
  long long int a, b, c;
  scanf("%lld %lld\n%lld", &a, &b, &c);
  long long int pedro = fat(c);
  long long int lucas = elevado(a, b);

  if (pedro > lucas)
    printf("Pedro\n");
  else
    printf("Lucas\n");
  
  return 0;
}