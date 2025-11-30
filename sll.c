#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*  next;
};
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data= data;
    newNode->next = NULL;
    return newNode;
}
void  insertNodeAtFirst(struct Node** head, int data )

{
   
    struct Node* newNode= createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertNodeAtAnyPosition(struct Node** head, int data, int pos)
{
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    int index =0;
    while( index < pos-1 && temp!= NULL)
    {
        temp = temp->next;
        index++;
    }
    if(temp == NULL)
    {
        printf("out of range!!");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertNodeAtLast(struct Node** head, int data)
{
    struct Node* newNode= createNode(data);
    struct Node* tempNode= *head;
    while(tempNode->next!= NULL)
    {
        tempNode =tempNode->next;

    }
    tempNode->next = newNode;
}
void display(struct Node* head)
{
    struct Node* temp=  head;
    
    printf("-------- printing the linked list\n");
    if(temp == NULL)
    {
         printf("there is no objects to print\n");
    }
    while(temp!= NULL)
    {
        printf(" %d ", temp->data);
        temp= temp->next;
    }
}

void deleteNodeAtFirst(struct Node** head)
{
    if (*head == NULL)
    {
        printf("there is no linked list to delete the objects\n");
        return;
    }
    struct Node* temp = *head;

    *head = (*head)->next;
    free(temp);
    temp = NULL;


}
void deleteLastNode(struct Node** head)
{
    if(*head == NULL)
    {
        printf("there is no objects to delete                11111!!!!!!!\n");
        return;
    }
    struct Node* temp = *head;
    if(temp->next == NULL)
    {
        free(temp);
        *head= NULL;
        return;

    }
    
    while((temp->next != NULL) && (temp->next->next !=NULL))
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;

}
void deleteNodeAtPosition(struct Node** head, int pos)
{
     if(*head == NULL)
    {
        printf("there is no objects to delete                11111!!!!!!!\n");
        return;
    }
    if(pos ==0)
    {
        return deleteNodeAtFirst(head);
    }
    
    struct Node* temp = *head;
   
    int index =1;
    while ((index < pos-1) && (temp->next != NULL))
    {
        temp= temp->next;
        index++;
    }
    struct Node* del = temp->next;
    temp->next= temp->next->next;
    free(del);
    del = NULL;
}
int scan()
{ 
    int n=0;
    printf("\nenter the number\n");
    scanf("%d", &n);

    return  n;
}

int pos()
{ 
    int n=0;
    printf("\nenter the position\n");
    scanf("%d", &n);

    return  n;
}


int main()
{
    struct Node* head= NULL;;
    int n=0;

    insertNodeAtFirst(&head, 100);
    display(head);
    insertNodeAtLast(&head, 200);
    display(head);
    insertNodeAtLast(&head, 300);
    display(head);
    //n = scan();
    insertNodeAtAnyPosition(&head,250, 2);
    display(head);
    deleteNodeAtFirst(&head);
    display(head);
    insertNodeAtLast(&head, 400);
    insertNodeAtLast(&head, 500);
    insertNodeAtLast(&head, 600);
    insertNodeAtLast(&head, 700);
    display(head);
    deleteLastNode(&head);
    display(head);
    deleteNodeAtPosition(&head,0);
    display(head);






    

    
}