#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
    int info;
    struct st *link;
}Node;
Node *start = NULL;
void display();
void add(int value)
{
    Node *newptr=NULL, *ptr;
    newptr = (Node *)malloc(sizeof(Node));
    newptr->info = value;
    newptr->link = NULL;
    if(start == NULL)
    {
        start = newptr;
    }
    else
    {
        ptr = start;
        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = newptr;
    }
}

int main()
{
    int value;
    char ch;
    printf("Enter elements of node: ");
    while(1)
    {
        printf("\nDo you want to insert(y/n): ");
        scanf("%c", &ch);
        fflush(stdin);
        if(ch == 'y')
        {
            printf("\nEnter info: ");
            scanf("%d", &value);
            add(value);
            fflush(stdin);
        }
        else
            break;
        }
        printf("\nThe linked list is: ");
        display();
        return 0;
}

void display()
{
    Node *ptr = start;
    while(ptr!= NULL)
    {
        printf("%d->", ptr->info);
        ptr = ptr->link;
    }
    printf("NULL");
}

