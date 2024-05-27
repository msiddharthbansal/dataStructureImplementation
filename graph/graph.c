#include <stdio.h>
#include <stdlib.h>
#define N 15

void populate (int **A, int n)
{
    int i, j;
    printf ("If there is an edge then 1 else 0.\n");
    for (i = 0; i< n; i++)
    {
        for (j = 0; j< n; j++)
        {
            if (i == j)
                A[i][j] = 0;
            else {
                printf ("Enter (%d to %d): ", i, j);
                scanf ("%d", &A[i][j]);
            }
        }
    }
}

void enqueue (int queue[], int *f, int *r, int value)
{
    if ((*r) == N-1) // full queue
        return;

    if (*f == -1)
        (*f)++;
    queue[++(*r)] = value; 
}

int dequeue (int queue[], int *f, int *r)
{
    if ((*f) == -1) // empty queue
        return -1;
    int val = queue[*f];
    (*f)++;

    if ((*f) == (*r)) // queue becomes empty
        (*f) = (*r) = -1;

    return val;
}

void bfs (int **A, int n, int start)
{
    int visited[N] = {0};
    int queue[N];
    int front = -1;
    int rear = -1;
    int new;

    visited[start] = 1;
    enqueue (queue, &front, &rear, start);
    while (front != -1)
    {
        new = dequeue (queue, &front, &rear);
        printf ("%d ", new);

        for (int i=0; i< n; i++)
        {
            if (A[new][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(queue, &front, &rear, i);
            }
        }
    }
}

void display (int **A, int n)
{
    int i, j;
    for (i = 0; i< n; i++)
    {
        for (j = 0; j< n; j++)
        {
            printf ("%d ", A[i][j]);
        }
        printf ("\n");
    }
}

int main()
{
    int n, i;
    int ** mat;
    printf ("Enter number of Vertices: ");
    scanf ("%d", &n);
    
    mat = (int **) malloc (sizeof (int *)*n);
    for (i = 0; i < n; i++)
    {
        mat [i] = (int *) malloc (sizeof (int)* n); 
    }
    
    populate (mat, n);
    display (mat, n);

    bfs (mat, n, 0);
    printf ("\n");

    free (mat);

    return 0;
}