#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5
struct Pizza{
    char name[10], add[20];
    int quantity , id;
}pizza[max];
int rear =-1;
int front = -1;
int id =1;
void insert();
int isfull();
int isempty();
void del();
void peek();
void display();
int main()
{
    int n, choice;
    while(1)
    {
        printf("Enter the choice:\n1.Place an Order.\n2.Dispatch Order\n3.Display the order to be dispatched next\n4.Display entire item\n5.Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
            default:
                printf("Enter correct choice\n");
        }
    }
}
void insert()
{
    if(!isfull())
    {
        rear++;
        pizza[rear].id = id++;
        printf("\nEnter Name:\n");
        scanf("%s",&pizza[rear].name);
        printf("\nEnter address:\n");
        scanf("%s",&pizza[rear].add);
        printf("\nEnter Quantity:\n");
        scanf("%d", &pizza[rear].quantity);
    }
    if(isfull())
        printf("\nNumber of Orders overflowed\n");
    if(front == -1)
        front =0;
}
void del()
{
    if(!isempty())
    {
        printf("\nDispatched order is: %d\n", pizza[front].id);
        front++;
    }
    else
        printf("Order Underflow");
}
void peek()
{
    if(isempty())
        printf("Number overflowed.");
    else
    {
        printf("Details of Order to dispatch next:\n");
        printf("Id=%d\n", pizza[front].id);
        printf("Name of customer: %s\n", pizza[front].name);
        printf("Address ; %s\n", pizza[front].add);
        printf("quantity : %d\n",pizza[front].quantity);
    }
}
int isfull()
{
    if(rear == max-1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if(front==-1|| front == rear+1)
        return 1;
    else
        return 0;
}
void display()
{
    int i;
    if(isempty())
    {
        printf("Order list is empty.");
        return;
    }
    printf("The order list is:");
    for(i=front;i<=rear;i++) {
        printf("\nId=%d\n", pizza[i].id);
        printf("Name of customer: %s\n", pizza[i].name);
        printf("Address ; %s\n", pizza[i].add);
        printf("quantity : %d\n", pizza[i].quantity);
        printf("\n");
    }
}
