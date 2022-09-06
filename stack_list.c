#include<stdio.h>
#include<stdlib.h>
typedef struct stud
{
    int data;
    struct stud *link;
}Node;
Node *top = NULL;
void display(Node *ptr)
{
    while(ptr != NULL)
    {
        printf("\nElement is %d", ptr->data);
        ptr = ptr->link;
    }
}
Node *isEmpty(Node *top)
{
    if(top == NULL)
    {
        return 1;
    }
    else
        return 0;
}
Node *isfull(Node *top)
{
    Node *n = (Node *)malloc(sizeof (Node));
    if(n == NULL)
    {
        return 1;
    }
    else
        return 0;
}
Node *push(Node *top, int x)
{

    if(isfull(top))
    {
      printf("Stack Overflow");
    }
    else
    {
        Node *n = (Node *)malloc(sizeof (Node));
        n->data = x;
        n->link = top;
        top = n;
        return top;
    }
}
int pop(Node *tp)
{

    if(isEmpty(tp))
    {
      printf("Stack underflow");
    }
    else
    {
        Node *n = tp;
        top = tp->link;
        int x = n->data;
        free(n);
        return x;
    }
}
int peek(int pos)
{
    Node *ptr = top;
    for(int i=0;(i<pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->link;
    }
    if(ptr!=NULL)
    {
        printf("\nThe element in %d position is %d", pos, ptr->data);
    }
    else
        return -1;
}
int main()
{
    int x;
    top = push(top, 23);
    top = push(top, 56);
    top = push(top, 76);

    printf("\nThe stack is : ");
    printf("\n%d", top);
    display(top);
    int pos;
    printf("\nEnter the position you want to peek: ");
    scanf("%d", &pos);
    peek(pos);
    int element = pop(top);
    printf("\nPopped out element is %d", element);
    display(top);
    return 0;
}
