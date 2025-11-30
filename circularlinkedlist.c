#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

struct Node *head=NULL;
struct Node *tail=NULL;

struct Node * createNode(){
    struct Node *newNode= (struct Node *)malloc(sizeof(struct Node));
   
    return newNode;
}
void insertAtBeg(int data )

{
    struct Node *newNode= createNode();
        if(newNode==NULL)
        {
            printf("memory allocation fails\n");
            return;
        }
        newNode->data=data;
    if(head == NULL)
    {
        
        head = newNode;
        newNode->next= newNode;
        tail=newNode;
       
    }
    else
    {

        newNode->next= head;
        tail->next=newNode;
        head=newNode;

    }
}

void printList()
{
    if(head== NULL)
    {
        printf("list is empty\n");
        return;
    }

    struct Node *ptr=head;
    printf("head ->");
   do{
    printf("%d ->", ptr->data);
    ptr=ptr->next;
   }while(ptr!=head);
   printf("head \n");  
}


void insertAtEnd(int data)
{
    if(head==NULL)
    {
        return insertAtBeg(data);
    }
    struct Node *newNode= createNode();
    if(newNode== NULL)
    {
        printf("memory allocation fails \n");
        return;
    }
    newNode->data=data;
    newNode->next=tail->next;
    tail->next= newNode;
    tail=newNode;
    
}
void insertAtPosition(int data, int pos)
{
    if(pos <=0)
    {
        printf("invalid position \n");
        return;
    }
    if(pos==1)
    {
        insertAtBeg(data);
   
        return ; }
   
   
    int index=1;
    struct Node *ptr=head;
    
    while(index<pos-1 && ptr->next!=head)
    {
        ptr=ptr->next;
        index++;
    }
    if(index!=pos-1)
    {
        printf("invalid position\n");
        return;
    }
    if(ptr->next==head)
    {
        insertAtEnd(data);
    
        return ;
    }
     struct Node *newNode= createNode();
      if(newNode==NULL)
    {
        printf("memory allocation fails\n");
        return;
    }
    newNode->data=data;
    newNode->next=ptr->next;
    ptr->next=newNode;
    
}
void deleteAtBeg()

{
    if(head == NULL)
    {
        printf("list is empty \n");
        return;
    }
    struct Node *ptr=head;
    if(head==tail)
    {
        tail =head=NULL;
        free(ptr);
        ptr=NULL;

        return;
    }
    head = head->next;
    tail->next=head;
    free(ptr);
    ptr=NULL;
}

void deleteAtAnyPosition(int pos)
{
    if(pos <=0)
    {
        printf("invalid list \n");
        return;
    }
    if(pos ==1)
    {
        deleteAtBeg();
        return;
    }
    struct Node *ptr=head;
    struct Node *secondLastNode=NULL;
    int index=1;
    while(index <pos-1 && ptr->next != head)
    {
        ptr= ptr->next;
        index++;
    }  
    struct Node *toDelete=ptr->next;
    if(index !=pos-1 || toDelete==head)
    {
        printf("out of %d bound access\n", index);
        return;
    }   
    ptr->next=toDelete->next;
    if(toDelete->next == head)
    {
        tail=ptr;
    }
    
    free(toDelete);
    toDelete=NULL;
}
int main()
{
    insertAtBeg(10);

    printList();
    insertAtEnd(100);
   
    printList();
    insertAtPosition(1,1);
    printList();
      insertAtPosition(50,4);
    printList();
    deleteAtBeg();
    printList();
    deleteAtAnyPosition(4);
    printList();
    

    

}