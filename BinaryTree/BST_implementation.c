#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node * left;
    struct node * right;
};

void printlevel (struct node * tree, int x)
{
    if (tree == NULL)
        return;

    if (x == 0)
        printf ("%d ", tree -> info);
    
    else
        printlevel (tree -> left, x-1);
        printlevel (tree -> right, x-1);
}

int maxfn (int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int height (struct node * tree)
{
    if (tree == NULL)
        return 0;
    
    return maxfn (height (tree -> left), height (tree -> right)) + 1;
}

struct node * inorderSuccessor (struct node * tree)
{
    while (tree -> left != NULL)
    {
        tree = tree -> left;
    }
    return tree;
}

struct node * insertion (struct node * tree, int value)
{
    struct node * n = (struct node *) malloc (sizeof(struct node));
    if (n == NULL)
    {
        perror ("Allocation failed.\n");
        return n;
    }

    n -> info = value;
    n -> left = NULL; 
    n -> right = NULL;

    if (tree == NULL)
        return n;
    
    struct node * temp = tree;
    
    while (1)
    {
        if (value < temp -> info)
        {
            if (temp -> left == NULL)
            {
                temp -> left = n;
                break;
            }
            temp = temp -> left;
        }
        else 
        {
            if (temp -> right == NULL)
            {
                temp -> right = n;
                break;
            }
            temp = temp -> right;
        }
    }
    return tree;
}

struct node * insertRec (struct node * tree, int value)
{
    if (tree == NULL)
    {
        struct node * n = (struct node *) malloc (sizeof(struct node));
        if (n == NULL)
        {
            perror ("Allocation Failed.\n");
            return tree;
        }
        n -> info = value;
        n -> left = NULL;
        n -> right = NULL;
        return n;
    }
    else if (value < tree -> info)
    {
        tree -> left = insertRec (tree -> left, value);
    }
    else {
        tree -> right = insertRec (tree -> right, value);
    }
    return tree;
}

struct node * deletion (struct node * tree, int value)
{
    struct node * curr = tree;
    struct node * prev = NULL;

    while (curr != NULL && curr -> info != value)
    {
        prev = curr;
        if (value < curr -> info)
            curr = curr -> left; 
        else 
            curr = curr -> right;
    }

    if (curr == NULL)
    {
        printf("Value not found.\n");
        return tree;
    }

    if (curr -> left == NULL || curr -> right == NULL)
    {
        struct node * newCurr;
        if (curr -> left == NULL)
            newCurr = curr -> right;
        else
            newCurr = curr -> left;

        if (prev == NULL)
            return newCurr;
        
        if (curr == prev -> left)
            prev -> left = newCurr;
        else 
            prev -> right = newCurr;
        free (curr);
    }
    else {
        struct node * p = NULL;
        struct node * temp;

        temp = curr -> right;
        while (temp -> left != NULL)
        {
            p = temp;
            temp = temp -> left;
        }
        if (p != NULL)
            p -> left = temp -> right;
        else
            curr -> right = temp -> right;
        curr -> info = temp -> info;
        free (temp);
    }
    return tree;
}

struct node * deleteRec (struct node * tree, int value)
{
    struct node * temp;
    if (tree == NULL)
    {
        printf ("Empty BST.\n");
        return tree;
    }
    
    if (tree -> info > value)
        tree -> left = deleteRec (tree -> left, value);
    
    else if (tree -> info < value)
        tree -> right = deleteRec (tree -> right, value);

    else {
        if (tree -> left == NULL)
        {
            temp = tree -> right;
            free (tree);
            return temp;
        }
        else if (tree -> right == NULL)
        {
            temp = tree -> left;
            free (tree);
            return temp;
        }
        
        temp = inorderSuccessor (tree -> right);
        tree -> info = temp -> info;
        tree -> right = deleteRec (tree -> right, temp -> info);        
    }
    return tree;
}

void PreOrder ( struct node * tree)
{
    if (tree == NULL)
        return;
    
    printf ("%d ", tree -> info);
    PreOrder (tree -> left);
    PreOrder (tree -> right);
}

void InOrder (struct node * tree)
{
    if (tree == NULL)
        return;
    
    InOrder (tree -> left);
    printf ("%d ", tree -> info);
    InOrder (tree -> right);
}

void PostOrder (struct node * tree)
{
    if (tree == NULL)
        return;

    PostOrder (tree -> left);
    PostOrder (tree -> right);
    printf ("%d ", tree -> info);
}

void LevelOrder (struct node * tree)
{
    int h, i;
    if (tree == NULL)
        return;
    h = height (tree);
    //printf ("\n%d\n", h);
    
    for (i=0; i< h; i++)
    {
        printlevel (tree, i);
        printf ("\n");
    }
    
}

struct node * cloneTree (struct node * tree)
{
    if (tree == NULL)
        return tree;
    
    struct node * n = (struct node *) malloc (sizeof (struct node));
    if (n == NULL)
    {
        perror ("Allocation Failed.\n");
        return tree;
    }

    n -> info = tree -> info;
    n -> left = cloneTree (tree -> left);
    n -> right = cloneTree (tree -> right);

    return n;
}

int main()
{
    struct node * tree = NULL;
    struct node * clone;
    int val;

    tree = insertion (tree, 26);
    tree = insertion (tree, 5);
    tree = insertion (tree, 77);
    tree = insertion (tree, 1);
    tree = insertion (tree, 61);

    tree = insertRec (tree, 11);
    tree = insertRec (tree, 59);
    tree = insertRec (tree, 15);
    tree = insertRec (tree, 48);
    tree = insertRec (tree, 19);

    printf ("PreOrder: ");
    PreOrder (tree);

    printf ("\nPostOrder: ");
    PostOrder (tree);

    printf ("\nInOrder: ");
    InOrder (tree);

    printf ("\nLevelOrder: \n");
    LevelOrder (tree);

    tree = deletion (tree, 26);
    printf ("Level Order: \n");
    LevelOrder (tree);

    tree = deleteRec (tree, 11);
    printf ("Level Order: \n");
    LevelOrder (tree);

    clone = cloneTree (tree);
    printf ("Level Order: \n");
    LevelOrder (clone);

    return 0;
}

/*
PreOrder: 26 5 1 11 15 19 77 61 59 48 
PostOrder: 1 19 15 11 5 48 59 61 77 26
InOrder: 1 5 11 15 19 26 48 59 61 77
LevelOrder: 
26
5 77
1 11 61
15 59
19 48
Level Order: 
48
5 77
1 11 61
15 59
19
Level Order: 
48
5 77
1 15 61
19 59
Level Order: 
48
5 77
1 15 61
19 59
*/