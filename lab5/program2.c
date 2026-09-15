#include <stdio.h>

void multiply(int mat1[3][2], int mat2[2][3], int mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            for (int k = 0; k < 2; k++) {
                sum += mat1[i][k] * mat2[k][j];
            }
            mat[i][j] = sum;
        }
    }
}

int main() {

    int mat1[3][2];
    int mat2[2][3];
    int mat[3][3];

    printf("Enter elements of first matrix : ");
    for (int i=0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of second matrix : ");
    for (int i=0; i<2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    multiply(mat1, mat2, mat);
    printf("The multiplication of both matrices is : \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}