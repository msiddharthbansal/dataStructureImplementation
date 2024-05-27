#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    int height;
    struct node * left;
    struct node * right;
};

struct node * minNode (struct node * Head)
{
    struct node * temp = Head;

    while (temp -> left != NULL)
        temp = temp -> left;
    
    return temp;
}

int height (struct node * Head)
{
    if (Head == NULL)
        return 0;
    return Head -> height;
}

int maxfn (int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int getBalance (struct node * Head)
{
    if (Head == NULL)
        return 0;
    return height (Head -> left) - height (Head -> right);
}

struct node * leftRotate (struct node * Head)
{
    struct node * temp = Head -> right;
    struct node * temp2 = temp -> left;

    // rotation
    temp -> left = Head;
    Head -> right = temp2;

    // Height Updation
    Head -> height = maxfn (height (Head -> left), height (Head -> right)) +1;
    temp -> height = maxfn (height (temp -> left), height (temp -> right)) +1;

    return temp;
}

struct node * rightRotate (struct node * Head)
{
    struct node * temp = Head -> left;
    struct node * temp2 = temp -> right;

    // rotation
    temp -> right = Head;
    Head -> left  = temp2;

    //Height Updation
    Head -> height = maxfn (height (Head -> left), height (Head -> right)) +1;
    temp -> height = maxfn (height (temp -> left), height (temp -> right)) +1;

    return temp;
}

struct node * insert (struct node * Head, int value)
{
    struct node * n = (struct node *) malloc (sizeof (struct node));
    n -> info = value;
    n -> height = 1;
    n -> left = NULL;
    n -> right = NULL;
    
    // for empty tree
    if (Head == NULL)
        return n;
    
    // normal BST insertion
    if (value < Head -> info)
        Head -> left = insert (Head -> left, value);
    else
        Head -> right = insert (Head -> right, value);
    
    // height updation
    Head -> height = 1 + maxfn (height (Head -> left), height (Head -> right));

    // check balance
    int balance = getBalance(Head);

    // Left Left Case
    if (balance > 1 && value < Head -> left -> info)
        return rightRotate (Head);
    
    // Right Right Case
    if (balance < -1 && value > Head -> right -> info)
        return leftRotate (Head);
    
    //Left Right Case
    if (balance > 1 && value > Head -> left -> info)
    {
        Head -> left = leftRotate (Head -> left);
        return rightRotate (Head);
    }

    // Right Left Case
    if (balance < -1 && value < Head -> right -> info)
    {
        Head -> right = rightRotate (Head -> right);
        return leftRotate (Head);
    }

    return Head;
}

struct node * delete (struct node * Head, int value)
{
    if (Head == NULL)
        return Head;
    
    // on left side
    if (value < Head -> info)
        Head -> left = delete (Head -> left, value);
    
    // on right side
    else if (value > Head -> info)
        Head -> right = delete (Head -> right, value);
    
    else {
        // if any of child is NULL
        if (Head -> left == NULL || Head -> right == NULL)
        {
            struct node * temp = Head -> left ? Head -> left : Head -> right;
            
            if (temp == NULL)
            {
                temp = Head;
                Head = NULL;
            }
            else
                *Head = *temp; // copy contents of only child
            free (temp);
        }
        else {
            struct node * temp = minNode (Head -> right); // leftmost node on right side
            Head -> info = temp -> info;
            Head -> right = delete (Head -> right, temp -> info); // delete the inorder successor
        }
    }

    if (Head == NULL)
        return Head;

    Head -> height = 1 + maxfn (height (Head -> left), height (Head -> right));

    // check balance
    int balance = getBalance (Head);

    // Left Left Case
    if (balance > 1 && getBalance (Head -> left) >= 0)
        return rightRotate (Head);
    
    // Right Right Case
    if (balance < -1 && getBalance (Head -> right) <= 0)
        return leftRotate (Head);
    
    //Left Right Case
    if (balance > 1 && getBalance (Head -> left) < 0)
    {
        Head -> left = leftRotate (Head -> left);
        return rightRotate (Head);
    }

    // Right Left Case
    if (balance < -1 && getBalance (Head -> right) > 0)
    {
        Head -> right = rightRotate (Head -> right);
        return leftRotate (Head);
    }

    return Head;
}

void preOrder(struct node * Head) 
{ 
    if(Head != NULL) 
    { 
        printf("%d ", Head -> info); 
        preOrder(Head -> left); 
        preOrder(Head -> right); 
    } 
}

int main()
{
    struct node * Head = NULL;

    Head = insert (Head, 24); 
    preOrder(Head);
    printf("\n");
    Head = insert (Head, 12); 
    preOrder(Head);
    printf("\n");
    Head = insert (Head, 5); 
    preOrder(Head);
    printf("\n");
    Head = insert (Head, 30); 
    preOrder(Head);
    printf("\n");
    Head = insert (Head, 20); 
    preOrder(Head);
    printf("\n");
    Head = insert (Head, 45);
    preOrder(Head);
    printf("\n");
    Head = insert (Head, 11);
    preOrder(Head);
    printf("\n");
    Head = insert (Head, 13);
    preOrder(Head);
    printf("\n");
    Head = insert (Head, 9);
    preOrder(Head);
    printf("\n");
    Head = insert (Head, 16);
    preOrder(Head);
    printf("\n");

    /*printf("Preorder traversal of the constructed AVL tree is \n"); 
    preOrder(Head);

    Head = delete (Head, 10);

    printf("\nPreorder traversal of the constructed AVL tree is \n"); 
    preOrder(Head);*/

    return 0;
}

/*
Preorder traversal of the constructed AVL tree is 
30 20 10 25 40 50 
Preorder traversal of the constructed AVL tree is
30 20 25 40 50
*/