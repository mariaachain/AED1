#include <stdio.h>

int main() {
    int inicial_fila;
    scanf("%d", &inicial_fila);

    int fila[50000];
    for (int i = 0; i < inicial_fila; i++) {
        scanf("%d", &fila[i]);
    }

    int sairam_fila;
    scanf("%d", &sairam_fila);

    int sairam[50000];
    for (int i = 0; i < sairam_fila; i++) {
        scanf("%d", &sairam[i]);
    }

    int saiu[100001] = {0};
    for (int i = 0; i < sairam_fila; i++) {
        saiu[sairam[i]] = 1;
    }

    int primeiro = 1;
    for (int i = 0; i < inicial_fila; i++) {
        if (!saiu[fila[i]]) {
            if (!primeiro) printf(" ");
            printf("%d", fila[i]);
            primeiro = 0;
        }
    }

    printf("\n");
    return 0;
}
