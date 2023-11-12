#include <stdio.h>
#include <stdlib.h>

void unesiMatricu(double matrix[][10], int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

int main() {

        double matrix1[10][10];
        double matrix2[10][10];

        int n1, m1;
        int n2, m2;
        printf("Unesite dimenziju prve matrice(broj redova pa kolona):\n");
        scanf("%d%d", &n1, &m1);
        printf("Unestie dimenziju druge matrice(broj redova pa kolona):\n");
        scanf("%d%d", &n2, &m2);

        if(m1 != n2) {
            printf("Matrice se ne mogu mnoziti!");
            return 0;
        }
        printf("Unesite prvu matricu:\n");
        unesiMatricu(matrix1, n1, m1);
        printf("Unesite drugu matricu:\n");
        unesiMatricu(matrix2, n2, m2);

        double** matrixProduct = (double**)malloc(sizeof(double*)*n1);
        for(int i = 0; i < n1; i++) {
                matrixProduct[i] = (double*)malloc(sizeof(double)*m2);
        }

        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < m2; j++) {
                double sum = 0;
                for(int k = 0; k < n1; k++) {
                    sum += matrix1[i][k] * matrix2[k][j];
                }
                matrixProduct[i][j] = sum;
                printf("%lf ", matrixProduct[i][j]);
            }
            printf("\n");
        }

        for(int i = 0; i < n1; i++) {
            free(matrixProduct[i]);
        }
        free(matrixProduct);

        return 0;
}
