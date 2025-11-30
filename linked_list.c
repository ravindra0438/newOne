#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};



struct node *head= NULL;


struct node* createNode(int data)
{
    struct node *new_node= (struct node *)malloc(sizeof(struct node));
    new_node->data= data;
    new_node->next= NULL;
    return new_node;
}

void insert_end(int data)
{
    struct node *new_node= createNode(data);
    struct node *temp;
    temp=head;
    while(temp != NULL && temp->next != NULL)
    {
        temp= temp->next;
    }
    temp->next= new_node;

}
void recursive_traverse(struct node *ptr)
{
    if(ptr == NULL)
    {
        return;
    }
     printf("%d ", ptr->data);
    recursive_traverse(ptr->next);
   
}
void printList()
{
    if(head == NULL)
    {
        printf("list is empty!!!!!!!!\n");
        return;
    }
    struct node *ptr= head;
    printf("head->");
    while(ptr!= NULL)
    {
        printf("%d ->", ptr->data);
        ptr= ptr->next;
    }
    printf("NULL\n");
}
void free_ll()
{
    printf("\n");
    struct node *temp= head;
    while(temp != NULL)
    {
        struct node *fr= temp;
        temp= temp->next;
        free(fr);
        fr=NULL;
        
    }
    head = NULL;
}
void insert(int data)
{
    struct node *new_node= createNode(data);
    if(new_node == NULL)
    {
        printf("there is no memory to allocate \n");
        return ;
    }
    
    new_node->next= head;
    head= new_node;

}
void insert_at_given_position(int data , int pos)
{
    if(pos ==1)
    {
        insert(data);
        return;
    }
    struct node *temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp= temp->next;
    }
    struct node *new_node= createNode(data);
    new_node->next= temp->next;
    temp->next= new_node;
}
int find_pos(int data)
{
    struct node *temp=head;
    int index=1;
    if(temp == NULL)
    {
        return 0;
    }
    while(temp != NULL && temp->data < data )
    {
        temp = temp->next;
        index++;
    }
    return index;
}

void sorted_insert(int data)
{
    int pos = find_pos(data);
    if(pos ==0 || pos ==1)
    {
        insert(data);
        return;
    }
    insert_at_given_position(data, pos);
    return;
}

void delete_first_node()
{
    struct node *toDelete;
    if(head==NULL)
    {
        printf("list is empty!!!\n");
    }
    toDelete= head;
    head= toDelete->next;
    free(toDelete);
    toDelete= NULL;
}

void delete_last_node()
{
    if(head == NULL)
    {
        printf("list is empty!!!!!!!!\n");
        return;
    }
    struct node *secondLastNode, *toDelete;
    secondLastNode=head;
    toDelete= head;

    while(toDelete->next!= NULL)
    {
        secondLastNode = toDelete;
       toDelete= toDelete->next;
    }
   
    if(head== toDelete)
    {

        head= NULL;
    }
    else
    {
secondLastNode->next= NULL;
    }
    
    free(toDelete);
    toDelete=NULL;

}
int search(int data)
{
    if(head == NULL)
    {
        printf("list is empty!!!\n");
        return -1;
    }

    struct node *ptr=head;
    while(ptr!= NULL)
    {
        if(ptr->data == data)
        {
            printf("%d is available in list\n", ptr->data);
            return 1;
        }
        ptr=ptr->next;
    }
    printf("%d is not available in list\n", data);
}

void reverseList()
{
    if(head == NULL)
    {
        printf("list is empty !!!!\n");
        return;
    }
    struct node *prev= NULL, *next= NULL, *curr=head;
    while(curr!= NULL)
    {
        next= curr->next;
        curr->next=prev;
        prev= curr;
        curr= next;
    }
    head = prev;
}
void reverse_r(struct node *curr)
{
    if(curr->next == NULL)
    {
        head= curr;
        return;

    }
    reverse_r(curr->next);
    struct node *next= curr->next;
    next->next= curr;
    curr->next= NULL;

}

void deleteAtGivenPos(int pos)
{
   
    if(head == NULL)
    {
        printf("list is empty!!!\n");
        return;
    }
     struct node *toDelete= head;
    if(pos==1)
    {
        head = head->next;
        
    }
    else{
        int index=1;
        struct node *secondLastNode=NULL;
        while(index<=pos-1 && toDelete!= NULL)
        {
            secondLastNode= toDelete;
            toDelete= toDelete->next;
            index++;
        }
        secondLastNode->next= toDelete->next;
        
    }
    free(toDelete);
        toDelete= NULL;
}
int main()
{
    insert(1);
    printList();
    insert(2);
     printList();
    insert(3);
     printList();

     insert_end(10);
     printList();
     insert_end(100);
     printList();
     insert_at_given_position(4, 4);
     printList();
      insert_at_given_position(0, 1);
    printList();
     recursive_traverse(head);
     free_ll();
       printList();
       sorted_insert(10);
       printList();
       sorted_insert(1);
       printList();
       sorted_insert(2);
       printList();
        sorted_insert(100);
       printList();
        sorted_insert(101);
       printList();
       sorted_insert(51);
       printList();
       sorted_insert(1000);
       printList();
       search(1000);
       reverseList();

       printList();
       reverse_r(head);
       printf("reversing the list !!!!!!!!!\n");
       printList();
       reverse_r(head);
       printList();
       
       delete_first_node();
         printList();
          reverseList();

       printList();

       printf("deleting 2nd node\n");
       deleteAtGivenPos(2);
        printList();
         printf("deleting 4th node\n");
       deleteAtGivenPos(4);
       printList();
       printf("deleting 4th node\n");
       deleteAtGivenPos(4);
       printList();
       printf("deleting 1th node\n");
       deleteAtGivenPos(1);
       printList();
         search(1);
         delete_first_node();
         printList();
        delete_last_node();
         printList();
          delete_last_node();
         printList();
                   delete_last_node();
         printList();
   
                   delete_last_node();
                   
         printList();
         search(10);
                   delete_last_node();
                    search(10);
         printList();



}