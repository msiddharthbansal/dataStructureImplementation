#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define N 10

int pop(int stack[],int *tos)
{
    int v;
    if((*tos)==-1)
        printf("UNDERFLOW \n");
    
    v = stack[*tos];
    (*tos)--;
    return v;
}

void push(int stack[],int *tos,int value)
{
    int i;
    if((*tos)>=N-1)
        printf("Stack overflow");
    (*tos)++;
    stack[*tos]=value;
}

int eval(int operand1,int operand2, char operator)
{
    if (operator == '+')
        return operand1+operand2;
    else if (operator == '-')
        return operand1-operand2;
    else if (operator == '/')
        return operand1/operand2;
    else if (operator == '*')
        return operand1*operand2;
}
int main()
{
    int stack[N];
    int tos = -1;
    char postfix[] = "10 15 + 20 *";
    char * delim = " ";
    int operand, operand1, operand2, answer;
    char operator;
    char * ptr = strtok(postfix,delim);
    
    for (int i = 0; i< sizeof (postfix)/sizeof (char); i++)
        printf ("%c", postfix[i]);
        
    printf ("\n");

    while(ptr!=NULL)
    {   
        if(isdigit(ptr[0]))
        {
            operand = atoi(ptr);
            push(stack,&tos,operand);
        }
        else
        {
            operator=ptr[0];
            operand2 = pop(stack,&tos);
            operand1 = pop(stack,&tos);
            answer = eval(operand1,operand2,operator);
            push(stack,&tos,answer);
        }
    
        ptr = strtok(NULL,delim);
    }
    printf("Final answer is: %d \n",answer); // Final answer is: 500
}
