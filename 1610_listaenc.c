#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int v;
    struct No* proximo;
} No;

#define MAX 10010

int visitado[MAX];
No* lista_vizinhos[MAX]; 
int N, M;
int temLoop;

void busca(int u) {
    visitado[u] = 1; 

    No* vizinho = lista_vizinhos[u];
    while (vizinho != NULL) {
        int v = vizinho->v;

        if (visitado[v] == 0) {
            busca(v);
        } else if (visitado[v] == 1) { 
            temLoop = 1;
            return;
        }
        
        if (temLoop) return;

        vizinho = vizinho->proximo;
    }

    visitado[u] = 2; 
}

int main() {
    int T_casos;
    scanf("%d", &T_casos);

    while (T_casos--) {
        scanf("%d %d", &N, &M);

        for (int i = 1; i <= N; i++) {
            lista_vizinhos[i] = NULL;
            visitado[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            
            No* novoNo = (No*)malloc(sizeof(No));
            novoNo->v = B;
            novoNo->proximo = lista_vizinhos[A];
            lista_vizinhos[A] = novoNo;
        }

        temLoop = 0; 

        for (int i = 1; i <= N; i++) {
            if (visitado[i] == 0) {
                busca(i);
                if (temLoop) break; 
            }
        }

        if (temLoop)
            printf("SIM\n");
        else
            printf("NAO\n");
            
        for (int i = 1; i <= N; i++) {
            No* atual = lista_vizinhos[i];
            while (atual != NULL) {
                No* temp = atual;
                atual = atual->proximo;
                free(temp);
            }
        }
    }

    return 0;
}
