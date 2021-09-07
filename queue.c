#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1 )
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void travQueue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Empty queue !! impossible to traverse");
    }
    else
    {
        for (int i = q->f + 1; i <= q->r; i++)
        {
            printf("%d  ", q->arr[i]);
        }
    }

    printf("\n");
}

int enQueue(struct queue *q)
{
    int val;
    if (isFull(q))
    {
        printf("Queue overflow , Enqueue not possible!! \n");
    }
    else
    {
        printf("Enter the element to enqueue : \n");
        scanf("%d", &val);
        q->r++;
        q->arr[q->r] = val;
    }
}

int deQueue(struct queue *q)
{
    int tempF;
    int tempNum;

    if (isEmpty(q))
    {
        printf("Queue empty , doesnot dequeued !! \n");
        return -1;
    }
    else
    {
        tempF = q->f;
        q->f++;
        tempNum = q->arr[q->f];

        return tempNum;
    }
}

int main()
{
    struct queue queue;
    int ele, cse, val;

    queue.size = 4;
    queue.f = -1;
    queue.r = -1;
    queue.arr = (int *)malloc((queue.size) * sizeof(int));

    while (1 == 1)
    {
        printf("\n\nOptions :\n\t 1 : traverse \n\t 2 : enqueue \n\t 3 : dequeue \n\t 4 : exit \n ");
        scanf("%d", &cse);
        switch (cse)
        {
        case 1:
            travQueue(&queue);
            break;

        case 2:
            enQueue(&queue);
            break;

        case 3:
            ele = deQueue(&queue);
            if (ele != -1)
            {
                printf("element dequeued is : %d", ele);
            }
            break;

        case 4:
            return 0;
        }
    }

    return 0;
}