#include <stdio.h>
#include <stdlib.h>

struct Term 
{
    int coef;
    int exp;
    struct Term* next;
};

struct Term* createTerm(int coef, int exp) 
{
    struct Term* n = (struct Term*)malloc(sizeof(struct Term));
    if (n == NULL) 
    {
        perror("Memory allocation failed");
        return NULL;
    }
    n->coef = coef;
    n->exp = exp;
    n->next = NULL;
    return n;
}

void insert(struct Term** poly, int coef, int exp) 
{
    struct Term* n = createTerm(coef, exp);
    if (*poly == NULL) 
    {
        *poly = n;
    } 
    else {
        struct Term* curr = *poly;
        while (curr->next != NULL) 
        {
            curr = curr->next;
        }
        curr->next = n;
    }
}

void display(struct Term* poly) 
{
    struct Term* curr = poly;
    while (curr != NULL) 
    {
        printf("%dx^%d", curr->coef, curr->exp);
        curr = curr->next;
        if (curr != NULL) 
            printf(" + ");
        
    }
    printf("\n");
}

struct Term* add(struct Term* p1, struct Term* p2) 
{
    struct Term* ans = NULL;
    while (p1 != NULL && p2 != NULL) 
    {
        if (p1->exp > p2->exp) 
        {
            insert(&ans, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp) 
        {
            insert(&ans, p2->coef, p2->exp);
            p2 = p2->next;
        }
        else {
            int sumCoeff = p1->coef + p2->coef;
            if (sumCoeff != 0)
                insert(&ans, sumCoeff, p1->exp);

            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) 
    {
        insert(&ans, p1->coef, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) 
    {
        insert(&ans, p2->coef, p2->exp);
        p2 = p2->next;
    }

    return ans;
}


struct Term* subtract(struct Term* p1, struct Term* p2) 
{
    struct Term* ans = NULL;
    while (p1 != NULL && p2 != NULL) 
    {
        if (p1->exp > p2->exp) 
        {
            insert(&ans, p1->coef, p1->exp);
            p1 = p1->next;
        } 
        else if (p1->exp < p2->exp) 
        {
            insert(&ans, -p2->coef, p2->exp);
            p2 = p2->next;
        } 
        else 
        {
            int diffCoeff = p1->coef - p2->coef;
            if (diffCoeff != 0)
                insert(&ans, diffCoeff, p1->exp);
            
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) 
    {
        insert(&ans, p1->coef, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) 
    {
        insert(&ans, -p2->coef, p2->exp);
        p2 = p2->next;
    }

    return ans;
}

struct Term* product(struct Term* p1, struct Term* p2) 
{
    struct Term* ans = NULL;
    struct Term* curr1 = p1;
    while (curr1 != NULL) 
    {
        struct Term* curr2 = p2;
        while (curr2 != NULL) 
        {
            int coeff = curr1->coef * curr2->coef;
            int exp = curr1->exp + curr2->exp;
            insert(&ans, coeff, exp);
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
    return ans;
}

int main() 
{
    struct Term* p1 = NULL;
    struct Term* p2 = NULL;

    insert(&p1, 6, 2);
    insert(&p1, 5, 1);
    insert(&p1, 4, 0);

    insert(&p2, 3, 3);
    insert(&p2, 2, 1);
    insert(&p2, 1, 0);

    printf("Poly 1: ");
    display(p1);

    printf("Poly 2: ");
    display(p2);

    struct Term* sum = add(p1, p2);
    printf("Sum: ");
    display(sum);

    struct Term* diff = subtract(p1, p2);
    printf("Difference: ");
    display(diff);

    struct Term* prod = product(p1, p2);
    printf("Product: ");
    display(prod);

    free(sum);
    free(diff);
    free(prod);

    return 0;
}
