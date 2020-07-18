#include<stdio.h>
#include<stdlib.h>
#define max 20
struct stack
{
    int arr[max];
    int top;
};
void init(struct stack *s)
{
    s->top=-1;
}
int isEmpty(struct stack *s)
{
    if(s->top==-1)
        return 1;
    else return 0;
}
int isFull(struct stack *s)
{
    if(s->top==max-1)
        return 1;
    else return 0;
}
void push(struct stack *s,int n)
{
    s->top++;
    s->arr[s->top]=n;
}
int pop(struct stack *s)
{
    int item;
    item=s->arr[s->top];
    s->top--;
    return item;
}
void peek(struct stack *s)
{
    printf("%d",s->top);
}
void main()
{
    struct stack s;
    init(&s);
    int i;
    char str[20];
    printf("Enter Expression:");
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='(')
            push(&s,1);
        if(str[i]==')')
            pop(&s);
    }
    peek(&s);
    if(isEmpty(&s))
    {
        printf("\nThe parenthesis are balanced.");
    }
    else
    {
        printf("\nNot Balanced");
    }
}
