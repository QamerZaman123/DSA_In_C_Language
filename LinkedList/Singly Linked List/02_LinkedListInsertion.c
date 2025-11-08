#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;    
};

void LinkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1: Insert a node at start
struct Node * InsertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));

    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Case 2: Insert a node at the end
struct Node * InsertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 3: Insert a node at an provided index or between
struct Node * InsertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    int i = 0;
    while(i!=index-1){
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 4: Insert if we have provided with previous node or the location
struct Node * InsertAtSpecificPlace(struct Node *head, struct Node *prevNode, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data,

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // InsertAtFirst:
    printf("Before InsertAtFirst\n");
    LinkedListTraversal(head);
    printf("After InsertAtFirst\n");
    head = InsertAtFirst(head, 444);
    LinkedListTraversal(head);

    // InsertAtIndex:
    // printf("Before InsertAtIndex\n");
    // LinkedListTraversal(head);
    // printf("After InsertAtIndex\n");
    // head = InsertAtIndex(head,100, 1);
    // LinkedListTraversal(head);
    
    // InsertAtEnd:
    // printf("Before InsertAtEnd\n");
    // LinkedListTraversal(head);
    // printf("After InsertAtEnd\n");
    // head = InsertAtEnd(head,500);
    // LinkedListTraversal(head);

    // InsertAtSpecificPlace:
    // printf("Before InsertAtSpecificPlace\n");
    // LinkedListTraversal(head);
    // printf("After InsertAtSpecificPlace\n");
    // head = InsertAtSpecificPlace(head,second,600);
    // LinkedListTraversal(head);

}