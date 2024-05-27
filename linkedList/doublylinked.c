#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* lptr;
    struct node* rptr;
};

struct node* insertFront (struct node* Head, int value)
{
    struct node* n = (struct node*) malloc (sizeof(struct node));
    if (n == NULL)
    {
        perror("Allocation Failed\n");
        return Head;
    }

    n -> lptr = NULL;
    n -> rptr = NULL;
    n -> info = value;

    if (Head == NULL)
        return n;

    n -> rptr = Head;
    Head -> lptr = n;
    return n;
}

struct node* insertEnd (struct node* Head, int value)
{
    struct node* n = (struct node*) malloc (sizeof(struct node));
    if (n == NULL)
    {
        perror("Allocation Failed\n");
        return Head;
    }

    n -> info = value;
    n -> lptr = NULL;
    n -> rptr = NULL;
    
    if (Head == NULL)
        return n;

    if (Head -> rptr == NULL)
    {
        Head -> rptr = n;
        n -> lptr = Head;
        return Head;
    }
    struct node* temp = Head;
    while (temp -> rptr != NULL)
    {
        temp = temp -> rptr;
    }
    temp -> rptr = n;
    n -> lptr = temp;
    return Head;
}

struct node* insertOrder (struct node* Head, int value)
{
    struct node* n = (struct node*) malloc (sizeof(struct node));
    if (n == NULL)
    {
        perror("allocation failed");
        return Head;
    }
    n -> info = value;
    n -> lptr = NULL;
    n -> rptr = NULL;
    
    if (Head == NULL)
        return n; 
    else if (Head -> info > value)
    {
        return insertFront(Head, value);
    }
    else {
        struct node* temp = Head;
        while (temp -> rptr != Head && temp -> rptr -> info <= value)
        {
            temp = temp -> rptr;
        }
        n -> rptr = temp -> rptr;
        temp -> rptr -> lptr = n;
        temp -> rptr = n;
        n -> lptr = temp;
        return Head;
    }
}

struct node * deleteFront (struct node * Head)
{
    if (Head == NULL){
        printf("Empty LinkedList \n");
        return Head;
    }
    struct node* temp = Head;
    Head = temp -> rptr;
    temp -> rptr -> lptr = NULL;
    return Head; 
}

struct node * deleteEnd (struct node * Head)
{
    if (Head == NULL)
        return Head;
    struct node* temp = Head;
    while (temp -> rptr -> rptr != NULL)
    {
        temp = temp -> rptr;
    }
    temp -> rptr = NULL;
    return Head;

}

struct node* deleteNode (struct node * Head, int value)
{
    if (Head == NULL)
        return Head;
    struct node* temp = Head;
    while (temp -> rptr != NULL && temp -> rptr -> info != value)
    {
        temp = temp -> rptr;
    }
    struct node* temp2 = temp -> rptr -> rptr;
    temp -> rptr = temp2;
    temp2 -> lptr = temp;
    return Head;
}

void display (struct node* Head)
{
    struct node* temp = Head;
    if (Head == NULL)
        return;
    
    while (temp != NULL)
    {
        printf ("%d ", temp -> info);
        temp = temp -> rptr;
    }
    
    printf("\n");
}

int main()
{
    struct node* Head = NULL;

    Head = insertFront(Head, 7);
    Head = insertFront(Head, 3);
    Head = insertFront(Head, 1);

    display (Head);
    Head = insertEnd(Head, 8);
    display (Head);
    Head = insertOrder(Head, 4);
    display (Head);
    Head = deleteFront (Head);
    display (Head);
    Head = deleteEnd (Head);
    display (Head);
    Head = deleteNode (Head, 6);
    display (Head);

    return 0;
}
/*
1 3 7 
1 3 7 8
1 3 4 7 8
3 4 7 8
3 4 7
*/