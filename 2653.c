#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOTAL_LEN 1000005
#define MAX_STRINGS 1000005

char buffer[MAX_TOTAL_LEN];
char *strings[MAX_STRINGS];

int compare(const void *a, const void *b) {
    const char *sa = *(const char **)a;
    const char *sb = *(const char **)b;
    return strcmp(sa, sb);
}

int main() {
    int n = 0;
    int pos = 0;

    while (scanf("%s", &buffer[pos]) != EOF) {
        strings[n++] = &buffer[pos];
        int len = strlen(&buffer[pos]);
        pos += len + 1;
    }

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    qsort(strings, n, sizeof(char *), compare);

    int distinct_count = 1;
    for (int i = 1; i < n; i++) {
        if (strcmp(strings[i], strings[i-1]) != 0) {
            distinct_count++;
        }
    }

    printf("%d\n", distinct_count);

    return 0;
}
