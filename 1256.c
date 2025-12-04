#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

void adicionar(Node **lista, int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->valor = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        Node *temp = *lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void liberar(Node *lista) {
    while (lista != NULL) {
        Node *temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

int main() {
    int N; // Número de casos de teste
    scanf("%d", &N);

    int primeiro = 1;

    while (N--) {
        int M, C; // M = endereços base (tamanho da tabela), C = quantidade de chaves
        scanf("%d %d", &M, &C);

        Node **tabela = (Node **)calloc(M, sizeof(Node*));

        for (int i = 0; i < C; i++) {
            int chave;
            scanf("%d", &chave);
            int indice = chave % M;
            adicionar(&tabela[indice], chave);
        }

        if (!primeiro) {
            printf("\n");
        }
        primeiro = 0;

        // Imprime a tabela
        for (int i = 0; i < M; i++) {
            printf("%d -> ", i);
            Node *atual = tabela[i];
            while (atual != NULL) {
                printf("%d -> ", atual->valor);
                atual = atual->prox;
            }
            printf("\\\n"); 
        }

        for (int i = 0; i < M; i++) {
            liberar(tabela[i]);
        }
        free(tabela);
    }

    return 0;
}
