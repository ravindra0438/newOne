#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include "stack.c"



int precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':return 1;
        case '/':
        case '*':return 2;
        case '^':return 3;
        default :return -1;
    }
}
int isOperator(char ch)
{
    return ch == '+' || ch=='-' || ch =='*'|| ch=='/'||ch == '^';
}

char *infixToPostFix(char *infix)
{
    int len=strlen(infix);
    int i,j=0;
    char *postFix= (char *) malloc(sizeof(char )* len);
    char stack[100];
    int top=-1;
    for(int i=0;i<len;i++)
    {
        if(infix[i] == ' ') 
        {
            postFix[j++] = infix[i];
        }
       else if(isalnum(infix[i]))
        {
            while(isalnum(infix[i]))
            {
            postFix[j++]= infix[i];
            i++;
            }
            i--;
        }
        else if(infix[i] == '(')
        {
            stack[++top]= infix[i];
        }
        else if(infix[i] ==')')
        {
            while(top >-1 && stack[top] !='(')
            {
                postFix[j++]= stack[top--];
            }
            if(stack[top] != '(')
            {
                return "invalid expression";    
            }
            else{
                top--;
            }
        }
        else if(isOperator(infix[i])){
            while(top >-1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postFix[j++]= stack[top--];
            }
            stack[++top]= infix[i];
        }
    }
    while(top>-1)
    {
        postFix[j++]=stack[top--];
    }
    postFix[j]='\0';
    return postFix;
}

int postFixEvaluation(char *postFix)
{
    int len = strlen(postFix);
    struct Stack *stack=createStack(len);
    for(int i =0;i<len;i++)
    {
        if(postFix[i]== ' ') continue;
        else if(isdigit(postFix[i]))
        {
            
            int num =0;
            while(isdigit(postFix[i]))
            {
                num = num*10 + (int )(postFix[i]-'0');
                i++;

            }
            i--;
           
            push(stack, num);
        }
        else if(isOperator(postFix[i]))

        {
            int val1=pop(stack);
            int val2= pop(stack);
                switch(postFix[i])
                {
                    case '+': push(stack, val1+val2);break;
                    case '-':push(stack, val2-val1);break;
                    case '*':push(stack, val2*val1);break;
                    case '/':push (stack, val2/val1);break;

                }
        }
    }
    return pop(stack);
}
int main()
{
    printf ("enter the expression\n");
    char infix[100];
    gets(infix);
    char *postFix = infixToPostFix(infix);
    printf("infix : %s  to post fix : %s", infix, postFix);
    int res= postFixEvaluation(postFix);
    printf(" postfix : %s result :%d", postFix, res);
}
