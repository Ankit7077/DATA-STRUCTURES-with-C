#include <stdio.h>

int main() {
    int r, c;
    printf("Enter the number of rows and columns of matrix: ");
    scanf("%d %d", &r, &c);

    int mat[50][50];
    printf("Enter the elements:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int sparArr[r * c][3];
    int num = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                sparArr[num][0] = i;
                sparArr[num][1] = j;
                sparArr[num][2] = mat[i][j];
                num++;
            }
        }
    }

    printf("Sparse matrix is:\n");
    printf("row\tcolumn\tvalue\n");
    for (int i = 0; i < num; i++) {
        printf("%d\t%d\t%d\n", sparArr[i][0], sparArr[i][1], sparArr[i][2]);
    }

    return 0;
}
