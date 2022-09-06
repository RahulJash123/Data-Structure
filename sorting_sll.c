#include<stdio.h>
#include<stdio.h>

typedef struct stud
{
    int info;
    struct stud *link;
}Node;
Node *start = NULL;
void add_end(int);
void display(Node*);
void sort();
int main()
{
    int value;
    char choice;
    printf("Enter elements of node: \n");
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
   display(start);
   printf("\nAfter sorting in ascending manner: ");
   sort();
   display(start);
}
void add_end(int value)
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
void sort()
{
    Node *ptr = start, *ptr1 = start;
    int temp = 0;
    while(ptr)
    {
        ptr1 = ptr->link;
        while(ptr1)
        {
            if(ptr1->info > ptr->info)
        {
          temp = ptr1->info;
          ptr1->info = ptr->info;
          ptr->info = temp;
        }
        ptr1 = ptr1->link;
    }
    ptr = ptr->link;
  }
}




