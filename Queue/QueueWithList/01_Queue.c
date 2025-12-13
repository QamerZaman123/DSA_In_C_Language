#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
    int data;
    struct Node *next;
};

void printQueue(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *f)
{
    if (f == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Node *n)
{
    if (n == NULL)
    {
        return 1;
    }

    return 0;
}

int enqueue(int val){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));

    if (isFull(n))
    {
        return -1;
    }
    
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }

        return 1;
    }
}

int dequeue()
{
    int val = -1;
    struct Node *ptr = f;

    if (isEmpty(f))
    {
        return -1;
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printf("Before Dequeue\n");
    printQueue(f);

    printf("After Dequeue \n");
    dequeue();
    printQueue(f);
}