#include<stdio.h>
#include<stdlib.h>



struct Queue{

    int front, rear,size;
    int *arr;
};
struct Queue * createQueue(int size)
{
    struct Queue *q= (struct Queue *)malloc(sizeof(struct Queue));
    if(q== NULL)
    {
        return NULL;
    }
    q->size=size;
    q->front=-1;
    q->rear=-1;
    q->arr= (int *)malloc(sizeof(int)*size);
    return q;
}
int isfull(struct Queue *q)
{
    if((q->front ==0 && q->rear == q->size-1) || (q->rear+1%(q->size) == (q->front)))
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct Queue *q)
{
    if(q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    return 0;
}
void Enqueue(struct Queue *q, int data)
{
    if(q == NULL)
    {
        printf("Queue is NULL\n");
        return;
    }
    if(q->arr== NULL)
    {
        printf("array is null\n");
        return;
    }

    if(isfull(q))
    {
        printf("queue is full\n");
        return;
    }
    if(isEmpty(q))
    {
        q->front=0;
        q->rear = 0;
        q->arr[q->rear]= data;
    }
    else if(q->rear == q->size-1 && !isfull(q))
    {
        q->rear = 0;
        q->arr[q->rear]=data;
    }
    else{
        q->rear = (q->rear+1) % (q->size);
        q->arr[q->rear]=data;
    }
}

void Dequeue(struct Queue *q)
{
    if(q == NULL)
    {
        printf("Queue is NULL\n");
        return;
    }
    if(q->arr== NULL)
    {
        printf("array is null\n");
        return;
    }
    if(isEmpty(q))
    {
        printf("queue is empty\n");
        return;
    }
    int data = q->arr[q->front];
    if(q->front == q->rear)
    {
        q->front=q->rear=-1;
        printf("%d is deleted\n", data);
        return;
    }
    
    q->front = (q->front+1) % q->size;
    printf("%d is deleted\n", data);

}

int main()
{
    struct Queue *q= createQueue(4);
    Enqueue(q,10);
    Enqueue(q,20);
    Enqueue(q,30);
    Enqueue(q,40);
    Dequeue(q);
    Dequeue(q);
    Enqueue(q,50);
    Enqueue(q,60);
    Enqueue(q,70);
}

