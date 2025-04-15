#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (i < 9) {
        printf("0%d ", i + 1);
      } else {
        printf("%d ", i + 1);
      }
    }
    printf("\n");
  }

  printf("\n");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if(j < 9){
        printf("0%d ", j + 1);
      } else{
        printf("%d ", j + 1);
      } 
    }
    printf("\n");
  }
  printf("\n");
  return 0;
} 