#include <stdio.h>

int main() {
    int t, guess, count = 0;
    scanf("%d", &t);
    for (int i = 0; i < 5; i++) {
        scanf("%d", &guess);
        if (guess == t) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
