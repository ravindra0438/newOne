#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "stack.h"



void destroyStack(struct Stack **stack)
{
    if(*stack != NULL)
    {
    free((*stack)->arr);
    free(*stack);
    *stack=NULL;
    }
}
struct Stack * createStack(int capacity)
{
    struct Stack *stack= (struct Stack *) malloc(sizeof(struct Stack));
    if(stack == NULL)
    {
        printf("memory allocation fails\n");
        return NULL;
    }
    stack->top=-1;
    stack->capacity=capacity;
    stack->arr =  (int *)malloc(stack->capacity * sizeof(int));

    return stack;
}

int isEmpty(struct Stack *stack)
{
    
    return stack->top == -1;
}
int isFull(struct Stack *stack)
{
    return stack->top == ((stack->capacity)-1);
}
void push (struct Stack *stack, int data)
{
    if(isFull(stack))
    {
        printf("stack is full \n");
        return;
    }
    stack->top++;
    stack->arr[stack->top]=data;
}

int pop(struct Stack *stack )
{
    if(isEmpty(stack))
    {
        printf("stack is empty\n");
        return INT_MIN;
    }
    int data = stack->arr[stack->top];
    stack->arr[stack->top]=0;
    stack->top--;
    
    return data;
}
int peek(struct Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("stack is empty\n");
        return INT_MIN;
    }
    return stack->arr[stack->top];
}
