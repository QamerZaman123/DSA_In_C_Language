#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void traverseList(struct Node *head){
    struct Node *p = head;
    do{
        printf("Element %d\n", p->data);
        p = p->next;
    }while(p != head);
}

// Case 1: Insert at first
struct Node * InsertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;

    while(p->next != head){
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    // head = ptr;
    return ptr;
}

// Case 2: Insert at the end
struct Node * InsertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    while(p->next != head){
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    return head;
}

// Case 3: Insert at the Index or In between
struct Node * InsertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;

    int i = 0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

void main(){
    struct Node *head;
    struct Node *second;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = head;

    // traverseList(head);
    // printf("After Insertion\n");
    // head = InsertAtFirst(head,33);
    // traverseList(head);

    // traverseList(head);
    // printf("After Insertion\n");
    // InsertAtEnd(head,33);
    // traverseList(head);

    traverseList(head);
    printf("After Insertion\n");
    InsertAtIndex(head,33,1);
    traverseList(head);
}