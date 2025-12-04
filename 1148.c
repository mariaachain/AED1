#include <stdio.h>
#include <string.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int inicio;
        scanf("%d", &inicio);

        int v, a;
        scanf("%d %d", &v, &a);

        int grafo[100][100];
        memset(grafo, 0, sizeof(grafo));

        int arestas_unicas = 0;

        for (int i = 0; i < a; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            
        
            if (grafo[x][y] == 0) {
                grafo[x][y] = 1;
                grafo[y][x] = 1;
                arestas_unicas++;
            }
        }
        printf("%d\n", arestas_unicas * 2);
    }

    return 0;
}
