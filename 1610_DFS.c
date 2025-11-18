#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NAO_VISITADO 0 
#define EM_CURSO 1     
#define PROCESSADO 2   

// Estrutura para representar o grafo usando Lista de Adjacência 
typedef struct Aresta {
    int destino;
    struct Aresta* proximo;
} Aresta;

void adicionar_dependencia(Aresta* dependencias[], int Documento_A, int Documento_B) {
    Aresta* nova_dependencia = (Aresta*)malloc(sizeof(Aresta));
    nova_dependencia->destino = Documento_B; 
    nova_dependencia->proximo = dependencias[Documento_A];
    dependencias[Documento_A] = nova_dependencia;
}

bool busca_profundidade(int documento_atual, Aresta* dependencias[], int status_documento[]) {
    // 1. Marca o nó atual como EM_CURSO
    status_documento[documento_atual] = EM_CURSO;

    Aresta* vizinho = dependencias[documento_atual];
    while (vizinho != NULL) {
        int documento_dependente = vizinho->destino;

        // Se o vizinho já está EM_CURSO, achamos um ciclo (aresta de retorno)
        if (status_documento[documento_dependente] == EM_CURSO) {
            return true;
        }

        // Se o vizinho é NAO_VISITADO, chamamos recursivamente
        if (status_documento[documento_dependente] == NAO_VISITADO) {
            if (busca_profundidade(documento_dependente, dependencias, status_documento)) {
                return true; // Propaga a descoberta do ciclo
            }
        }
        vizinho = vizinho->proximo;
    }

    // 2. Terminou de visitar o nó e seus descendentes. Marca como PROCESSADO.
    status_documento[documento_atual] = PROCESSADO;
    return false;
}

// Libera a memória do grafo para evitar vazamento
void liberar_memoria(Aresta* dependencias[], int total_documentos) {
    for (int i = 1; i <= total_documentos; i++) {
        Aresta* atual = dependencias[i];
        while (atual != NULL) {
            Aresta* proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }
}

void resolve_caso() {
    int N, M; // N=Documentos, M=Dependências
    if (scanf("%d %d", &N, &M) != 2) return;

    Aresta** dependencias = (Aresta**)malloc((N + 1) * sizeof(Aresta*));
    if (dependencias == NULL) exit(EXIT_FAILURE); 
    for (int i = 1; i <= N; i++) {
        dependencias[i] = NULL;
    }

    int status_documento[N + 1];
    for (int i = 1; i <= N; i++) {
        status_documento[i] = NAO_VISITADO;
    }

    for (int i = 0; i < M; i++) {
        int Documento_A, Documento_B;
        if (scanf("%d %d", &Documento_A, &Documento_B) != 2) continue;
        adicionar_dependencia(dependencias, Documento_A, Documento_B);
    }

    bool loop_encontrado = false;

    for (int i = 1; i <= N; i++) {
        if (status_documento[i] == NAO_VISITADO) {
            if (busca_profundidade(i, dependencias, status_documento)) {
                loop_encontrado = true;
                break; // Achou o primeiro loop, já pode parar
            }
        }
    }

    if (loop_encontrado) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }

    // Limpeza
    liberar_memoria(dependencias, N);
    free(dependencias);
}

int main() {
    int T; // Casos de teste
    if (scanf("%d", &T) != 1) return 1;

    for (int t = 0; t < T; t++) {
        resolve_caso();
    }

    return 0;
}
