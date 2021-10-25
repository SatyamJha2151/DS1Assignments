#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20
char Stack_arr[max][max];
int top=-1;
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top==max-1)
        return 1;
    else
        return 0;
}
void push(char str[max])
{
    if(isFull())
        printf("Stack is Full");
    else
    {
        top++;
        strcpy(Stack_arr[top], str);
    }
}
char* pop()
{
    if(isEmpty())
    {
        printf("Stack is empty");
        exit(1);
    }
    else
    {
        char* str;
        str = Stack_arr[top];
        top--;
        return str;
    }
}
int operator(char n)
{
    if ( n == '+'|| n == '-'|| n == '/'|| n=='^'|| n == '('|| n==')'|| n=='*')
        return 1;
    else
        return 0;
}
void postfix_to_infix(char str[max])
{
    int i;
    char operand1[max], operand2[max], operand[2];
    for(i=0;i< strlen(str);i++) {
        if (!operator(str[i])) {
            operand[0]= str[i];
            operand[1] = '\0';
            push(operand);
        }
        else
        {
            char string[max]="\0";
            strcpy(operand2, pop());
            strcpy(operand1, pop());
            operand[0] ='(';
            operand[1] ='\0';
            strcat(string, operand);
            strcat(string, operand1);
            operand[0] = str[i];
            operand[1] = '\0';
            strcat(string, operand);
            strcat(string, operand2);
            operand[0] = ')';
            operand[1] = '\0';
            strcat(string, operand);
            push(string);
        }
    }
    printf("Infix form of the expression is %s", pop());
}
int main()
{
    char expression[max];
    printf("Enter the expression");
    scanf("%s", expression);
    postfix_to_infix(expression);
    return 0;
}