#include<stdio.h>
#define N 5

void insert(int queue[], int *f, int *r, int value)
{
    if (((*r)+1)%N == *f)
        printf("QUEUE IS FULL\n");
    
    if (*f == -1)
        *f = 0;
     
    (*r) = ((*r)+1)%N;
    queue[*r] = value;
    printf("front %d rear %d \n", *f, *r);
 
}

void delete(int queue[],int *f,int *r)
{
    int v;
    if(*f == -1)
        printf("QUEUE IS EMPTY \n");
   
    v = queue[*f];
    if (*f == *r)
        *f=*r=-1;
    
    printf("dequeued %d \n", queue[*f]);
    *f = ((*f)+1)%N;
    printf("front %d rear %d \n", *f, *r);
}
void display(int queue[], int *f, int *r)
{
    int i;
 
    if(*f == -1 && *r == -1)
        printf("Underflow");
    
    else
    {
        printf("QUEUE IS \n");
        i = *f;
        while(i != *r)
        {
            printf("%d ", queue[i]);
            i = (i+1)%N;
        }
        printf("%d ", queue[*r]);
        printf("\n");
    }
}

int main()
{
    int queue[N];
    int f = -1;
    int r = -1;
    int v;
    insert(queue, &f, &r, 1);
    insert(queue, &f, &r, 2);
    insert(queue, &f, &r, 3);
    insert(queue, &f, &r, 4);
    insert(queue, &f, &r, 5);

    printf("THE ORIGINAL QUEUE \n");
    display(queue, &f, &r);

    delete(queue, &f, &r);
    display(queue, &f, &r);

    delete(queue, &f, &r);
    display(queue, &f, &r);

    delete(queue, &f, &r);
    display(queue, &f, &r);

    delete(queue, &f, &r);
    display(queue, &f, &r);

    insert(queue, &f, &r, 10);
    display(queue, &f, &r);

    insert(queue, &f, &r, 8);
    display(queue, &f, &r);

    return 0;
}
/*
front 0 rear 0 
front 0 rear 1 
front 0 rear 2
front 0 rear 3
front 0 rear 4
THE ORIGINAL QUEUE
QUEUE IS
1 2 3 4 5
dequeued 1
front 1 rear 4
QUEUE IS
2 3 4 5
dequeued 2
front 2 rear 4
QUEUE IS 
3 4 5
dequeued 3
front 3 rear 4
QUEUE IS
4 5
dequeued 4
front 4 rear 4 
QUEUE IS 
5
front 4 rear 0
QUEUE IS
5 10
front 4 rear 1
QUEUE IS
5 10 8
*/