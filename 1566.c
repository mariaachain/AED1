#include <stdio.h>
#include <string.h> 

// Define as alturas mínima e máxima para facilitar a leitura do código
#define MIN_ALTURA 20
#define MAX_ALTURA 230
#define TAMANHO_FREQUENCIA (MAX_ALTURA + 1)

void ordenarAlturas() {
    int n; 
    scanf("%d", &n);

    // Inicializa todas as posições com 0.
    int frequencia[TAMANHO_FREQUENCIA];
    memset(frequencia, 0, sizeof(frequencia));

    // Lê todas as n alturas e atualiza o contador de frequência
    for (int i = 0; i < n; i++) {
        int h;
        scanf("%d", &h);
        // Apenas para garantir que a altura está no intervalo esperado
        if (h >= MIN_ALTURA && h <= MAX_ALTURA) {
            frequencia[h]++;
        }
    }

    // Flag para controlar a impressão do primeiro número (que não tem espaço antes)
    int primeiro_numero = 1;

    // Itera do menor para o maior valor de altura possível
    for (int h = MIN_ALTURA; h <= MAX_ALTURA; h++) {
        for (int i = 0; i < frequencia[h]; i++) {
            if (primeiro_numero) {
                printf("%d", h);
                primeiro_numero = 0;
            } else {
                printf(" %d", h);
            }
        }
    }
    printf("\n");
}
