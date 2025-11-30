#include<stdio.h>
#include<stdlib.h>
struct Deque{
    int front;
    int rear;
    int *arr;
    int size;
};
struct Deque * createQueue(int size)
{
    struct Deque *q=(struct Deque *)malloc(sizeof (struct Deque));
    if(q== NULL)
    {
        printf("memory allocation fails\n");
        return NULL;
    }
    q->front=-1;
    q->rear=-1;
    q->size=size;
    q->arr= (int *)malloc(sizeof(int)*size);
    if(q->arr== NULL)
    {
        printf("memory allocation fails to the array\n");
    }
    return q;
}

int isEmpty(struct Deque *q)
{
    if(q== NULL)
    {
        printf ("deque is null\n");
        return -1;
    }
    return q->rear == -1 && q->front==-1 ;
}
int isFull(struct Deque *q)
{
    if(q== NULL)
    {
        printf("deque is NUll\n");
        return -1;
    }
    return (((q->rear+1)%q->size) == q->front);
}

void insertFront(struct Deque *q, int data)
{
    if(q==NULL)

    {
        printf("deque is nULL\n");
        return;
    }
    if(q->arr==NULL)
    {
        printf("array is null\n");
        return;
    }
    if(isFull(q))
    {
        printf("deque is full \n");
        return;
    }
    if(isEmpty(q))
    {
        q->front =0;
        q->rear=0;
    }
    else
    {
        q->front= ((q->size)+(q->front-1)) %q->size;
    }
    q->arr[q->front]=data;
}


void Display(struct Deque *q)
{
    if(isEmpty(q))
    {
        printf("dequeue is empty\n");
        return;
    }
      int i= q->front;
    while(1)
    {
      
        printf("%d ", q->arr[i]);
        if(q->rear == i) break;
        i= (i +1) %q->size;
    }
    printf("\n");
}

void insertRear(struct Deque *q, int data)
{
    if(q== NULL || q->arr == NULL)
    {
        printf("arr/deque is null\n");
        return;
    }
    if(isFull(q) == 1)
    {
        printf("deque is full\n");
        return;
    }
    if(isEmpty(q)==1)
    {
        q->front =0;
        q->rear=0;
    }
    else{
        q->rear= (q->rear+1)%q->size;
    }
    q->arr[q->rear]=data;
}

void deleteFront(struct Deque *q)
{
    if(q==NULL)
    {
        printf("deque is NULL\n");
        return;
    }
    if(isEmpty(q) ==1)
    {
        printf("deque is empty\n");
        return;
    }
    int data= q->arr[q->front];
    printf("%d is deleted\n", data);
    if(q->rear == q->front)
    {
        q->rear=q->front=-1;
        return;
    }
    q->front= ((q->size+q->front)+1)%q->size;
    
}
void deleteRear(struct Deque *q)
{
     if(q==NULL)
    {
        printf("deque is NULL\n");
        return;
    }
    if(isEmpty(q) ==1)
    {
        printf("deque is empty\n");
        return;
    }
     int data= q->arr[q->rear];
    printf("%d is deleted\n", data);
    if(q->rear == q->front)
    {
        q->rear=q->front=-1;
        return;
    }
    q->rear = (q->size +q->rear -1 )% (q->size);

}

int main()
{

    struct Deque *q= createQueue(4);
    insertFront(q,10);
    insertRear(q,20);
    insertRear(q,30);
    insertRear(q,40);
    deleteFront(q);
    Display(q);
    insertFront(q,50);
     Display(q);
     deleteRear(q);
        Display(q);
        deleteFront(q);
        Display(q);
        deleteRear(q);
        Display(q);
        deleteFront(q);
        Display(q);
        deleteRear(q);
        Display(q);

        



}