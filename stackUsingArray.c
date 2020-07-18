//Program to perform different stack operation
#include<stdio.h>
#define max 10
int arr[max],top;
void Init_stack()
{
    top=-1;
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top==max)
        return 1;
    else
        return 0;
}
void push(int val)
{
    if(isFull())
        printf("The Stack is Full");
    else
    {
        arr[++top]=val;
    }

}
int pop()
{
    int item=0;
    if(isEmpty())
        printf("The stack is empty.");
    else
    {
        item=arr[top];
        top-=1;
    }
    return item;
}
void display()
{
    int i,j;
    if(isEmpty())
        printf("The stack is empty.");
    else
    {
        j=top;
        for(i=j; i>=0; i--)
        {
            printf("%d ",arr[i]);
        }
    }
}
void peek()
{
    if(isEmpty())
        printf("The stack is empty.");
    else
        printf("The Top Element is %d.",arr[top]);
}
void main()
{
    int choice;
    Init_stack();
    int ele;
    do
    {
        printf("\n\nEnter the operation to be performed\n1:Check if empty\n2.Check if Full\n3. Push a element\n4. Pop A element\n5.Display All elements\n6.Display top element.\n7. Initialize Stack\n8.Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            if(isEmpty())
            {
                printf("The stack is Empty");
            }
            else
                printf("The stack is not empty.");
            break;
        case 2:
            if(isFull())
            {
                printf("\nThe stack is Full");
            }
            else
                printf("\nThe stack is not Full.");
            break;
        case 3:
            if(isFull())
            {
                printf("\nThe stack is Full");
            }
            else
            {
                printf("\nEnter the element to be Pushed : ");
                scanf(" %d",&ele);
                push(ele);
            }
            break;
        case 4:
            if(isEmpty())
            {
                printf("The stack is Empty");
            }
            else
            {
                printf("Popped element is : %d ",pop());
            }
            break;
        case 5:
            if(isEmpty())
            {
                printf("The stack is Empty");
            }
            else
            {
                printf("\nThe Stack is : ");
                display();
            }
            break;
        case 6:
            if(isEmpty())
            {
                printf("The stack is Empty");
            }
            else
            {
                peek();
            }
            break;
        case 7:
            Init_stack();
            break;
        case 8:
            exit(0);
            break;

        default:
            printf("\nThe choice is wrong enter again.");

        }
    }
    while(1);
}
