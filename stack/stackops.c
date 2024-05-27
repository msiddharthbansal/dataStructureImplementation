#include <stdio.h>
#define N 4

int read (int stack[], int tos)
{
    if (tos == -1)
    {    
        printf("No elements in stack.");
        return -1;
    }
    return stack[tos];
}

int readkth (int stack[], int tos, int k)
{
    if (k < 0 || tos < k)
    {
        printf ("No element at this position.");
        return -1;
    }
    return stack[tos-k+1];
}

void push (int stack[], int* tos, int value)
{
    if (*tos >= N-1)
    {
        printf ("Stack Overflow\n");
        return;
    }
    (*tos)++;
    stack[*tos] = value;
    return;
} 

int pop (int stack[], int* tos)
{
    int value;
    if (*tos == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    value = stack[*tos];
    (*tos)--;
    return value;
}

void display (int stack[], int tos)
{
    printf("Stack Content:\n");
    while (tos>-1)
    {
        printf ("%d ", stack[tos]);
        tos--;
    }
    printf("\n");
}

int main()
{
    int stack[N];
    int a, tos = -1;

    a = pop (stack, &tos);

    push (stack, &tos, 2);
    push (stack, &tos, 3);
    push (stack, &tos, 4);
    push (stack, &tos, 5);    
    display (stack, tos);

    push (stack, &tos, 6);
    a = pop (stack, &tos);

    printf("Popped value: %d\n", a);
    display (stack, tos);

    a = read(stack, tos);
    printf("TOS value: %d\n", a);

    a = readkth (stack, tos, 2);
    printf("2nd from TOS value: %d\n", a);

    return 0;
}
//Stack Underflow
//Stack Content:
//5 4 3 2
//Stack Overflow
//Popped value: 5
//Stack Content:
//4 3 2
//TOS value: 4
//2nd from TOS value: 3