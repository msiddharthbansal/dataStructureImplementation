#include <stdio.h>

void display (int row, int col, int arr[row][col])
{
    int a, b;
    for (a = 0; a<row; a++)
    {
        for (b = 0; b< col; b++)
        {
            printf("%d ", arr[a][b]);
        }
        printf("\n");
    }
}

void getMatrix( int row, int col, int arr[row][col])
{
    int i, j;
    for (i=0; i< row; i++)
    {
        for (j=0; j<col;j++)
        {
            printf("Enter value of matrix [%d][%d]: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }
}

void addMatrices(int row, int col, int mat[row][col], int mat2[row][col], int ans[row][col]) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            ans[i][j] = mat[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int row, int col, int mat[row][col], int mat2[row][col], int ans[row][col]) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            ans[i][j] = mat[i][j] - mat2[i][j];
        }
    }
}

int dotproduct (int c1, int arr[c1], int arr2[c1])
{
    int i, ans=0;
    for (i=0; i<c1; i++)
    {
        ans += arr[i]*arr2[i];
    }
    return ans;
}

void transpose (int r1, int c1, int arr[r1][c1], int ans[c1][r1])
{
    int i, j;
    for (i=0; i<c1; i++)
    {
        for (j=0; j<r1; j++)
        {
            ans[i][j] = arr[j][i];
        }
    }
}

void productMatrix(int r1, int c1, int r2, int c2, int mat[r1][c1], int mat2[r2][c2], int ans[r1][c2])
{
    int i, j;
    int x[c2][r2];
    transpose (c2, r2, mat2, x);

    for (i=0; i< r1; i++)
    {
        for (j=0; j<c2; j++)
        {
            ans[i][j] = dotproduct (c1, mat[i], x[j]);
        }
    }
}

int main()
{
    int r1, c1, r2, c2;
    printf ("Enter row and col of mat: ");
    scanf ("%d %d", &r1, &c1); // 2 2

    printf ("Enter row and col of mat1: ");
    scanf ("%d %d", &r2, &c2); // 2 2

    int mat[r1][c1], mat2[r2][c2];

    getMatrix(r1, c1, mat); // 3 7 4 9
    getMatrix(r2, c2, mat2); // 6 2 5 8

    if (r1 == r2 && c1 == c2)
    { 
        int ans[r1][c1];
        addMatrices (r1, c1, mat, mat2, ans);
        printf ("Sum of mat & mat1: \n");
        display (r1, c1, ans); // 9 9 9 17
    }

    if (r1 == r2 && c1 == c2)
    {
        int ans[r1][c1];
        subtractMatrices (r1, c1, mat, mat2, ans);
        printf("Difference of mat & mat1: \n");
        display (r1, c1, ans); // -3 5 -1 1
    }
    if (c1 == r2)
    {
        int ans[r1][c2];
        productMatrix(r1, c1, r2, c2, mat, mat2, ans);
        printf("Product of mat & mat2: \n");
        display (r1, c2, ans); // 53 62 69 80
    }
    return 0;
}