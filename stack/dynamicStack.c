#include <stdio.h>
#include <stdlib.h>

int* push(int stack[], int*size, int*tos, int value)
{
    int* newStack;
    if (*tos >= *size -1)
    {
        *size = (*size)*2;
        newStack = (int*) malloc((*size)*sizeof(int));
        if (newStack == NULL)
            return stack;

        for (int i=0; i<=*tos; i++)
            newStack[i] = stack[i];

        (*tos)++;
        newStack[*tos] = value;
        return newStack;
    }
    (*tos)++;
    stack[*tos] = value;
    return stack;
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

int main()
{
    int* stack;
    int size = 1;
    int tos = -1;
    int value;
    int a, i;

    stack = (int*) malloc(size*sizeof(int));


    stack = push(stack, &size, &tos, 3);
    stack = push(stack, &size, &tos, 4);
    stack = push(stack, &size, &tos, 5);
    stack = push(stack, &size, &tos, 6);
    printf("Stack content.\n");
    for (i=0; i<=tos; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");

    printf ("size: %d\n", size);

    a = pop (stack,&tos);
    a = pop (stack, &tos);
    a = pop (stack, &tos);

    if (size >= 4*tos)
        size = size/2;

    printf ("size: %d\n", size);

}
//Stack content.
//3 4 5 6 
//size: 4 
//size: 2 