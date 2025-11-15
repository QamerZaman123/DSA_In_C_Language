#include <stdio.h>
#include <stdlib.h>

// Using array for stack implementation
struct Stack
{
    char *arr; // array that will store stack items
    int size; // total size of stack or array
    int top;  // this is index or top of array(stack)
};

int isEmpty(struct Stack *s)
{
    // if top is -1 then stack is empty
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack *s)
{
    // top is the "index" so we do "(s->size) - 1" as it start like 1
    if (s->top == (s->size) - 1)
    {
        return 1;
    }
    return 0;
}

int push(struct Stack *s, char val)
{
    if (isFull(s))
    {
        return 0;
    }
    s->top++;
    s->arr[s->top] = val;
    return 1;
}

char pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
    }
    char val = s->arr[s->top];
    s->top--;
    return val;
}

char peek(struct Stack *s, int i)
{
    int arr_index = s->top - i + 1;
    if (isEmpty(s))
    {
        printf("Stack Undeflow\n");
    }
    if (i <= 0 || arr_index <= 0)
    {
        printf("Invalid position i\n");
    }
    char val = s->arr[arr_index];
    return val;
}

char stackTop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow");
    }
    char val = s->arr[s->top];
    return val;
}

int stackBottom(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow");
    }
    char val = s->arr[0];
    return val;
}

void traverse(struct Stack *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("%c\n", s->arr[i]);
    }
}

void traverse_rev(struct Stack *s)
{
    for (int i = 0 ; i <= s->top; i++)
    {
        printf("%c\n", s->arr[i]);
    }
}

void main(void)
{
    struct Stack *s;

    s = (struct Stack *)malloc(sizeof(struct Stack)); // dynamic memory allocation for stack
    s->top = -1;                                      // Initialize top to "-1" for tracking top (we will increase it as values added to stack -1 means empty)
    s->size = 20;                                      // Initialize top to "-1" for tracking top (we will increase it as values added to stack -1 means empty)
    s->arr = (char *)malloc(s->size * sizeof(char));    // dynamic memory for our array

    int res; 
    res = push(s, 'a');
    res = push(s, 'b');
    res = push(s, 'c');
   
    if(res == 1){

        printf("Stack top is %c\n", stackTop(s));
        printf("Stack bottom is %c\n", stackBottom(s));
        
        printf("Traversal\n");
        traverse(s);

        printf("Traversal_rev\n");
        traverse_rev(s);

        printf("Peeked: %c\n", peek(s,1));
        printf("Popped: %c\n", pop(s));
    }

    free(s);
    free(s->arr);
}