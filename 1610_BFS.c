#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura para Lista de Adjacência (dependências)
typedef struct Aresta {
    int destino;
    struct Aresta* proximo;
} Aresta;

// Estrutura para a Fila  da BFS
typedef struct NoFila {
    int documento;
    struct NoFila* proximo;
} NoFila;

typedef struct Fila {
    NoFila *frente;
    NoFila *fundo;
} Fila;

void inicializar_fila(Fila* fila) {
    fila->frente = fila->fundo = NULL;
}

bool fila_vazia(Fila* fila) {
    return fila->frente == NULL;
}

void enfileirar(Fila* fila, int documento) {
    NoFila* novo_no = (NoFila*)malloc(sizeof(NoFila));
    if (novo_no == NULL) exit(EXIT_FAILURE);
    
    novo_no->documento = documento;
    novo_no->proximo = NULL;

    if (fila_vazia(fila)) {
        fila->frente = fila->fundo = novo_no;
    } else {
        fila->fundo->proximo = novo_no;
        fila->fundo = novo_no;
    }
}

int desenfileirar(Fila* fila) {
    if (fila_vazia(fila)) return -1;

    NoFila* temp = fila->frente;
    int documento = temp->documento;
    fila->frente = fila->frente->proximo;

    if (fila->frente == NULL) {
        fila->fundo = NULL;
    }
    free(temp);
    return documento;
}

void adicionar_dependencia(Aresta* dependencias[], int Documento_A, int Documento_B) {
    Aresta* nova_dependencia = (Aresta*)malloc(sizeof(Aresta));
    if (nova_dependencia == NULL) exit(EXIT_FAILURE);
    
    nova_dependencia->destino = Documento_B;
    nova_dependencia->proximo = dependencias[Documento_A];
    dependencias[Documento_A] = nova_dependencia;
}

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
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return;

    // Inicialização do Grafo
    Aresta** dependencias = (Aresta**)malloc((N + 1) * sizeof(Aresta*));
    if (dependencias == NULL) exit(EXIT_FAILURE); 
    for (int i = 1; i <= N; i++) {
        dependencias[i] = NULL;
    }

    // armazenar o grau de entrada 
    int grau_entrada[N + 1];
    for (int i = 1; i <= N; i++) {
        grau_entrada[i] = 0;
    }

    // Leitura das dependências e construção do grafo
    for (int i = 0; i < M; i++) {
        int Documento_A, Documento_B;
        if (scanf("%d %d", &Documento_A, &Documento_B) != 2) continue;
        adicionar_dependencia(dependencias, Documento_A, Documento_B);
        // Ao adicionar A -> B, o grau de entrada de B aumenta
        grau_entrada[Documento_B]++; 
    }

 

    Fila fila;
    inicializar_fila(&fila);
    int documentos_processados = 0;

    // 1. Enfileirar todos os nós com grau de entrada 0
    for (int i = 1; i <= N; i++) {
        if (grau_entrada[i] == 0) {
            enfileirar(&fila, i);
        }
    }

    // 2. Processamento (BFS)
    while (!fila_vazia(&fila)) {
        int Documento_U = desenfileirar(&fila);
        documentos_processados++;

        Aresta* vizinho = dependencias[Documento_U];
        while (vizinho != NULL) {
            int Documento_V = vizinho->destino;
            
            grau_entrada[Documento_V]--;

            // Se o grau de entrada for 0, ele pode ser processado
            if (grau_entrada[Documento_V] == 0) {
                enfileirar(&fila, Documento_V);
            }
            vizinho = vizinho->proximo;
        }
    }

    // 3. Verificação do Ciclo
    if (documentos_processados < N) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }

    liberar_memoria(dependencias, N);
    free(dependencias);
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 1;

    for (int t = 0; t < T; t++) {
        resolve_caso();
    }

    return 0;
}
