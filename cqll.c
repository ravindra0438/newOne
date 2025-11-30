#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node*next;
};
struct Queue
{
    struct Node *front, *rear;
};

struct Queue* createQueue()
{
    struct Queue *q= (struct Queue *)malloc(sizeof(struct Queue));
    if(q== NULL)
    {
        printf("memory allocation fails\n");
        return;
    }
    q->front=NULL;
    q->rear=NULL;
    return q;
}
struct Node* createNode()
{
    struct Node *newNode= (struct Node *)malloc(sizeof(struct Node));
    newNode->next=NULL;
    return newNode;
}

int isEmpty(struct Queue *q)
{
    return q->rear == NULL && q->front == NULL;
}
void Enqueue(struct Queue *q, int data)
{
    if(q==NULL)
    {
        printf("queue is nUll\n");
        return;
    }
    struct Node *newNode= createNode();
    newNode->data=data;
    if(isEmpty(q))
    {
        newNode->next=newNode;
        q->rear=q->front=newNode;

        return;
    }
    newNode->next=q->rear->next;
    q->rear->next=newNode;
    q->rear=newNode;
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
        printf("queue is NULL\n");
        return;
    }
    struct Node *toDelete= q->front;
    if(toDelete == q->rear)
    {
        q->rear=q->front =NULL;
    }
    else
    {
         q->front= q->front->next;
    q->rear->next=q->front;
    }
   
    printf("%d is delated\n", toDelete->data);
    free(toDelete);
    toDelete=NULL;  
}
struct Queue * reverseQueue(struct Queue *q)
{
    if(q== NULL || q->front == NULL || (q->front == q->rear))
    {
        return q;
    }
  

 struct Node *curr=q->front, *prev=q->rear, *next=NULL;

 do {
    next= curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
 }while(curr !=q->front);

 struct Node *temp=q->front;
 q->front=q->rear;
 q->rear=temp;
 q->rear->next=q->front;
 return q;
}
void printList(struct Queue *q )
{
    if(q== NULL || q->front ==NULL)
    {
        printf("queue is NULL\n");
        return;
    }
    struct Node *n=q->front;
    printf("front -> ");
    do
    {
    printf("%d ",n->data); /* code */
    n= n->next;
    } while (n!=q->front);
    printf("<- rear\n");
    
}

int main()
{
    struct Queue *q= createQueue();
    Enqueue(q,10);
    Enqueue(q,20);
    Enqueue(q,30);
    printList(q);
    struct Queue *r =reverseQueue(q);
    printList(q);
    reverseQueue(q);
     printList(q);
     Dequeue(q);
     Dequeue(q);
     Dequeue(q);
     printList(q);
     printList(r);
     reverseQueue(q);


}
