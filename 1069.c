#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1001

int main() {
    int n;
    scanf("%d", &n);
    getchar(); 

    while (n--) {
        char mina[MAX_SIZE];
        if (fgets(mina, sizeof(mina), stdin) == NULL) {
            break;
        }
        mina[strcspn(mina, "\n")] = 0; 

     
        char pilha[MAX_SIZE];
        int topo = -1; 

        int diamantes = 0;
        int i;
        int tamanho = strlen(mina);

        for (i = 0; i < tamanho; i++) {
            if (mina[i] == '<') {
                topo++;
                pilha[topo] = '<';
            } else if (mina[i] == '>') {
                if (topo != -1) {
                    topo--;
                    diamantes++;
                }
            }
        }

        printf("%d\n", diamantes);
    }

    return 0;
}
