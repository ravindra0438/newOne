#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct QNode{
    int data;
    struct QNode * next;
};
struct Queue{
    struct QNode *front, *rear;
};


struct QNode * createNode(int data)
{
    struct QNode *n= (struct QNode *) malloc(sizeof(struct QNode));
    if(n== NULL)
    {
        printf("memory allocation fails\n");
        return NULL;
    }
    n->next= NULL;
    n->data= data;
    return n;
}
struct Queue * createQueue()
{
    struct Queue *q= (struct Queue *) malloc(sizeof(struct Queue));
     if(q== NULL)
    {
        printf("memory allocation fails\n");
        return NULL;
    }

    q->rear=q->front= NULL;
    return q;

}

void Enqueue(struct Queue *q, int data)
{
    if(q== NULL)
    {
        printf("queue is NULL\n");
        return;
    }
    struct QNode *newNode = createNode(data);
    if(newNode== NULL)
    {
        return;
    }
    if(q->rear== NULL)
    {
        q->rear=q->front= newNode;
        return;
       
    }
    q->rear->next= newNode;
    q->rear= newNode;
}
void Dequeue(struct Queue *q)
{
    if(q==NULL)
    {
        printf("Queue is NUll\n");
        return;
    }
    if(q->front == NULL)
    {
        printf("queue is empty\n");
        return;
    }
    struct QNode *toDelete=q->front;
    q->front=q->front->next;
    if(q->front == NULL)
    {
        q->rear= NULL;
    }
    printf("%d is deleted\n", toDelete->data);
    free(toDelete);
    toDelete=NULL;
}

int front(struct Queue *q)
{
   if(q==NULL)
   {
       printf("queue is null\n");
    return q->front->data;
}

struct Queue * reverseQueue(struct Queue *q)
{
    if(q== NULL || q->front == NULL)
    {
        return;
    }
    int data= front(q);
    Dequeue(q);
    reverseQueue(q);
    Enqueue(q,data);
    return q;
}
int main()
{
    struct Queue *q= createQueue();
    Enqueue(q,10);
    Enqueue(q,20);
    Enqueue(q,30);
    struct Queue *qu=reverseQueue(q);
    printf("front %d ,  rear %d", q->front->data, q->rear->data);
    Dequeue(q);

}
