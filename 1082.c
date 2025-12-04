#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adj[30][30];
int visited[30];
int nodes[30];
int node_count;
int V, E;

int compare(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void dfs(int u) {
    visited[u] = 1;
    nodes[node_count++] = u;
    for (int v = 0; v < V; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    for (int t = 1; t <= N; t++) {
        if (scanf("%d %d", &V, &E) != 2) break;

        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < E; i++) {
            char u, v;
            scanf(" %c %c", &u, &v);
            adj[u - 'a'][v - 'a'] = 1;
            adj[v - 'a'][u - 'a'] = 1;
        }

        printf("Case #%d:\n", t);

        int connected_components = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                connected_components++;
                node_count = 0;
                dfs(i);
                
                qsort(nodes, node_count, sizeof(int), compare);

                for (int j = 0; j < node_count; j++) {
                    printf("%c,", nodes[j] + 'a');
                }
                printf("\n");
            }
        }
        printf("%d connected components\n\n", connected_components);
    }

    return 0;
}
