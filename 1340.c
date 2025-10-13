#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 1001


int pq_pop(int arr[], int* size) {
    if (*size == 0) {
        return -1; // Indica que a estrutura está vazia
    }

    int max_val = -1;
    int max_idx = -1;

    // Encontra o maior elemento e seu índice
    for (int i = 0; i < *size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
            max_idx = i;
        }
    }

    // "Remove" o elemento deslocando os elementos subsequentes para a esquerda
    for (int i = max_idx; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--; // Decrementa o tamanho

    return max_val;
}

int main() {
    int n;

    // O loop continua enquanto scanf conseguir ler um inteiro
    while (scanf("%d", &n) != EOF) {
   
        int stack_arr[MAX_SIZE];
        int stack_top = -1; // Índice do topo da pilha

        int queue_arr[MAX_SIZE];
        int queue_front = 0;   // Índice do início da fila
        int queue_rear = -1;   // Índice do fim da fila

        int pq_arr[MAX_SIZE];
        int pq_size = 0;      // Tamanho da fila de prioridade

        bool is_stack = true;
        bool is_queue = true;
        bool is_priority_queue = true;

        // Processa todas as n operações do caso de teste
        for (int i = 0; i < n; i++) {
            int command, value;
            scanf("%d %d", &command, &value);

            if (command == 1) {
                // Adiciona o elemento em todas as estruturas
                if (is_stack) {
                    stack_arr[++stack_top] = value;
                }
                if (is_queue) {
                    queue_arr[++queue_rear] = value;
                }
                if (is_priority_queue) {
                    pq_arr[pq_size++] = value;
                }
            } else { // command == 2

                // Verifica a pilha
                if (is_stack) {
                    // Se a pilha está vazia ou o elemento do topo não corresponde, é impossível ser uma pilha
                    if (stack_top < 0 || stack_arr[stack_top--] != value) {
                        is_stack = false;
                    }
                }

                // Verifica a fila
                if (is_queue) {
                    // Se a fila está vazia ou o elemento da frente não corresponde, é impossível ser uma fila
                    if (queue_front > queue_rear || queue_arr[queue_front++] != value) {
                        is_queue = false;
                    }
                }

                // Verifica a fila de prioridade
                if (is_priority_queue) {
                    // Se a fila de prioridade está vazia ou o maior elemento não corresponde, é impossível
                    if (pq_size == 0 || pq_pop(pq_arr, &pq_size) != value) {
                        is_priority_queue = false;
                    }
                }
            }
        }

        int possible_count = 0;
        if (is_stack) possible_count++;
        if (is_queue) possible_count++;
        if (is_priority_queue) possible_count++;

        if (possible_count == 0) {
            printf("impossible\n");
        } else if (possible_count > 1) {
            printf("not sure\n");
        } else {
            if (is_stack) {
                printf("stack\n");
            } else if (is_queue) {
                printf("queue\n");
            } else {
                printf("priority queue\n");
            }
        }
    }

    return 0;
}
