#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next = NULL;

    node(int data)
    {
        this->data = data;
    }
};
class queue
{
public:
    node *front = NULL;
    node *rear = NULL;
};

int isEmpty(queue *q)
{
    if (q->rear == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue *q, int data)
{
    node *n = new node(data);

    if (n == NULL)
    {
        cout << "Queue is full.!!\n";
    }
    else if (q->front == NULL && q->rear ==NULL )
    {
        q->rear = n;
        q->front = n;
    }
    else
    {
        q->rear->next = n;
        q->rear=n;
    }
    cout << "Element enqued is : " << data << "\n";
}

int dequeue(queue *q)
{
    node *ptr;
    int ele = q->front->data;
    if (isEmpty(q))
    {
        cout << "empty queue\n";
        return -1;
    }
    else
    {
        ptr = q->front;
        q->front = q->front->next;
        free(ptr);
    }
    return ele;
}

void queueTraverse(queue *q)
{
    if (isEmpty(q))
    {
        cout << "Empty Queue   \n";
    }
    else
    {

        node *temp = q->front;
        cout << "printing elements : \n";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        
        cout << " \n";
    }
}

int main()
{
    int dq;
    queue q;
    enqueue(&q, 10);
    enqueue(&q, 20);
    
    //dq = dequeue(&q);
    //cout << "Element dequed is :" << dq << "\n";
    queueTraverse(&q);
    return 0;
}