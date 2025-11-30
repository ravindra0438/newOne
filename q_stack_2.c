#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void Enqueue(struct Stack *s1, int data)
{
    if(s1== NULL)
    {
        printf("s1 is NULL\n");
        return;
    }
    push(s1,data);
}

void Dequeue(struct Stack *s1, struct Stack *s2)
{
    if(s1 == NULL || s2==NULL)
    {
        printf("stack is NULL\n");
        return;
    } 
    if(isEmpty(s2))
    {
        while(!isEmpty(s1))
        {
            int data=pop(s1);
            push(s2,data);
        }
    }
   int data= pop(s2);
     if(data != INT_MIN)
       printf("%d is deleted \n", data);
}
int main()
{
    struct Stack *s1= createStack(10);
    struct Stack *s2= createStack(10);
    Enqueue(s1,10);
    Enqueue(s1,20);
    Dequeue(s1,s2);
    Dequeue(s1,s2);
    Dequeue(s1,s2);
    Dequeue(s1,s2);
 
}