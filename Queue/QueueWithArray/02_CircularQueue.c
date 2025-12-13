#include <stdio.h>
#include <stdlib.h>


struct Circular_Queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Circular_Queue *q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

int isFull(struct Circular_Queue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

int enqueue(struct Circular_Queue *q, int val){
    if(isFull(q)){
        return -1;
    }
    q->r = (q->r+1) % q->size;
    q->arr[q->r] = val;
    return q->arr[q->r];
}

int dequeue(struct Circular_Queue *q){
    if(isEmpty(q)){
        return -1;
    }
    q->f = (q->f+1) % q->size;
    return q->arr[q->f];
}

int main(){
    struct Circular_Queue *q;
    q = (struct Circular_Queue *) malloc(sizeof(struct Circular_Queue));
    
    q->size = 4;
    q->f = 0;
    q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    printf("%d\n", enqueue(q,900));
    printf("%d\n", enqueue(q,100));
    printf("%d\n", enqueue(q,300));
    printf("%d\n", enqueue(q,300));

    printf("Dequeue: %d\n",dequeue(q));
    printf("Dequeue: %d\n",dequeue(q));
    printf("Dequeue: %d\n",dequeue(q));
    printf("Dequeue: %d\n",dequeue(q));

    printf("%d\n", enqueue(q,1000));
    printf("%d\n", enqueue(q,1000));
    printf("%d\n", enqueue(q,1000));

}