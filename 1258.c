#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Roupa {
    char nome[100];
    char cor[20];
    char tamanho;
};

int compara(const void *a, const void *b) {
    struct Roupa *p1 = (struct Roupa *)a;
    struct Roupa *p2 = (struct Roupa *)b;

    int r = strcmp(p1->cor, p2->cor);
    
    if (r != 0) {
        return r;
    }

    if (p1->tamanho > p2->tamanho) return -1;
    if (p1->tamanho < p2->tamanho) return 1;

    return strcmp(p1->nome, p2->nome);
}

int main() {
    int n, i;
    int primeiro = 1;
    struct Roupa lista[100];
    char lixo;

    while (scanf("%d", &n) && n != 0) {
        scanf("%c", &lixo);

        if (primeiro == 0) {
            printf("\n");
        }
        primeiro = 0;

        for (i = 0; i < n; i++) {
            fgets(lista[i].nome, 100, stdin);
            
            int tam = strlen(lista[i].nome);
            if (lista[i].nome[tam - 1] == '\n') {
                lista[i].nome[tam - 1] = '\0';
            }

            scanf("%s %c", lista[i].cor, &lista[i].tamanho);
            scanf("%c", &lixo);
        }

        qsort(lista, n, sizeof(struct Roupa), compara);

        for (i = 0; i < n; i++) {
            printf("%s %c %s\n", lista[i].cor, lista[i].tamanho, lista[i].nome);
        }
    }

    return 0;
}
