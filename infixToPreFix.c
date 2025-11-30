#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include "stack.c"

int isOperator(char ch)
{
    return ch == '+'|| ch =='-'|| ch == '*'||ch == '/' || ch == '^' ;
}
int isRightAssociativity(char ch)
{
    return ch =='^';
}

char * reverseString(char *ch)
{
    int left =0;
    int right = strlen(ch)-1;
    while(left <right)
    {
        char c= ch[left];
        ch[left]= ch[right];
        ch[right]= c;
        left++;
        right--;
    }
    return ch;
}

int Precedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '^':return 3;
        default :return -1;
    }
}
char * infixToPrefix(char *infix)
{
    int len = strlen(infix);
    struct Stack *stack= createStack(len);
    
    char *preFix= (char *)malloc(sizeof(char)*(len+1));
    int j=0;

    for(int i=len-1;i>=0;i--)
    {
        if(isalnum(infix[i]))
        {
            preFix[j++]= infix[i];
        }
        else if(infix[i] == ')')
        {
            push(stack, infix[i]);
            
        }
        else if( infix[i] == '(')
        {
            while(stack->top >-1 && peek(stack) != ')')
            {
            
                preFix[j++] = pop(stack);

            }
            if(peek(stack)!=')')
            {
                return "INVALID EXPRESSION";
            }
            else{
                pop(stack);
            }
        }
        else if(isOperator(infix[i]))
        {
            while((stack->top >-1 && Precedence(infix[i]) <Precedence(peek(stack)))
                    ||  ((Precedence(infix[i]) == Precedence(peek(stack))) && isRightAssociativity(infix[i])))
                    {
                        preFix[j++]= pop(stack);
                    }
                    push(stack, infix[i]);
        }


    }


    while(stack->top >-1)
    {
        preFix[j++]=pop(stack);
    }
    preFix[j] = '\0';

    return reverseString(preFix);
    
}
    int evaulationOfPrefix(char *prefix)
    {
        if(prefix== NULL)
        {
            return 0;
        }
    
        int len = strlen(prefix);
        int stack[len];
        int top=-1;
        for(int i=len-1;i>=0;i--)
        {
            if(isdigit(prefix[i]))
            {
                stack[++top]= prefix[i]-'0';
            }
            else if(isOperator(prefix[i]))
            {
                if(top < 1) return -1;
                int val1=stack[top--];
                int val2 = stack[top--];
                switch(prefix[i])
                {
                    case '+': stack[++top]= val1+val2;break;
                    case '-':stack[++top]= val2-val1;break;
                    case '*':stack[++top]= val2*val1;break;
                    case '/':stack[++top]= val2/val1;break;
                    case '^':stack[++top]= pow(val2, val1);break;

                }
            }
            else
            {
                return -1;
            }
        }
        return top >-1 ? stack[top]:-1; 
    }


int main()
{
    printf("enter the expression\n");
    char infix[100];
    gets(infix);
    char *res= infixToPrefix(infix);
    char *eval= evaulationOfPrefix(res);
    printf("infix : %s converted to prefix : %s\n", infix, res);
    printf("evaluated prefix : %s to %d\n",res, eval);

}