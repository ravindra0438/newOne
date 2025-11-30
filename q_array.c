#include<stdio.h>
#include<math.h>
#include<conio.h>



struct Queue{
    int size;
    int start;
    int end;
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
    q->start=-1;
    q->end=-1;
    q->arr= (int *) malloc(sizeof(int)*size);
    return q;
}
int isFull(struct Queue *q)
{
    if(q== NULL)
    {
        printf("queue is full\n");
        return 0;
    }
    if(q->start == 0 && q->end == q->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
   
}
int isEmpty(struct Queue *q)
{
    if(q== NULL)
    {
        printf("queue is empty\n");
        return 0;
    }
    return q->start == -1;
}
void enqueue(struct Queue *q,int data)
{
    if(q== NULL)
    {
        printf("queue is NULL\n");
        return ;
    }
    if(isFull(q)) 
    {
        printf("queue is full\n");
        return;
    }
    if(isEmpty(q))
    {
        q->start++;
    }
         q->end++;
        q->arr[q->end]= data;
}
void dequeue(struct Queue *q)
{
    if(q==NULL)
    {
        printf("queue is null\n");
        return;
    }
    if(isEmpty(q))
    {
        printf("queue is empty\n");
        return;
    }
    printf("%d is deleted \n", q->arr[q->start]);
    q->arr[q->start]= -1;
    q->start++;
    if(q->start > q->end)
    {
        q->start=-1;
        q->end=-1;
    }


}

int getFront(struct Queue *q)
{
    if(q== NULL)
    {
        printf("Queue is NULL\n");
        return;
    }
    return q->arr[q->start];
}
int getRear(struct Queue *q)
{

     if(q== NULL)
    {
        printf("Queue is NULL\n");
        return 0;
    }
    return q->arr[q->end];
}

int main()
{
    printf("enter the queue size\n");
    int d ; scanf("%d", &d);
    struct Queue *q= createQueue(d);
    enqueue(q, 10);
    enqueue(q,20);
    dequeue(q);
    dequeue(q);
    dequeue(q);

}