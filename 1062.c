include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break; 

        while (1) {
            int desired[1000];
            scanf("%d", &desired[0]);
            if (desired[0] == 0) {
                printf("\n");
                break; 
            }

            for (int i = 1; i < n; i++) {
                scanf("%d", &desired[i]);
            }

            int stack[1000];
            int top = -1;
            int current = 1;
            int possible = 1;

            for (int i = 0; i < n; i++) {
                int target = desired[i];

                while (current <= target) {
                    stack[++top] = current++;
                }

                if (stack[top] == target) {
                    top--; 
                } else {
                    possible = 0;
                    break;
                }
            }

            if (possible)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}
