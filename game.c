#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int **t;
int **checked;
int count;
int queens_count = 0;
void print(int n);
int check(int row, int col, int n);
int solve(int row, int n);
int main()
{

    int n, i, j;

    printf("Number of queens ? \t");
    scanf("%d", &n);
    t = (int **)malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
    {
        t[i] = (int *)malloc(sizeof(int) * n);
    }
    checked = (int **)malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
    {
        checked[i] = (int *)malloc(sizeof(int) * n);
    }

    print(n);
    solve(0, n);
    return 0;
}
void print(int n)
{
    int i, j;
    printf("\n\nSolution %d:\n\n", ++count);

    for (i = 0; i < n; ++i)
        printf("\t%d", i);
    printf("\n\n");
    for (i = 0; i < n; ++i)
    {
        printf("%d", i);
        for (j = 0; j < n; ++j) //for nxn t
        {
            if (t[i][j] == 1)
                printf("\tQ"); //queen at i,j position
            else
                printf("\t-"); //empty slot
        }
        printf("\n\n");
    }
}
int check(int row, int col, int n)
{

    //check row , column and diagonal conflicts
    for (int i = 0; i < n; i++)
    {

        if (t[row][i])
            return 0;
        if (t[i][col])
            return 0;

        int r = row;
        int c = col;

        while (r >= 0 && c >= 0)
        {

            if (t[r][c] == 1)
                return 0;
            r--;
            c--;
        }

        r = row;
        c = col;
        while (r < n && c >= 0)
        {

            if (t[r][c] == 1)
                return 0;
            r++;
            c--;
        }
        r = row;
        c = col;

        while (r >= 0 && c < n)
        {

            if (t[r][c] == 1)
                return 0;
            r--;
            c++;
        }
        r = row;
        c = col;
        while (r < n && c < n)
        {

            if (t[r][c] == 1)
                return 0;
            r++;
            c++;
        }
    }
    return 1;
}
int solve(int row, int n)
{
    if (n == 3)
    {
        printf("no solution for n=3 \n");
        print(n);
        return 0;
    }
    int q_count = queens_count + 1;
    if (row == n)
    {

        return 0;
    }

    for (int column = 0; column < n; ++column)
    {

        if (check(row, column, n) && checked[row][column] == 0)
        {

            t[row][column] = 1;
            queens_count++;
            checked[row][column] = 1;
            print(n);
            if (queens_count == n)
            {
                return 0;
            }
            solve(row + 1, n);
            if (q_count == queens_count)
            {
                t[row][column] = 0;
                queens_count--;
                solve(row, n);
                checked[row][column] = 0;
            }
        }
    }
}