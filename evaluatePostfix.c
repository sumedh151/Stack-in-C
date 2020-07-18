#include<stdio.h>
#include<stdlib.h>
#define max 20
struct stack
{
    int data[max];
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
    s->data[s->top]=n;
}
int pop(struct stack *s)
{
    int item;
    item=s->data[s->top];
    s->top--;
    return item;
}
