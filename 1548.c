#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int teste;
    scanf("%d", &teste);

    while (teste--) {
        int alunos;
        scanf("%d", &alunos);

        int original[1000], sorted[1000];
        
        for (int i = 0; i < alunos; i++) {
            scanf("%d", &original[i]);
            sorted[i] = original[i];
        }

        qsort(sorted, alunos, sizeof(int), cmp);

        int count = 0;
        for (int i = 0; i < alunos; i++) {
            if (original[i] == sorted[i])
                count++;
        }

        printf("%d\n", count);
    }

    return 0;
}
