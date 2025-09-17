#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int instancia = 1;

    while (n--) {
        int sudoku[9][9];
        int i, j;

        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        int valido = 1;

        for (i = 0; i < 9 && valido; i++) {
            int visto[10] = {0};
            for (j = 0; j < 9; j++) {
                int num = sudoku[i][j];
                if (num < 1 || num > 9 || visto[num]) {
                    valido = 0;
                    break;
                }
                visto[num] = 1;
            }
        }

        for (j = 0; j < 9 && valido; j++) {
            int visto[10] = {0};
            for (i = 0; i < 9; i++) {
                int num = sudoku[i][j];
                if (num < 1 || num > 9 || visto[num]) {
                    valido = 0;
                    break;
                }
                visto[num] = 1;
            }
        }

        for (int bi = 0; bi < 9 && valido; bi += 3) {
            for (int bj = 0; bj < 9 && valido; bj += 3) {
                int visto[10] = {0};
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        int num = sudoku[bi + i][bj + j];
                        if (num < 1 || num > 9 || visto[num]) {
                            valido = 0;
                            break;
                        }
                        visto[num] = 1;
                    }
                }
            }
        }

        printf("Instancia %d\n", instancia++);
        if (valido)
            printf("SIM\n");
        else
            printf("NAO\n");

        printf("\n");
    }

    return 0;
}
