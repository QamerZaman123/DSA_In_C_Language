#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == (ptr->size) - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(int val, struct Stack *ptr)
{
    if (isFull(ptr) == 1)
    {
        return -1;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        return val;
    }
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr) == 1)
    {
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct Stack *ptr, int i)
{
    int arr_index = ptr->top - i + 1;
    if (i <= 0 || arr_index < 0)
    {
        return 0; // Return 0 for invalid cases
    }
    else
    {
        return ptr->arr[arr_index];
    }
}

int stackTopElement(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    return ptr->arr[ptr->top];
}

int stackBElement(struct Stack *ptr){
    if(isEmpty(ptr)){
        return -1;
    }
    return ptr->arr[0];
}

int main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // push operation
    push(200, s);
    push(300, s);
    push(400, s);

    // pop operation
    // pop(s);

    // Getting stack top element: try it with empty or filled stack
    printf("The top is %d\n", stackTopElement(s));

    // Getting stack top element: try it with empty or filled stack
    printf("The bottom is %d", stackBElement(s));

    // peek opeartion
    // Printing every element with position(starting from 1)
    //  for(int j=1; j <= s->top + 1 ; j++){
    //      printf("The value at position %d is %d\n", j, peek(s,j));
    //  }
    // finding the element on specific position
    //  printf("%d", peek(s,-1));

    // Testing if stack is empty or full

    // if(isEmpty(s) == 1){
    //     printf("Stack is Empty");
    // }else{
    //     printf("Stack is not empty");
    // }

    // if(isFull(s) == 1){
    //     printf("Stack is Full");
    // }else{
    //     printf("Stack is not Full");
    // }
}