#include "stack_ll.h"


void push(int data)
{
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    if(newNode== NULL)
    {
        printf("memory allocation fails\n");
        return;
    }
    newNode->next=head;
    head=newNode;
    newNode->data= data;
}

void pop ()
{
    if(head == NULL)
    {
        printf("stack is empty\n");
        return;
    }
    struct Node *ptr= head;
    printf("%d is deleted \n", ptr->data);
    head= head->next;
    free(ptr);
    ptr=NULL;
}

int peek()
{
    if(head== NULL)
    {
        printf("stack is empty\n");
        return -1;
    }
    return head->data;
}

int size()
{
    if(head == NULL)
    {
        return 0;
    }
    struct Node *ptr=head;
    int index=0;
    while(ptr !=NULL)
    {
        ptr=ptr->next;
        index++;
    }
    return index;
}

#if 0 
main()

{
    push (1);
    push(2);
    int data= peek();
    printf("top value : %d \n", data);
    pop();
    pop();
    pop();
    push(100);
      data= peek();
    printf("top value : %d \n", data);
    printf("size : %d ", size());

}
    #endif