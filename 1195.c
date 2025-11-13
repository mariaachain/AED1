#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int v) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = v;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int v) {
    if (raiz == NULL) return criarNo(v);
    if (v < raiz->valor)
        raiz->esq = inserir(raiz->esq, v);
    else if (v > raiz->valor)
        raiz->dir = inserir(raiz->dir, v);
    return raiz;
}

void preOrdem(No* raiz, int* primeiro) {
    if (raiz == NULL) return;
    if (*primeiro) {
        printf("%d", raiz->valor);
        *primeiro = 0;
    } else {
        printf(" %d", raiz->valor);
    }
    preOrdem(raiz->esq, primeiro);
    preOrdem(raiz->dir, primeiro);
}

void inOrdem(No* raiz, int* primeiro) {
    if (raiz == NULL) return;
    inOrdem(raiz->esq, primeiro);
    if (*primeiro) {
        printf("%d", raiz->valor);
        *primeiro = 0;
    } else {
        printf(" %d", raiz->valor);
    }
    inOrdem(raiz->dir, primeiro);
}

void posOrdem(No* raiz, int* primeiro) {
    if (raiz == NULL) return;
    posOrdem(raiz->esq, primeiro);
    posOrdem(raiz->dir, primeiro);
    if (*primeiro) {
        printf("%d", raiz->valor);
        *primeiro = 0;
    } else {
        printf(" %d", raiz->valor);
    }
}

void liberar(No* raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int c, n, i, v, caso = 1;
    scanf("%d", &c);
    while (c--) {
        No* raiz = NULL;
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &v);
            raiz = inserir(raiz, v);
        }

        printf("Case %d:\n", caso++);
        int primeiro = 1;
        printf("Pre.: ");
        preOrdem(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("In..: ");
        inOrdem(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("Post: ");
        posOrdem(raiz, &primeiro);
        printf("\n\n");

        liberar(raiz);
    }
    return 0;
}
