//stack using structures
#include<stdio.h>
#include<stdlib.h>

struct arrayStack
{
    int top;
    int cap;
    int *arr;
};

struct arrayStack *createStack(int cap)
{
    struct arrayStack *stack;
    stack=malloc(sizeof(struct arrayStack));
    stack->top=-1;
    stack->cap=cap;
    stack->arr=malloc(sizeof(int)*cap);
    return stack;
}

int isFull(struct arrayStack*stack)
{
    if(stack->top==stack->cap-1)
        return 1;
    else return 0;
}

int isEmpty(struct arrayStack*stack)
{
    if(stack->top==-1)
        return 1;
    else return 0;
}

void push(struct arrayStack*stack,int item)
{
    if(isFull(stack))
        printf("Stack overflow.");
    else
    {
        stack->top++;
        stack->arr[stack->top]=item;
    }
}

int pop(struct arrayStack* stack)
{
    int item=0;
    if(isEmpty(stack))
    {
     /*printf("Stack underflow.");*/
     return -1;
    }
    else
    {
        item=stack->arr[stack->top];
        stack->top--;
        return item;
    }
}

void display(struct arrayStack* stack)
    {
        int i,j;
        if(isEmpty(stack))
            printf("Stack is empty.");
        else
        {
            j=stack->top;
            for(i=j;i>=0;i--)
                printf("\n%d",stack->arr[i]);
        }
    }

void main()
{
    int choice,item,cap;
    struct arrayStack *stack;
    printf("\nEnter Capacity of stack:");
    scanf("%d",&cap);
    stack=createStack(cap);

    do
    {
        printf("\n\n1.Check if Full");
        printf("\n2.Check if Empty");
        printf("\n3.Push an element");
        printf("\n4.Pop an element");
        printf("\n5.Display all elements");
        printf("\n6.Re-initialize Stack");
        printf("\n7.Exit");
        printf("\n\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            {
             if(isFull(stack))
                    printf("\nStack is full.");
             else printf("\nStack is not full.");
             break;
            }
        case 2:
            {
             if(isEmpty(stack))
                    printf("\nStack is empty.");
             else printf("\nStack is not empty.");
             break;
            }
        case 3:
            {
                printf("\nEnter element to be pushed:");
                scanf("%d",&item);
                push(stack,item);
                break;
            }
        case 4:
            {
                item=pop(stack);
                if(item==-1)
                    printf("\nStack was empty.");
                else printf("\nPopped value is %d",item);
                break;
            }
        case 5:
            {
                if(isEmpty(stack))
                    printf("Stack is empty.");
                else
                {
                 printf("\nThe stack is:");
                 display(stack);

                }
                break;
            }
        case 6:
            {
                printf("\nEnter capacity of stack:");
                scanf("%d",&cap);
                stack=createStack(cap);
                break;
            }
        case 7:
            {
                exit (0);
                break;
            }
        default:
            {
                printf("Incorrect choice.");
                break;
            }
        }
    }while(1);
}
