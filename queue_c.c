#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int front;
    int rear;
    int capacity;
    int size;
    int *arr;
};

struct Queue * createQueue(int capacity)
{
    struct Queue *q= (struct Queue *) malloc(sizeof(struct Queue));
    if(q== NULL)
    {
        printf("memory allocation fails\n");
        return NULL;
    }
    q->capacity= capacity;
    q->front=0;
    q->rear = q->capacity-1;
    q->arr= (int *)malloc(sizeof(int)* q->capacity);
    q->size=0;
    return q;
} 
int isFull(struct Queue *q)
{
    if(q== NULL)
    {
        return 0;
    }
    return q->size== q->capacity;
}
int isEmpty(struct Queue *q)
{
    if(q==NULL)
    {
        return 1;

    }
    return q->size==0;
}


void Enqueue(struct Queue *q, int data)
{
    if(q==NULL)
    {
        printf("queue is NULL\n");
        return;
    }
    if(isFull(q))
    {
        printf("queue is full\n");
        return;
    }
    q->rear= (q->rear+1)%q->capacity;
    q->arr[q->rear]=data;
     q->size= q->size+1;
}
void Dequeue(struct Queue *q)
{
    if(q== NULL)
    {
        printf("queue is NULL\n");
        return;
    }
    if(isEmpty(q))
    {
        printf("queue is empty\n");
        return;
    }
    int data= q->arr[q->front];
    q->front= (q->front+1)%(q->capacity);
    q->size= q->size-1;
    printf("%d is deleted\n", data);
}

int front(struct Queue *q)
{
    if(q== NULL)
    {
        printf("queue is NULL\n");
        return -1;
    }
    if(isEmpty(q))
    {
        printf("queue is empty\n");
        return -1;
    }

    return q->arr[q->front];
}
int rear(struct Queue *q)
{

    if(q== NULL)
    {
        printf("queue is NULL\n");
        return -1;
    }
    if(isEmpty(q))
    {
        printf("queue is empty\n");
        return -1;
    }

    return q->arr[q->rear];
}

int main()
{
    printf("enter the size of queue\n");
    int d;
    scanf("%d", &d);
    struct Queue *q= createQueue(d);
    Enqueue(q,10);
    Enqueue(q,20);
    Enqueue(q,30);
    Enqueue(q,40);
    Dequeue(q);
    Dequeue(q);
    Enqueue(q,50);
    printf("rear data %d\n ", q->arr[q->rear]);
    Dequeue(q);
    Enqueue(q,60);
    printf("rear data %d\n ", q->arr[q->rear]);
    printf("rear %d , front :%d \n", q->rear, q->front);
   
    
}
