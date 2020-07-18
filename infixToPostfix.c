#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20
struct stack
{
    char str[max];
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
void push(struct stack *s,char n)
{
    s->top++;
    s->str[s->top]=n;
}
char pop(struct stack *s)
{
    char item;
    item=s->str[s->top];
    s->top--;
    return item;
}
int isOperator(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
        return 1;
    else return 0;
}
int preceed(char x)
{
    if(x=='^')
        return 3;
    else if(x=='*'||x=='/')
        return 2;
    else if(x=='+'||x=='-')
        return 1;
}
void infixToPostfix(struct stack *s)
{
    char in[max],post[max];
    char item;
    char x;
    int i=0,j=0;
    printf("Enter Infix Expression:");
    scanf("%s",in);
    push(&s,'(');
    strcat(in,")");
    while(in[i]!='\0')
    {
        item=in[i];
        if(item=='(')
            push(&s,item);
        else if(isalnum(item))
        {
            post[j]=item;
            j++;
        }
        else if(isOperator(item))
        {
            x=pop(&s);
            while(preceed(x)>=preceed(item))
            {
                post[j]=x;
                j++;
                x=pop(&s);
            }
            push(&s,x);
            push(&s,item);
        }
        else if(in[i]==')')
        {
            x=pop(&s);
            while(x!='(')
            {
                post[j]=x;
                j++;
                x=pop(&s);
            }
        }
        else if(s->top!=-1)
        {
            x=pop(&s);
            post[j]=x;
            j++;
        }
        else
        {
            printf("Invalid expression.");
            exit(0);
        }
        i++;
    }
    if(s->top>0)
    {
        printf("Unbalanced Equation.");
        exit(0);
    }
    post[j]='\0';
    printf("Postfix Expression:");
    puts(post);
}
void main()
{
    struct stack s;
    init(&s);
    infixToPostfix(&s);
}
