#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char letra;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(char l) {
    No* novo = (No*) malloc(sizeof(No));
    novo->letra = l;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir(No* raiz, char l) {
    if (raiz == NULL) {
        return criarNo(l);
    }
    if (l < raiz->letra) {
        raiz->esquerda = inserir(raiz->esquerda, l);
    } else if (l > raiz->letra) {
        raiz->direita = inserir(raiz->direita, l);
    }
    return raiz;
}

int buscar(No* raiz, char l) {
    if (raiz == NULL) return 0;
    if (raiz->letra == l) return 1;
    if (l < raiz->letra)
        return buscar(raiz->esquerda, l);
    else
        return buscar(raiz->direita, l);
}

void imprimeInfixa(No* raiz, int* primeiro) {
    if (raiz == NULL) return;
    imprimeInfixa(raiz->esquerda, primeiro);
    if (*primeiro) {
        printf("%c", raiz->letra);
        *primeiro = 0;
    } else {
        printf(" %c", raiz->letra);
    }
    imprimeInfixa(raiz->direita, primeiro);
}

void imprimePrefixa(No* raiz, int* primeiro) {
    if (raiz == NULL) return;
    if (*primeiro) {
        printf("%c", raiz->letra);
        *primeiro = 0;
    } else {
        printf(" %c", raiz->letra);
    }
    imprimePrefixa(raiz->esquerda, primeiro);
    imprimePrefixa(raiz->direita, primeiro);
}

void imprimePosfixa(No* raiz, int* primeiro) {
    if (raiz == NULL) return;
    imprimePosfixa(raiz->esquerda, primeiro);
    imprimePosfixa(raiz->direita, primeiro);
    if (*primeiro) {
        printf("%c", raiz->letra);
        *primeiro = 0;
    } else {
        printf(" %c", raiz->letra);
    }
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main() {
    No* raiz = NULL;
    char comando[20];
    char letra;
    int primeiro;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &letra);
            raiz = inserir(raiz, letra);
        } else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &letra);
            if (buscar(raiz, letra))
                printf("%c existe\n", letra);
            else
                printf("%c nao existe\n", letra);
        } else if (strcmp(comando, "INFIXA") == 0) {
            primeiro = 1;
            imprimeInfixa(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "PREFIXA") == 0) {
            primeiro = 1;
            imprimePrefixa(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "POSFIXA") == 0) {
            primeiro = 1;
            imprimePosfixa(raiz, &primeiro);
            printf("\n");
        }
    }

    liberarArvore(raiz);
    return 0;
}
