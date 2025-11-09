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

//Insertion
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

// Case 4: Insert after a specific value containing node
struct Node * InsertAfter(struct Node *head, int data, int val){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    struct Node *q = p->next;

    while(q->data != val){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;

    return head;


}

//Deletion
// Case 1: Delete the first Node
struct Node * dFirst(struct Node *head){
    
    struct Node *p = head;

    while(p->next!=head){
        p = p->next;
    }
    
    p->next = head->next;
    free(p);
    head = p->next;
    return head;

}

// Case 2: Delete the last node
struct Node * dLast(struct Node *head){
    struct Node *p = head;
    struct Node *q = p->next;

    while(q->next != head){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Case 3: Delete at index
struct Node * dIndex(struct Node *head, int index){
    struct Node *p = head;
    
    int i = 0;
    while(i!=index-1){ 
        p = p->next;
        i++;
    }

    struct Node *q = p->next;

    p->next = q->next;

    free(q);

    return head;
}

// Case 4: Delete a specific value containing node
struct Node * dVal(struct Node *head, int val){
    struct Node *p = head;  
    struct Node *q = p->next;

    while(q->data != val){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
}

void main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 199;
    fourth->next = head;

    // Test Insertion Here
    // traverseList(head);
    // printf("After Insertion\n");
    // head = InsertAtFirst(head,1); //Case 1
    // InsertAtEnd(head,200); //Case 2
    // InsertAtIndex(head,300,2); //Case 3
    // InsertAfter(head, 202, 3); // Case 4
    // traverseList(head);


    // Test Deletion Here:
    // traverseList(head);
    // printf("After Deletion\n");
    // head = dFirst(head); //Case 1
    // dLast(head); //Case 2
    // dIndex(head); //Case 3
    // dVal(head); //Case 4
    // traverseList(head);


}