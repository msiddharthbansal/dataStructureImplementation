#include<stdio.h>
#define N 10

void insert(int queue[], int *f, int *r, int value)
{
    if(*r >= N-1)
        printf("QUEUE IS FULL \n");
    else if(*f == -1 && *r == -1)
    {
        *f = *r =0;
        queue[*r] = value;
    }
    else
    {
        (*r)++;
        queue[*r] = value;
    }
}

int delete(int queue[], int *f, int *r){
    int v;
    if(*f == -1 && *r == -1)
    {
        printf("QUEUE IS EMPTY \n");
        return -1;
    }
    v = queue[*f];
    if(*f == *r)
        *f = *r = -1;
    else
        (*f)++;
    return v;
}

void display(int queue[], int *f, int *r)
{
    int i;
    if(*f == -1 && *r == -1)
        printf("QUEUE IS EMPTY");
    else{
        for(i = (*f); i<= (*r); i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int queue[N];
    int f = -1;
    int r = -1;
    int v;
    
    insert(queue,&f,&r,1);
    insert(queue,&f,&r,2);
    insert(queue,&f,&r,3);
    insert(queue,&f,&r,4);
    insert(queue,&f,&r,5);
    insert(queue,&f,&r,6);

    printf("THE ORIGINAL QUEUE \n");

    display(queue, &f, &r);
    
    v = delete(queue, &f, &r);
    printf("DELETED ELEMENT IS %d \n",v);
    display(queue, &f, &r);
    
    v = delete(queue, &f, &r);
    printf("DELETED ELEMENT IS %d \n",v);
    display(queue, &f, &r);
    
    v = delete(queue, &f, &r);
    printf("DELETED ELEMENT IS %d \n",v);
    display(queue, &f, &r);
    
    v = delete(queue, &f, &r);
    printf("DELETED ELEMENT IS %d \n",v);
    display(queue, &f, &r);
    
    v = delete(queue, &f, &r);
    printf("DELETED ELEMENT IS %d \n",v);
    display(queue, &f, &r);

    return 0;
}
/*THE ORIGINAL QUEUE 
1 2 3 4 5 6 
DELETED ELEMENT IS 1
2 3 4 5 6
DELETED ELEMENT IS 2
3 4 5 6
DELETED ELEMENT IS 3
4 5 6
DELETED ELEMENT IS 4
5 6
DELETED ELEMENT IS 5
6 
*/