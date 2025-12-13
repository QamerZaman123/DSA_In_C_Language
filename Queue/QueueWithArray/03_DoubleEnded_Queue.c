#include <stdio.h>
#include <stdlib.h>

struct DE_QUEUE {
    int size;
    int F;       // Front index
    int R;       // Rear index
    int *arr;
};

// Check if deque is empty
int isEmpty(struct DE_QUEUE *q) {
    return q->F == -1;
}

// Check if deque is full
int isFull(struct DE_QUEUE *q) {
    return ( (q->F == 0 && q->R == q->size - 1) || (q->F == q->R + 1) );
}

// Insert at rear
int enqueue_R(struct DE_QUEUE *q, int val) {
    if (isFull(q)) return -1;

    if (isEmpty(q)) {   // First element
        q->F = q->R = 0;
    } else if (q->R == q->size - 1) { // Wrap around
        q->R = 0;
    } else {
        q->R++;
    }

    q->arr[q->R] = val;
    return val;
}

// Insert at front
int enqueue_F(struct DE_QUEUE *q, int val) {
    if (isFull(q)) return -1;

    if (isEmpty(q)) {   // First element
        q->F = q->R = 0;
    } else if (q->F == 0) { // Wrap around to end
        q->F = q->size - 1;
    } else {
        q->F--;
    }

    q->arr[q->F] = val;
    return val;
}

// Delete from front
int dequeue_F(struct DE_QUEUE *q) {
    if (isEmpty(q)) return -1;

    int val = q->arr[q->F];

    if (q->F == q->R) {  // Only one element
        q->F = q->R = -1;
    } else if (q->F == q->size - 1) {
        q->F = 0;  // Wrap around
    } else {
        q->F++;
    }

    return val;
}

// Delete from rear
int dequeue_R(struct DE_QUEUE *q) {
    if (isEmpty(q)) return -1;

    int val = q->arr[q->R];

    if (q->F == q->R) {  // Only one element
        q->F = q->R = -1;
    } else if (q->R == 0) {
        q->R = q->size - 1; // Wrap around
    } else {
        q->R--;
    }

    return val;
}

// Display all elements
void traverse(struct DE_QUEUE *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = q->F;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->R) break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main() {
    struct DE_QUEUE *q = malloc(sizeof(struct DE_QUEUE));
    q->size = 5;          // Small size to test wrap-around
    q->F = q->R = -1;
    q->arr = malloc(q->size * sizeof(int));

    // enqueue_R(q, 10);
    // enqueue_R(q, 20);
    // enqueue_R(q, 30);
    enqueue_F(q, 5);
    enqueue_F(q, 1);

    traverse(q);

    // printf("Deleted from front: %d\n", dequeue_F(q));
    printf("Deleted from rear: %d\n", dequeue_R(q));

    traverse(q);

    free(q->arr);
    free(q);

    return 0;
}
