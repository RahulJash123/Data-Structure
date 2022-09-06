#include<stdio.h>
#include<stdlib.h>

typedef struct stud
{
    int info;
    struct stud *link;
} Node;

Node *start1 = NULL;
Node *start2 = NULL;
Node *start3 = NULL;
void add_end(int,int);
void display(Node *);
void concate();

int main()
{
    int value,count=0,c=1;
    char choice;
    printf("Enter the elements of 1st node: ");
    while(1)
    {
        printf("\nDo you want to insert(y/n)? ");
        scanf("%c", &choice);
        fflush(stdin);
        if(choice == 'y' || choice == 'y')
        {
            printf("Enter info: ");
            scanf("%d", &value);
            add_end(value,c);
            fflush(stdin);
        }
        else
        {
            break;
        }
}

    c=2;
    printf("\nEnter the elements of 2nd List: ");
    while(1)
    {
        printf("\nDo you want to insert(y/n)? ");
        scanf("%c", &choice);
        fflush(stdin);
        if(choice == 'y' || choice == 'y')
        {
            printf("Enter info: ");
            scanf("%d", &value);
            add_end(value,c);
            fflush(stdin);
        }
        else
        {
            break;
        }
   }
    printf("\nThe 1st linked list is : ");
    display(start1);
    printf("\nThe 2nd linked list is : ");
    display(start2);
    printf("\nAfter Concatenation : ");
    concate();
    display(start3);
    return 0;

}

void add_end(int value,int c)
{
    Node *newptr = NULL, *ptr,*tptr;
    newptr = (Node*)malloc(sizeof(Node));
    newptr->info = value;
    newptr->link = NULL;
    if(c==1)
    {
       if(start1 == NULL)
    {
        start1 = newptr;
    }
    else
    {
        ptr = start1;
        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = newptr;
    }

    }
    else if(c==2)
    {
if(start2 == NULL)
    {
        start2 = newptr;
    }
    else
    {
        ptr = start2;
        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = newptr;
    }
  }
}

void display(Node *start)
{
    Node *ptr = start;
    while(ptr)
    {
        printf("%d->", ptr->info);
        ptr = ptr->link;
    }
    printf("NULL");
}

void concate()
{
    Node *ptr=NULL;
    start3 = (Node *)malloc(sizeof(Node));
    start3=ptr=start1;
    while(ptr->link != NULL )
    {
        ptr = ptr->link;
    }
    ptr->link = start2;
}

