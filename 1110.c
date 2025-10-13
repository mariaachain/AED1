#include <stdio.h>
#define MAX_SIZE 101

int main() {
    int n;

    // O loop continua enquanto scanf conseguir ler um inteiro e ele não for 0.
    while (scanf("%d", &n) == 1 && n != 0) {
        
        if (n == 1) {
            printf("Discarded cards:\n");
            printf("Remaining card: 1\n");
            continue;
        }

        //  Simulação da Fila
        int queue[MAX_SIZE];
        int front = 0; // Índice do início da fila (topo da pilha)
        int rear = n;  // Índice da primeira posição livre no final da fila

        // Inicializa a fila com as cartas de 1 a n
        for (int i = 0; i < n; i++) {
            queue[i] = i + 1;
        }

        // Armazenamento das cartas descartadas
        int discarded_cards[MAX_SIZE];
        int discarded_count = 0;

        // O processo continua enquanto houver 2 ou mais cartas na pilha
        while (rear - front >= 2) {
            // 1. Joga fora a carta do topo: remove da frente da fila
            discarded_cards[discarded_count++] = queue[front++];

            // 2. Move a próxima carta para a base: remove da frente e adiciona ao final
            queue[rear++] = queue[front++];
        }

      
        printf("Discarded cards: ");
        for (int i = 0; i < discarded_count; i++) {
            printf("%d", discarded_cards[i]);
            // Adiciona a vírgula e o espaço, exceto para a última carta
            if (i < discarded_count - 1) {
                printf(", ");
            }
        }
        printf("\n");

        // A carta restante é a única que sobrou na fila
        printf("Remaining card: %d\n", queue[front]);
    }

    return 0;
}110.c
