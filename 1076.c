#include <stdio.h>
#include <string.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n;
        scanf("%d", &n);

        int v, a;
        scanf("%d %d", &v, &a);

        int grafo[50][50];
        memset(grafo, 0, sizeof(grafo));

        for (int i = 0; i < a; i++) {
            int u, w;
            scanf("%d %d", &u, &w);
            grafo[u][w] = 1;
            grafo[w][u] = 1;
        }

        int movimentos = 0;
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                if (grafo[i][j]) {
                    movimentos++;
                }
            }
        }

        printf("%d\n", movimentos);
    }

    return 0;
}
