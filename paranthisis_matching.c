#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stud
{
    int size;
    int top;
    char *arr;
}Node;
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
        //return ;
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
int match(char a, char b)
{
    if(a == '(' && b == ')'){
        return 1;
    }
    if(a == '{' && b == '}'){
        return 1;
    }
    if(a == '[' && b == ']'){
        return 1;
    }
    return 0;
}
int parenthesisMatch(char *exp)
{
    char popped_char;
    Node *sp;
    sp->size = 50;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size *sizeof(char));
    for(int i = 0; exp[i]!= '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(isFull(sp)){
                return 0;
            }
            popped_char = pop(sp);
            if(!match(popped_char, exp[i])){
            return 0;
           }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    char *exp, s[30];
    printf("Enter input: ");
    scanf("%s", &s);
    exp = s;
    if(parenthesisMatch(exp))
    {
        printf("The parenthesis is balanced\n");
    }
    else
        printf("The parenthesis is not balanced\n");
    return 0;
}
 