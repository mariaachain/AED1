#include <stdio.h>
#include <stdlib.h>

// Função para calcular o Máximo Divisor Comum (MDC)
int mdc(int a, int b) {
    return (b == 0) ? a : mdc(b, a % b);
}

int main() {
    int n, n1, d1, n2, d2, num_res, den_res, div_comum;
    char op, slash;

    scanf("%d", &n);

    while (n--) {
        scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);

        if (op == '+') {
            num_res = (n1 * d2 + n2 * d1);
            den_res = (d1 * d2);
        } else if (op == '-') {
            num_res = (n1 * d2 - n2 * d1);
            den_res = (d1 * d2);
        } else if (op == '*') {
            num_res = (n1 * n2);
            den_res = (d1 * d2);
        } else if (op == '/') {
            num_res = (n1 * d2);
            den_res = (n2 * d1);
        }

        div_comum = mdc(abs(num_res), abs(den_res));

        printf("%d/%d = %d/%d\n", num_res, den_res, num_res / div_comum, den_res / div_comum);
    }

    return 0;
}
