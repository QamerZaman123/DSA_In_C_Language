#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void traverseRight(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

void traverseLeft(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->prev;
    }
}

// Case 1: Insert at first
struct Node * InsertAtFirst(struct Node *N_1, int data){
    struct Node *New_Node = (struct Node *)malloc(sizeof(struct Node));
    New_Node->data = data;
    New_Node->prev = NULL;

    struct Node *p = N_1;

    p->prev = New_Node;
    New_Node->next = p;
    return New_Node;
}

// Case 2: Insert at the end
struct Node * InsertAtEnd(struct Node *N_1, int data){
    struct Node *New_Node = (struct Node *)malloc(sizeof(struct Node));
    New_Node->data = data;
    struct Node *p = N_1;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = New_Node;
    New_Node->prev = p;
    New_Node->next = NULL;

    return N_1;
}

void main(){
    struct Node *N1;
    struct Node *N2;

    N1 = (struct Node *)malloc(sizeof(struct Node));
    N2 = (struct Node *)malloc(sizeof(struct Node));

    N1->data = 1;
    N1->prev = NULL;
    N1->next = N2;

    N2->data = 2;
    N2->prev = N1;
    N2->next = NULL;
    
    // traverseRight(N1);
    // printf("After Insertion\n");
    // N1 = InsertAtFirst(N1,300);
    // traverseRight(N1);

    // traverseRight(N1);
    // printf("After Insertion\n");
    // N1 = InsertAtEnd(N1,300);
    // traverseRight(N1);


}