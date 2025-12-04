#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef struct {
    int v, w;
} Edge;

typedef struct {
    Edge *e;
    int sz, cp;
} Vec;

Vec g[2505];
int distv[2505][2505];
int heap[2000000][3];
int hsz;

void push(int d, int u, int f) {
    int i = hsz++, p;
    heap[i][0] = d;
    heap[i][1] = u;
    heap[i][2] = f;
    while (i > 0) {
        p = (i - 1) / 2;
        if (heap[p][0] <= heap[i][0]) break;
        int a = heap[p][0], b = heap[p][1], c = heap[p][2];
        heap[p][0] = heap[i][0];
        heap[p][1] = heap[i][1];
        heap[p][2] = heap[i][2];
        heap[i][0] = a;
        heap[i][1] = b;
        heap[i][2] = c;
        i = p;
    }
}

int pop(int *u, int *f) {
    if (!hsz) return -1;
    int d = heap[0][0];
    *u = heap[0][1];
    *f = heap[0][2];
    hsz--;
    heap[0][0] = heap[hsz][0];
    heap[0][1] = heap[hsz][1];
    heap[0][2] = heap[hsz][2];
    int i = 0;
    for (;;) {
        int l = i * 2 + 1, r = l + 1, s = i;
        if (l < hsz && heap[l][0] < heap[s][0]) s = l;
        if (r < hsz && heap[r][0] < heap[s][0]) s = r;
        if (s == i) break;
        int a = heap[s][0], b = heap[s][1], c = heap[s][2];
        heap[s][0] = heap[i][0];
        heap[s][1] = heap[i][1];
        heap[s][2] = heap[i][2];
        heap[i][0] = a;
        heap[i][1] = b;
        heap[i][2] = c;
        i = s;
    }
    return d;
}

int main() {
    int N, M, C, E;
    while (scanf("%d %d %d %d", &N, &M, &C, &E) == 4) {
        int i, j;

        for (i = 0; i < N; i++) {
            g[i].sz = 0;
            g[i].cp = 4;
            g[i].e = malloc(sizeof(Edge) * g[i].cp);
        }

        for (i = 0; i < M; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);

            if (g[u].sz == g[u].cp) {
                g[u].cp <<= 1;
                g[u].e = realloc(g[u].e, sizeof(Edge) * g[u].cp);
            }
            g[u].e[g[u].sz++] = (Edge){v, p};

            if (g[v].sz == g[v].cp) {
                g[v].cp <<= 1;
                g[v].e = realloc(g[v].e, sizeof(Edge) * g[v].cp);
            }
            g[v].e[g[v].sz++] = (Edge){u, p};
        }

        for (i = 0; i < N; i++)
            for (j = 0; j < C; j++)
                distv[i][j] = INF;

        hsz = 0;
        distv[E][0] = 0;
        push(0, E, 0);

        while (hsz) {
            int u, f;
            int d = pop(&u, &f);
            if (d != distv[u][f]) continue;

            for (i = 0; i < g[u].sz; i++) {
                int v = g[u].e[i].v;
                int w = g[u].e[i].w;
                int nf = f;

                if (u >= C) {
                    if (v < C) nf = v;
                } else {
                    if (v < f) continue;
                    if (v < C && v > f + 1) continue;
                    if (v == f + 1) nf = f + 1;
                }

                if (nf >= C) nf = C - 1;

                if (distv[u][f] + w < distv[v][nf]) {
                    distv[v][nf] = distv[u][f] + w;
                    push(distv[v][nf], v, nf);
                }
            }
        }

        printf("%d\n", distv[C-1][C-1]);

        for (i = 0; i < N; i++)
            free(g[i].e);
    }
    return 0;
}
