#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* link;
};

void display (struct node* Head)
{
    struct node* temp = Head;
    if (Head == NULL)
        return;
    do {
        printf("%d ", temp -> info);
        temp = temp -> link;
    }
    while (temp != Head);
    printf("\n");
    return;
}

struct node * insertFront (struct node * Head, int value)
{
    struct node* n = (struct node*) malloc (sizeof(struct node));
    if (n == NULL)
    {
        perror("allocation failed");
        return Head;
    }
    n -> info = value;
    if (Head == NULL)
    {    
        n -> link = n;
        return n;
    }
    struct node* temp = Head;
    while (temp -> link != Head)
    {
        temp = temp -> link;
    }       
    temp -> link = n;
    n -> link = Head;
    Head = n;
    return Head;
}

struct node* insertEnd (struct node* Head, int value)
{
    struct node* n = (struct node*) malloc (sizeof(struct node));
    if (n == NULL)
    {
        perror ("allocation failed");
        return Head;
    }
    n -> info = value;
    if (Head == NULL)
    {
        n -> link = n;
        return n;
    }
    struct node* temp = Head;
    while (temp -> link != Head)
    {
        temp = temp -> link;
    }
    temp -> link = n;
    n -> link = Head;
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
    
    if (Head == NULL)
    {
        n -> link = n;
        return n; 
    }
    else if (Head -> info > value)
    {
        return insertFront(Head, value);
    }
    else {
        struct node* temp = Head;
        while (temp -> link != Head && temp -> link -> info <= value)
        {
            temp = temp -> link;
        }
        n -> link = temp -> link;
        temp -> link = n;
        return Head;
    }
}

struct node* deleteFront (struct node* Head)
{
    if (Head == NULL)
    {
        printf ("Empty LinkedList\n");
        return Head;
    }
    if (Head -> link == Head)
    {
        return NULL;
    }
    else {
        struct node* temp = Head;
        while (temp -> link != Head)
        {
            temp = temp -> link;
        }
        temp -> link = Head -> link;
        Head = Head -> link;
        return Head;
    }
}

struct node* deleteEnd (struct node* Head)
{
    if (Head == NULL)
    {
        printf ("Empty LinkedList\n");
        return Head;
    }
    if (Head -> link == Head)
    {
        return NULL;
    }
    else {
        struct node* temp = Head;
        while (temp -> link -> link != Head)
        {
            temp = temp -> link;
        }
        temp -> link = Head;
        return Head;
    }
}

struct node* deleteNode (struct node* Head, int value)
{
    if (Head == NULL)
    {
        printf ("Empty LinkedList\n");
        return Head;
    }
    if (Head -> link == Head && Head -> info == value)
    {
        return NULL;
    }
    else {
        struct node* temp = Head;
        while (temp -> link -> info != value)
        {
            temp = temp -> link;
        }
        temp -> link = temp -> link -> link;
        return Head;
    }
}

struct node* mergedLists( struct node* Head, struct node* Head2)
{
    struct node* temp = Head;
    while (temp -> link != Head)
    {
        temp = temp -> link;
    }
    temp -> link = Head2;
    while (temp -> link -> link != Head2)
    {
        temp = temp -> link;    
    }
    temp -> link -> link = Head;
    return Head;
}

int main()
{
    struct node* Head = NULL;
    struct node* Head2 = NULL;
    struct node* Joined = NULL;

    Head2 = insertEnd (Head2, 1);
    Head2 = insertEnd (Head2, 2);
    Head2 = insertEnd (Head2, 3);
    Head2 = insertEnd (Head2, 4);
    Head2 = insertEnd (Head2, 5);
    

    Head = insertFront(Head, 7);
    Head = insertFront(Head, 6);
    Head = insertFront(Head, 3);
    Head = insertFront(Head, 2);

    display (Head);

    Head = insertEnd(Head, 8);
    display (Head);

    Head = insertOrder(Head, 4);
    display (Head);

    Head = deleteFront(Head);
    display (Head);

    Head = deleteEnd(Head);
    display (Head);

    Head = deleteNode (Head, 4);
    display (Head);
    display (Head2);

    Joined = mergedLists (Head, Head2);
    display (Joined);

    return 0;
}

/*
2 3 6 7 
2 3 6 7 8
2 3 4 6 7 8
3 4 6 7 8 
3 4 6 7
3 6 7
1 2 3 4 5
3 6 7 1 2 3 4 5
*/