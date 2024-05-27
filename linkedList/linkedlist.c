#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node* link;
};

void display (struct node *Head) {
    if (Head == NULL)
        return;
    
    struct node *temp = Head;
    while (temp != NULL)
    {
        printf ("%d ", temp -> info);
        temp = temp -> link;
    }
    printf ("\n");
    return;
}

struct node * insertFront (struct node * Head, int value)
{
    struct node* n = (struct node*) malloc (sizeof(struct node));
    if (n == NULL){
        perror("malloc");
        return Head;
    }

    n -> info = value;
    n -> link = Head;
    Head = n;

    return Head;
        
}

struct node * insertEnd (struct node * Head, int value) 
{
    struct node* n = (struct node*) malloc (sizeof(struct node));
    if (n == NULL){
        perror("malloc");
        return Head;
    }
    
    n -> info = value;
    n -> link = NULL;
    if (Head == NULL)
        return n;
    else if (Head -> link == NULL)
    {
        Head -> link = n;
        return Head;
    }
    else {
        struct node *temp = Head;
        while (temp -> link != NULL)
        {
            temp = temp -> link;
        }
        temp -> link = n;

        return Head;
    }

}

struct node * insertOrder (struct node * Head, int value)
{
    struct node* n = (struct node*) malloc (sizeof(struct node));
    if (n == NULL)
    {
        perror("malloc");
        return Head;
    }

    n -> info = value;
    n -> link = NULL;

    if (Head == NULL)
        return n;
    if (Head -> info > value)
        return insertFront(Head, value);
    else {
        struct node* temp = Head;
        while (temp -> link != NULL && temp -> link -> info < value)
        {
            temp = temp -> link;
        }
        n -> link = temp -> link;
        temp -> link = n;
        return Head;
    }
}

struct node * insertAfter(struct node * Head, int value, int after)
{
    struct node* n = (struct node*) malloc (sizeof(struct node));
    if (n == NULL)
    {   perror ("malloc");
        return Head;
    }
    n -> info = value;
    n -> link = NULL;
    if (Head == NULL)
        return n;
    struct node* temp = Head;
    while (temp != NULL && temp -> info != after)
    {
        temp = temp -> link;
    }
    n -> link = temp -> link;
    temp -> link = n;
    return Head;
}

struct node * insertBefore(struct node * Head, int value, int before)
{
    struct node* n = (struct node*) malloc (sizeof(struct node));
    if (n == NULL)
    {   perror ("malloc");
        return Head;
    }
    n -> info = value;
    n -> link = NULL;
    if (Head == NULL)
        return n;
    struct node* temp = Head;
    while (temp != NULL && temp -> link -> info != before)
    {
        temp = temp -> link;
    }
    n -> link = temp -> link;
    temp -> link = n;
    return Head;
}

struct node * deleteFront (struct node * Head)
{
    if (Head == NULL){
        printf("Empty LinkedList \n");
        return Head;
    }
    struct node* temp = Head;
    Head = temp -> link;
    return Head; 
}

struct node * deleteEnd (struct node * Head)
{
    if (Head == NULL)
        return Head;
    struct node* temp = Head;
    while (temp -> link -> link != NULL)
    {
        temp = temp -> link;
    }
    temp -> link = NULL;
    return Head;

}

struct node * deleteNode (struct node * Head, int value)
{
    if (Head == NULL)
        return Head;
    struct node* temp = Head;
    while (temp -> link != NULL && temp -> link -> info != value)
    {
        temp = temp -> link;
    }
    struct node* temp2 = temp -> link -> link;
    temp -> link = temp2;
    return Head;
}

int main()
{
    struct node* Head = NULL;

    Head = insertFront(Head, 7);
    Head = insertFront(Head, 3);

    display (Head);
    Head = insertEnd(Head, 8);
    display (Head);
    Head = insertOrder(Head, 4);
    display (Head);
    Head = insertAfter(Head, 5, 4);
    display (Head);
    Head = insertBefore(Head, 6, 7);
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
3 7         
3 7 8       
3 4 7 8     
3 4 5 7 8   
3 4 5 6 7 8 
4 5 6 7 8
4 5 6 7
4 5 7
*/