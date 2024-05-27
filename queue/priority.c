#include<stdio.h>
#define N 10

void enqueue(int queue[], int x, int *front, int *rear)
{
    int pos;
    if(*rear == N-1)
        printf("Overflow\n");
    else
    {
        pos = *rear;
        (*rear)++;;
        while(pos >= 0 && queue[pos] >= x)
        {
            queue[pos+1] = queue[pos];
            pos--;
        }
        queue[pos+1] = x;
        if(*front == -1)
            (*front)++;
        
    }
 
}

void dequeue(int queue[], int *front, int *rear)
{
    if (*front == -1 && *rear == -1)
        printf("Underflow");
    else if (*front == *rear)
        *front = *rear = -1;
    else {
        printf("Dequeued %d \n", queue[*front]);
        (*front)++;
    }
}

void peek(int queue[], int *front, int *rear)
{
    if(*front == -1 && *rear == -1)
        printf("Underflow");
    else
        printf("%d ", queue[*front]);
}

void display(int queue[], int *front, int *rear){
    int i;
    if(*front == -1 && *rear == -1)
        printf("Underflow");
    else {
        printf("Priority Queue: ");
        for(i = (*front); i<= (*rear); i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    int front = -1;
    int rear = -1;
    int queue[N];
    int value;

    enqueue(queue, 9, &front, &rear);
    enqueue(queue, 2, &front, &rear);
    enqueue(queue, 8, &front, &rear);
    enqueue(queue, 4, &front, &rear);
    enqueue(queue, 1, &front, &rear);
    enqueue(queue, 6, &front, &rear);
    enqueue(queue, 7, &front, &rear);

    display(queue,&front,&rear);

    dequeue(queue,&front,&rear);
    display(queue,&front,&rear);

    dequeue(queue,&front,&rear);
    display(queue,&front,&rear);
    
    dequeue(queue,&front,&rear);
    display(queue,&front,&rear);
    
    dequeue(queue,&front,&rear);
    display(queue,&front,&rear);

    return 0;
}
/*
Priority Queue: 1 2 3 4 5 6 7 
Dequeued 1
Priority Queue: 2 3 4 5 6 7
Dequeued 2
Priority Queue: 3 4 5 6 7
Dequeued 3
Priority Queue: 4 5 6 7
Dequeued 4
Priority Queue: 5 6 7
*/
