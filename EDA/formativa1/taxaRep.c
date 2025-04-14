#include <stdio.h>
#include <stdlib.h>


int main() {
  int d;
  scanf("%d", &d);
  
  int a, s, m, c, matri, apro;
  
  while(scanf("%d %d %d", &a, &s, &m) != EOF){
    int cod[m], rep[m], codrep[m], cont = 0;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &c, &matri, &apro);
        cod[i] = c;
        rep[i] = matri - apro;
    }

    //acha o maior num de reprovados
    int maior = rep[0];
    for (int i = 1; i < m; i++) {
        if (rep[i] > maior) {
            maior = rep[i];
        }
    }
    
    // Guarda os codigos com essas disciplinas de mais reprovados
    for (int i = 0; i < m; i++)
    {
        if (rep[i] == maior)
        {
            codrep[cont] = cod[i];
            cont++;
        }
    }

    for (int i = 0; i < cont - 1; i++) {
        for (int j = 0; j < cont - i - 1; j++) {
            if (codrep[j] > codrep[j + 1]) {
                int temp = codrep[j];
                codrep[j] = codrep[j + 1];
                codrep[j + 1] = temp;
            }
        }
    }

    printf("%d/%d\n", a, s);

    for (int i = 0; i < cont; i++)
    {
        printf("%d ", codrep[i]);
    }

    printf("\n\n");    
    
  }
  
  return 0;
}
