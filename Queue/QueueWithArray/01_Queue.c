#include <stdio.h>
#include <stdlib.h>


struct Queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

int isFull(struct Queue *q){
    if(q->r == q->size - 1){
        return 1;
    }
    return 0;
}

int enqueue(struct Queue *q, int val){
    if(isFull(q)){
        return -1;
    }
    q->r++;
    q->arr[q->r] = val;
    return q->arr[q->r];
}

int dequeue(struct Queue *q){
    if(isEmpty(q)){
        return -1;
    }
    q->f++;
    return q->arr[q->f];
}

int main(){
    struct Queue *q;
    q = (struct Queue *) malloc(sizeof(struct Queue));
    
    q->size = 10;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    printf("%d\n", enqueue(q,900));
    printf("%d\n", enqueue(q,100));
    printf("%d\n", enqueue(q,300));

    printf("Dequeue: %d\n",dequeue(q));
}