#include<stdio.h>
#include<stdio.h>

typedef struct stud
{
    struct stud *lptr;
    int info;
    struct stud *rptr;
}Node;
Node *start = NULL;
Node *last = NULL;
void add_end(int value)
{

    Node *newptr=NULL, *ptr;
    newptr = (Node *)malloc(sizeof(Node));
    newptr->info = value;
    newptr->lptr = NULL;
    newptr->rptr = NULL;
    if(start == NULL)
    {
        start = newptr;
        last = newptr;
    }
    else
    {
        ptr = start;
        while(ptr->rptr != NULL)
        {
            ptr = ptr->rptr;
        }
        ptr->rptr = newptr;
        newptr->lptr = ptr;
        last = newptr;
    }
}
void display()
{
    Node *ptr = start;
    while(ptr)
    {
        printf("%d->", ptr->info);
        ptr = ptr->rptr;
    }
    printf("NULL");
}
int main()
{
    int value;
    char choice;
    printf("Enter elements of 1st node: \n");
    while(1)
    {
    printf("Do you want to insert(y/n): ");
    scanf("%c", &choice);
    fflush(stdin);
    if(choice == 'y')
    {
        printf("Enter info: ");
        scanf("%d", &value);
        add_end(value);
        fflush(stdin);
    }
    else
    {
            break;
    }
  }
    printf("\nThe linked list is: ");
    display();
    return 0;
}
