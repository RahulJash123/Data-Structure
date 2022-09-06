#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
    int info;
    struct st *link;
}Node;
Node *start = NULL;
void add_anypos(int value, int pos)
{

    int step = 0;
    Node *newptr = NULL, *ptr;
    newptr = (Node *)malloc(sizeof(Node));
    newptr->info = value;
    newptr->link = NULL;
    ptr = start;
    while(step<pos-1)
    {
        ptr = ptr->link;
        step++;
    }
    newptr->link = ptr->link;
    ptr->link = newptr;

}
void add_end(int value)
{
    Node *newptr = NULL, *ptr;
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
void display();

int main()
{
    int value, pos;
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
            add_end(value);
            fflush(stdin);
        }
        else
            break;
        }
        printf("\nThe linked list is: ");
        display();
        while(1)
        {
        printf("\nDo you want to insert a node in between(y/n): ");
        scanf("%c", &ch);
        fflush(stdin);
        if(ch == 'y')
        {
            printf("\nEnter the position: ");
            scanf("%d", &pos);
            printf("\nEnter info: ");
            scanf("%d", &value);
            add_anypos(value, pos);
            fflush(stdin);
        }
        else
            break;
        }

        printf("\nThe ultimate linked list is: ");
        display();
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
