#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
struct Node *tail=NULL;
struct Node* createNode(int data)
{
    struct Node *newNode= (struct Node *)malloc(sizeof(struct Node));
    newNode->data= data;
    newNode->next= NULL;
    newNode->prev= NULL;
    return newNode;
}

void insertAtBegining(int data)
{
    struct Node *newNode= createNode(data);
     if(head ==NULL)
     {
        tail = head=newNode;
     }
     else{
        head->prev= newNode;
    newNode->next= head;
    newNode->prev= NULL;
    head=newNode;
     
     } 
    

}
void insertAtEnd(int data)
{
    struct Node *newNode= createNode(data);
    if(head== NULL)
    {
        tail=head= newNode;
        return;
    }
   
   tail->next=newNode;
   newNode->prev=tail;
   tail=newNode;

}
void insertAtAnyPosition(int data, int pos)
{
    if(pos <=0)
    {
        printf("invalid position\n");
        return;
    }
    if(head == NULL || pos ==1)
    {
        insertAtBegining(data);
        return;
    }
    int index =1;
    struct Node *ptr;
    ptr=head;
    while(index <pos-1  && ptr != NULL)
    {
        ptr= ptr->next;
        index++;
    } 
    if(ptr== NULL)
    {
        printf("given invalid position !!!\n");
        return;
    }

    if(ptr->next == NULL)
    {
        insertAtEnd(data);
        return;
    }
    struct Node *newNode= createNode(data);
    if(newNode == NULL)
    {
        printf("memory allocation fails !!!\n");
        return;
    }
    
    
    newNode->next=ptr->next;
    newNode->prev=ptr;
    newNode->next->prev= newNode;
    ptr->next=newNode;
   
}

void printList()
{
    struct Node *ptr=head;
     if(head == NULL)
    {
        printf("list is empty!!!\n");
        return;
    }
    printf("head-> ");
    while(ptr!=NULL)
    {
        printf("%d ->", ptr->data);
        ptr= ptr->next;
    }
    printf("tail\n");
}
void printListReverse()
{
    if(tail == NULL)
    {
        printf("list is empty!!!\n");
        return;
    }
    struct Node *ptr=tail;
    printf("tail-> ");
    while(ptr!=NULL)
    {
        printf("%d ->", ptr->data);
        ptr= ptr->prev;
    }
    printf("head\n");
}

void deleteFirst()
{
    struct Node *ptr= head;
    if(head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    
    if(head->next == NULL)
    {
       head=tail=NULL;
         free(ptr);
         ptr=NULL;
       return;
    }
   head= head->next;
   head->prev=NULL;
    free(ptr);
    ptr=NULL;
  
}
void deleteAtEnd()
{
    if(head== NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct Node *ptr=tail;
    if(head==tail)
    {   
        head=tail= NULL;
        free(ptr);
        ptr=NULL;
        return;

    }
    tail = tail->prev;
    tail->next= NULL;
    free(ptr);
    ptr=NULL;

}
void deleteAtAnyPosition(int pos)

{
    if(head == NULL)
    {
        printf("list is empty!!!\n");
        return ;
    }
    if(pos <=0)
    {
          printf("invalid position to delete!!!\n");
        return;
    }
    if(pos == 1)
    {
        deleteFirst();
        return;
    }
    struct Node *toDelete=head;
    struct Node *secondLastNode=NULL;
    int index=1;
    while(index<pos && toDelete!=NULL)
    {
       secondLastNode= toDelete;
       toDelete= toDelete->next;
        index++;
    }
    if(toDelete == NULL)
    {
        printf("invalid position to delete!!!\n");
        return;
    }
    if(toDelete == tail)
    {
        tail = tail->prev;
        tail->next= NULL;
        free(toDelete);
        toDelete=NULL;
        return;
    }
    secondLastNode->next= toDelete->next;
    secondLastNode->next->prev=secondLastNode;
    free(toDelete);
     toDelete=NULL;


}
void reverseList()
{
    if(head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    if(head == tail)
    {
        return;
    }
    struct Node *curr = head;
    struct Node *temp=NULL;
    struct Node *prev=NULL;
    while(curr!=NULL)
    {
        temp= curr->next;
    
        curr->next= curr->prev;
        curr->prev=temp;
        prev= curr;
        
        curr=temp;
    }   
   //temp=head;
    head=prev;
  //  tail=temp;
    //temp=NULL; 

}
int main()
{
    insertAtBegining(1);
    printList();
    insertAtBegining(10);
     printList();
      insertAtBegining(100);
     printList();
     printListReverse();
     printList();
     insertAtEnd(1000);
     printList();
     printListReverse();
     insertAtAnyPosition(0,2);
     printList();
      insertAtAnyPosition(3,3);
     printList();
     insertAtAnyPosition(6,6);
     printList();
     insertAtAnyPosition(9,9);
     printList();
     deleteFirst();
     printList();
     deleteAtEnd();
     printList();
      deleteAtEnd();
      printList();
      deleteAtAnyPosition(2);
      printList();
      deleteAtAnyPosition(5);
      printList();
      reverseList();
      printList();
      
      
    
    
    



}
