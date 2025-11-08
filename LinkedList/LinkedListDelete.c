#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

void traverse(struct Node *ptr){
    while(ptr != NULL){
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * dFirst(struct Node *head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

struct Node * dBetween(struct Node *head, int index){
    struct Node *p = head;

    int i=0;
    while(i!=index-1){
        p = p->next;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);

    return head;
}

struct Node * dLast(struct Node *head){
    struct Node *p = head;
    struct Node *q = p->next;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node * dVal(struct Node *head, int val){
    struct Node *p = head;
    struct Node *q = p->next;

    while(q->data != val && q->next != NULL){
        p = p->next;
        q = q->next;
    }

    if(q->data == val){
        p->next = q->next;
        free(q);
    }

    return head;
}

void main(){
    struct Node *head;
    struct Node *sec;
    struct Node *thr;

    head = (struct Node *)malloc(sizeof(struct Node));
    sec = (struct Node *)malloc(sizeof(struct Node));
    thr = (struct Node *)malloc(sizeof(struct Node));
    
    head->data = 33;
    head->next = sec;

    sec->data = 34;
    sec->next = thr;

    thr->data = 35;
    thr->next = NULL;

    // traverse(head);
    // printf("After");
    // head = dFirst(head);
    // traverse(head);

    // traverse(head);
    // printf("After");
    // head = dBetween(head,1);
    // traverse(head);

    // traverse(head);
    // printf("After\n");
    // head = dLast(head);
    // traverse(head);

    traverse(head);
    printf("After\n");
    head = dVal(head,34);
    traverse(head);
}