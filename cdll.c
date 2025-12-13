#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head=NULL;
struct Node *tail=NULL;

struct Node * createNode()
{
    
   
   struct Node *newNode= (struct Node *) malloc(sizeof(struct Node));
   if(newNode== NULL)
   {
    printf("memory allocation fails\n");
    return NULL;
   }
   newNode->next=NULL;
   newNode->prev=NULL;
   return newNode;
}

void insertAtBeg(int data)
{
    struct Node *newNode= createNode();
    if(newNode==NULL)
    {
        printf("memory allocation fails");
        return;
    }
    newNode->data=data;
    if(head == NULL)
    {
        newNode->next=newNode;
        newNode->prev=newNode;
        head=newNode;
        tail=newNode;
        return;
    }

    newNode->next=head;
    newNode->prev=tail;
    head->prev=newNode;
    tail->next=newNode;
    head=newNode;



}

void PrintList()
{
    if(head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct Node *ptr= head;
    printf("head ->");
    do{
        printf("%d <->", ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("tail\n");
}
void printReverseList()

{
    if(tail == NULL)
    {
        printf("list is empty\n");
        return ;
    }
    struct Node *ptr=tail;
    printf("tail ->");
    do
    {
        printf("%d <->", ptr->data);
        ptr=ptr->prev;
    } while (ptr!=tail);

    printf("head\n");
    
}
void insertAtEnd(int data)
{
    if(head == NULL)
    {
        insertAtBeg(data);
        return;
    }
    struct Node *newNode= createNode();
    if(newNode== NULL)
    {
        printf("memory allocation fails\n");
        return;
    }
    newNode->data=data;
    newNode->next=tail->next;
    newNode->prev=tail;
    tail->next=newNode;
    head->prev=newNode;
    tail=newNode;

}
void insertAtAnyPosition(int data, int pos)
{

    if(pos <=0)
    {
        printf("invalid position\n");
        return;
    }
    if(head == NULL ) 
    {
        if(pos ==1)
        {
            insertAtBeg(data);
            return;
        }
        else{
            printf("can't insert at %d location as you mentioned due to list is empty\n", pos);
            return;
        }
    }
    struct Node *ptr=head;
    int index=1;
    while(index<pos-1 && ptr->next!=head)
    {
        ptr=ptr->next;
        index++;
    }
    if(index!=pos-1)
    {
        printf("out of bound access\n");
        return;
    }
    if(ptr->next==head)
    {
        insertAtEnd(data);
        return;
    }
    struct Node *newNode= createNode();
    if(newNode==NULL)
    {
        printf("memory  allocation fails\n");
        return;
    }
    newNode->data=data;
    newNode->next=ptr->next;
    newNode->prev=ptr;
    ptr->next=newNode;
    newNode->next->prev=newNode;
}
void deleteAtBeg()
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct Node *ptr=head;
    if(head==tail)
    {
        head=tail=NULL;
        free(ptr);
        ptr=NULL;
        return;

    }
    head= head->next;
    head->prev=tail;
    tail->next=head;
    free(ptr);
    ptr=NULL;


}

void deleteAtEnd()
{
    if(head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct Node *ptr=tail;
    if(head==tail)
    {
        head=tail=NULL;
        free(ptr);
        ptr=NULL;
        return;
    }
    tail= tail->prev;
    tail->next=head;
    head->prev=tail;
    free(ptr);
    ptr=NULL;

}

void deleteAtAnyPosition(int pos)
{
    if(pos <=0)
    {
        printf("invalid position , position MUST be greater than 1\n");
        return;
    }
    if(head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    
    if(pos ==1)
    {
        deleteAtBeg();
        return;

    }
    struct Node *ptr=head;
    int index=1;
    while(index <pos-1 && ptr->next !=head)
    {
        ptr=ptr->next;
        index++;
    }
    if(index !=pos-1 || ptr->next == head)
    {
    printf("out of bound access \n");
    return;
    }
    struct Node *toDelete= ptr->next;
    if(toDelete->next == head)
    {
        deleteAtEnd();
        return;
    }
    ptr->next= toDelete->next;
    toDelete->next->prev=ptr;
    free(toDelete);
    toDelete=NULL;
}

int main()
{
    insertAtBeg(100);
    insertAtBeg(10);
     insertAtBeg(1);
    PrintList();
    insertAtEnd(200);
    PrintList();
    insertAtAnyPosition(0,1);
    PrintList();
    insertAtAnyPosition(4,4);
    PrintList();
    deleteAtBeg();
    PrintList();
    deleteAtEnd();
    PrintList();
   deleteAtAnyPosition(2);
    PrintList();    
    printReverseList();

}
