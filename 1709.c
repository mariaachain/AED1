#include <stdio.h>

int main() {
    int total_cartas;
    
    scanf("%d", &total_cartas);

    int metade = total_cartas / 2;
    int posicao_atual = 1;
    int quantidade_embaralhamentos = 0;

    do {
        if (posicao_atual < metade) {
            posicao_atual = 2 * posicao_atual + 1;
        } else {
            posicao_atual = 2 * (posicao_atual - metade);
        }
        
        quantidade_embaralhamentos++;
        
    } while (posicao_atual != 1);

    printf("%d\n", quantidade_embaralhamentos);

    return 0;
}
