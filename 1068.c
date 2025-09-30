#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    char expr[MAX];
    
    while (scanf("%s", expr) != EOF) {  // Lê até o fim da entrada
        int top = -1;
        char stack[MAX];
        int balanced = 1;

        for (int i = 0; i < strlen(expr); i++) {
            if (expr[i] == '(') {
                stack[++top] = '(';
            } else if (expr[i] == ')') {
                if (top == -1) {
                    balanced = 0;
                    break;
                }
                top--;
            }
        }

        if (balanced && top == -1)
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}
