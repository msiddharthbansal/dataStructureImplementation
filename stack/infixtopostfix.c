#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h> 
#define N 30

int rightprecedence (char ch)
{
    if (ch == '^')
        return 1;
    return 0;
}

int getprecedence (char ch)
{
    switch (ch)
    {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
    }
}

char pop(char stack[], int *tos) { 
    char value;
    if (*tos < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    value = stack[(*tos)--]; 
    return value;
}

void push(char stack[], int *tos, char value) { 
    if (*tos >= N - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++(*tos)] = value; 
}

char readTop(char stack[], int tos) { 
    if (tos < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    char temp = stack[tos]; 
    return temp;
}

int main()
{
    char stack[N];
    int tos = -1;
    char infix[] = "10^20^30";

    int length = strlen(infix);
    char* postfix = (char*) malloc((length + 1) * sizeof(char));
    int x, i, j = 0;
    char input, tosSymbol;
    printf("infix expression: %s \n", infix);

    for (i = 0; i < length; i++) {
        input = infix[i];
        if (isalnum(input)) 
            postfix[j++] = input;
        else if (input == '(')
            push(stack, &tos, input);
        else if (input == ')') {
            while ((tosSymbol = pop(stack, &tos)) != '(')
                postfix[j++] = tosSymbol;
        } 
        else {
            tosSymbol = readTop(stack, tos);
            x = rightprecedence(tosSymbol);
            if (tosSymbol == -1 || tosSymbol == '(')
                push(stack, &tos, input);
            else {
                if (getprecedence(input) > getprecedence(tosSymbol))
                    push(stack, &tos, input);
                else if(x == 0){
                    while (tos >= 0 && getprecedence(input) <= getprecedence(readTop(stack, tos)))
                        postfix[j++] = pop(stack, &tos);
                    push(stack, &tos, input);
                }
                else{
                    if(tos>=0 && x == 1 && getprecedence(input) == getprecedence(readTop(stack, tos)))
                    
                        push(stack, &tos, input);
                    
                    else if(getprecedence(input) < getprecedence(readTop(stack, tos)))
                    {
                        if(tos==0){
                            postfix[j++]=pop(stack, &tos);
                            push(stack, &tos, input);
                            
                        }
                        else{
                            while (getprecedence(input) <= getprecedence(readTop(stack, tos)))
                            {
                                postfix[j++]=pop(stack, &tos);
                                push(stack, &tos, input);
                            }
                        }
                    
                    }
                }
            }
        }
    }
    
    while ((tosSymbol = pop(stack, &tos)) != -1)
        postfix[j++] = tosSymbol;
    
    postfix[j] = '\0';
    printf("postfix expression is: %s \n", postfix);
    free (postfix);
    return 0;
}