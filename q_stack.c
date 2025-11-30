#include<stdio.h>
#include<stdlib.h>
#include"stack.h"




void Enqueue(struct Stack *s1, struct Stack *s2, int data)
{
    while(!isEmpty(s1))
    {
        if(s2== NULL)
        {
            return;
        }
        int temp= pop(s1);
        push(s2, temp);
    }
    push(s1,data);
    while(!isEmpty(s2))
    {
        int temp = pop(s2);
        push(s1,temp);
    }
}
void Dequeue(struct Stack *s1)
{
    if(s1== NULL)
    {
        return ;
    }
    int data =pop(s1);
    if(data != INT_MIN)
        printf("%d is deleted\n", data);
}

int main()
{
    struct Stack *s1= createStack(10);
    struct Stack *s2= createStack(10);
    Enqueue(s1,s2,10);
    Enqueue(s1,s2,20);
    Dequeue(s1);
    Dequeue(s1);
    Dequeue(s1);
    Dequeue(s1);
    destroyStack(&s1);
    destroyStack(&s2);
    destroyStack(&s2);
}