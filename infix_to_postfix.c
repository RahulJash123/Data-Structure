#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stud
{
    int size;
    int top;
    char *arr;
}Node;

int stackTop(Node *sp)
{
    return sp->arr[sp->top];
}

int isEmpty(Node *ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isFull(Node *ptr)
{
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
        return 0;
}

void push(Node *ptr, char val)
{
    if(isFull(ptr))
    {
        printf("Stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(Node *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch){
        if(ch == '*' || ch == '/'){
            return 3;
        }
        else if(ch == '+' || ch == '-'){
            return 2;
        }
        else
        return 0;
}

int isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        return 1;
    }
    else
    return 0;
}

char *infixtoPostfix(char *infix)
{
   Node *sp = (Node *)malloc(sizeof(Node));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc(strlen((infix)+1) * sizeof(char));
    int i=0, j=0;
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if(precedence(infix[i]) > precedence(stackTop(sp)))
            {
                    push(sp, infix[i]);
                    i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix, s[50];
    printf("Enter input: ");
    scanf("%s", &s);
    infix = s;
    printf("Postfix is %s", infixtoPostfix(infix));
    return 0;
} 

