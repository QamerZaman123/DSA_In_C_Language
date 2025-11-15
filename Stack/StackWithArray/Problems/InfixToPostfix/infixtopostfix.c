#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int isFull(struct Stack *s)
{
    if (s->size == s->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int push(struct Stack *s, char exp)
{
    if (isFull(s))
    {
        return 0;
    }
    s->top++;
    s->arr[s->top] = exp;
    return 1;
}

char pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        return 0;
    }
    char val = s->arr[s->top];
    s->top--;
    return val;
}

int stackTopElement(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    return ptr->arr[ptr->top];
}

int precedence(char ch){
    if(ch == '*' || ch=='/'){
        return 3;
    }else if(ch == '+' || ch=='-'){
        return 2;
    }else{
        return 0;
    }
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' ){
        return 1;
    }
    return 0;
}

char *infixToPostfix(struct Stack *s, char *infix)
{
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;

    // while loop started
    while (infix[i] != '\0')
    {
        // if start
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        // if end

        // else start
        else{
            if(precedence(infix[i]) > precedence(stackTopElement(s))){
                push(s,infix[i]);
                i++;
            }else{
                postfix[j] = pop(s);
                j++;
            }
        }
        // else end
    }
    // while loop ended

    // while loop started
    while(!isEmpty(s)){
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    // while loop ended

    return postfix;
}

void main(void)
{
    struct Stack *s;
    s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = -1;
    s->size = 100;
    s->arr = (char *)malloc(s->size * sizeof(char));

    char *infix = "a-b+t/6";
    printf("postifx is %s\n", infixToPostfix(s,infix)); 
}