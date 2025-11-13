#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *top)
{
    while (top != NULL)
    {
        printf("Element: %d\n", top->data);
        top = top->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));

    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node *top)
{
    if (!isEmpty)
    {
        printf("Stack Underflow: Stack is null and can't be popped out\n");
        return 1;
    }
    else
    {
        struct Node *n = top;
        top = top->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(struct Node *top,int pos){
    struct Node *p = top;

    for(int i=0; (i<pos-1 && p!=NULL); i++){
        p = p->next;
    }
    if(p!=NULL){
        return p->data;
    }else{
        return -1;
    }
}

int stackTop(struct Node *top){
    return top->data;
}

int stackBottom(struct Node *top){
    struct Node *p = top;

    while(p->next != NULL){
        p=p->next;
    }
    return p->data;
}

int main()
{
    struct Node *top;
    top = NULL;

    top = push(top, 78);
    top = push(top, 700);
    top = push(top, 700);
    // traverse(top);

    // printf("%d\n", pop(top));

    printf("Data is %d\n",peek(top,3));
    printf("top is %d\n",stackTop(top));
    printf("bottom is %d\n",stackBottom(top));
}