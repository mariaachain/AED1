#include <stdio.h>

#define MAX 1050

char grid[MAX][MAX];
int N, M;

typedef struct {
    int x, y;
} Point;

Point queue[MAX * MAX];
int head, tail;

void bfs(int r, int c) {
    head = 0;
    tail = 0;
    
    queue[tail].x = r;
    queue[tail].y = c;
    tail++;
    grid[r][c] = 'o'; 

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while(head < tail) {
        Point p = queue[head];
        head++;

        for(int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == '.') {
                grid[nx][ny] = 'o';
                queue[tail].x = nx;
                queue[tail].y = ny;
                tail++;
            }
        }
    }
}

int main() {
    if (scanf("%d %d", &N, &M) != 2) return 0;

    for(int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    int cliques = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(grid[i][j] == '.') {
                cliques++;
                bfs(i, j);
            }
        }
    }

    printf("%d\n", cliques);

    return 0;
}
