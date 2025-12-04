#include <stdio.h>
#include <string.h>

#define MAX 10005

int dist[MAX];
int queue[MAX * 2];

int reverse(int n) {
    int r = 0;
    while (n > 0) {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}

int bfs(int start, int target) {
    memset(dist, -1, sizeof(dist));
    int head = 0, tail = 0;

    queue[tail++] = start;
    dist[start] = 0;

    while (head < tail) {
        int u = queue[head++];

        if (u == target) return dist[u];

        int v1 = u + 1;
        if (v1 <= 10000 && dist[v1] == -1) {
            dist[v1] = dist[u] + 1;
            queue[tail++] = v1;
        }

        int v2 = reverse(u);
        if (v2 <= 10000 && dist[v2] == -1) {
            dist[v2] = dist[u] + 1;
            queue[tail++] = v2;
        }
    }
    return -1;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", bfs(a, b));
    }

    return 0;
}
