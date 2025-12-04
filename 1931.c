#include <stdio.h>
#include <stdlib.h>

#define MAX_C 10005
#define MAX_E 100005
#define INF 1000000000

typedef struct {
    int cost;
    int u;
    int parity;
} State;

int head[MAX_C];
int to[MAX_E];
int weight[MAX_E];
int next_edge[MAX_E];
int edge_count = 0;

int dist[MAX_C][2];

State heap[MAX_E * 10];
int heap_size = 0;

void add_edge(int u, int v, int w) {
    to[edge_count] = v;
    weight[edge_count] = w;
    next_edge[edge_count] = head[u];
    head[u] = edge_count++;
}

void swap(State *a, State *b) {
    State temp = *a;
    *a = *b;
    *b = temp;
}

void push(State s) {
    heap[heap_size] = s;
    int curr = heap_size++;
    while (curr > 0) {
        int parent = (curr - 1) / 2;
        if (heap[curr].cost < heap[parent].cost) {
            swap(&heap[curr], &heap[parent]);
            curr = parent;
        } else {
            break;
        }
    }
}

State pop() {
    State ret = heap[0];
    heap[0] = heap[--heap_size];
    int curr = 0;
    while (curr * 2 + 1 < heap_size) {
        int child = curr * 2 + 1;
        if (child + 1 < heap_size && heap[child + 1].cost < heap[child].cost) {
            child++;
        }
        if (heap[child].cost < heap[curr].cost) {
            swap(&heap[child], &heap[curr]);
            curr = child;
        } else {
            break;
        }
    }
    return ret;
}

int main() {
    int C, V;
    if (scanf("%d %d", &C, &V) != 2) return 0;

    for (int i = 0; i <= C; i++) head[i] = -1;
    for (int i = 0; i <= C; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    for (int i = 0; i < V; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    dist[1][0] = 0;
    State start = {0, 1, 0};
    push(start);

    while (heap_size > 0) {
        State current = pop();
        int d = current.cost;
        int u = current.u;
        int p = current.parity;

        if (d > dist[u][p]) continue;

        for (int e = head[u]; e != -1; e = next_edge[e]) {
            int v = to[e];
            int w = weight[e];
            int new_dist = d + w;
            int new_parity = 1 - p;

            if (new_dist < dist[v][new_parity]) {
                dist[v][new_parity] = new_dist;
                State next_state = {new_dist, v, new_parity};
                push(next_state);
            }
        }
    }

    if (dist[C][0] == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", dist[C][0]);
    }

    return 0;
}
