#include <stdio.h>

void add(int mat1[2][2], int mat2[2][2], int mat[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

int main() {
    int mat1[2][2];
    int mat2[2][2];

    int mat[2][2];

    printf("Enter elements of first matrix : ");
    for (int i=0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of second matrix : ");
    for (int i=0; i<2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    add(mat1, mat2, mat);
    printf("The addition of both matrices is : \n");
    for (int i=0; i<2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}