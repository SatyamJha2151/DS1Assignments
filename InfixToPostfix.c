#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20
int top =-1;
char arr[max];
int isEmpty();
int isFull();
void push( char n);
char pop();
int operator(char n)
{
    if ( n == '+'|| n == '-'|| n == '/'|| n=='^'|| n == '('|| n==')'|| n=='*')
        return 1;
    else
        return 0;
}
int ISP(char n)
{
    if(n== '+'||n=='-')
        return 1;
    if(n =='*'||n == '/')
        return 2;
    if(n=='^')
        return 3;
    if(n == '(')
        return 0;
}
int ICP(char n)
{
    if(n== '+'||n=='-')
        return 1;
    if(n =='*'||n == '/')
        return 2;
    if(n=='^')
        return 4;
    if(n == '(')
        return 5;
}
void Infix_to_postfix(char str[])
{
    char string[max] = "0";
    int i, j=0;
    char temp;
    for(i=0 ; i< strlen(str); i++)
    {
        if(operator(str[i]))
        {
            if(str[i] == '(') {
                push(str[i]);
            }
            else if( str[i] == ')')
            {
                while(arr[top] != '(')
                {
                    temp = pop();
                    string[j++] = temp;
                }
                top--;
            }
            else if(top==-1)
            {
                push(str[i]);
            }
            else if (ICP(str[i])<= ISP(arr[top]))
            {
                while(ICP(str[i])<= ISP(arr[top]))
                {
                    temp = pop();
                    string[j++] = temp;
                }
                push(str[i]);

            }
            else if(ICP(str[i])> ISP(arr[top]))
            {
                push(str[i]);
            }
        }
        else
        {
            string[j++] =str[i];
        }
    }
    while(top!=-1)
    {
        temp = pop();
        string[j++] = temp;
    }
    printf("Postfix form of the expression.");
    printf("%s\n", string);
}
int main()
{
    int choice;
    char expression[max];
    while(1)
    {

        printf("\nEnter your choice\n1.Infix to Postfix");
        printf("\n2. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the expression\n");
                scanf("%s", expression);
                Infix_to_postfix(expression);
                break;
            case 2:
                exit(1);
        }
    }
    return 0;
}
void push(char n)
{
    int i;
    if(isFull())
    {
        printf("Stack is overflown");
        return;
    }
    top = top+1;
    arr[top]= n ;
}
char pop()
{
    if(isEmpty())
    {
        printf("Stack is underflow");
        exit(1);
    }
    char item;
    int i;
    item = arr[top];
    top = top-1;
    return item;
}

int isFull()
{
    if(top==max-1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}