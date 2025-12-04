#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 200005
#define MAX_VERTICES 200005

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int parent[MAX_VERTICES];

int compare(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
    }
}

int main() {
    int m, n;
    
    while (scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        int total_cost = 0;
        
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
            total_cost += edges[i].w;
        }

        qsort(edges, n, sizeof(Edge), compare);

        for (int i = 0; i < m; i++) {
            parent[i] = i;
        }

        int mst_cost = 0;
        int edges_count = 0;

        for (int i = 0; i < n; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            
            if (find(u) != find(v)) {
                unite(u, v);
                mst_cost += edges[i].w;
                edges_count++;
            }
        }

        printf("%d\n", total_cost - mst_cost);
    }

    return 0;
}
