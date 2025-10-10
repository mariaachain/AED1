#include <stdio.h>
int main() {
    int N;

    scanf("%d", &N);

  
    int X[N];
    int i;


    for (i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    // Assume que o primeiro elemento é o menor para iniciar 
    int menor_valor = X[0];
    int posicao = 0;

    // Percorre o vetor a partir do segundo elemento 
    for (i = 1; i < N; i++) {
        if (X[i] < menor_valor) {
            menor_valor = X[i];
            posicao = i;
        }
    }

    // Imprime o resultado
    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
