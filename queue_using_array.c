#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int size;
    int f;
    int r;
    int *arr;
} Node;
int isFull(Node *q)
{
    if (q->r == q->size - 1)
    {
        printf("This queue is full");
        return 1;
    }
    else
        return 0;
}
int isEmpty(Node *q)
{
    if (q->r == q->f)
    {
        printf("This queue is empty");
        return 1;
    }
    else
        return 0;
}
void enqueue(Node *q, int val)
{
    if (isFull(q))
    {
        printf("This queue is full");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}
int dequeue(Node *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This queue is Empty");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    Node q;
    q.size = 50;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    char ch;
    int val;
    while (1)
    {
        printf("\nDo you wanrt to insert(y/n): ");
        scanf("%c", &ch);
        fflush(stdin);
        if (ch == 'y')
        {
            printf("\nEnter the value: ");
            scanf("%d", &val);
            enqueue(&q, val);
            fflush(stdin);
        }
        else
        {
            break;
        }
    }
    for (int i = q.f + 1; i <= q.r; i++)
    {
        printf("%d ", q.arr[i]);
    }
    printf("\nDequeing element is %d", dequeue(&q));
    return 0;
}