#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node *right;
};

struct Node * createNode(int data_val){
    struct Node *n;
    n = (struct Node *) malloc(sizeof(struct Node));
    n->data = data_val;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void preorder(struct Node *root){
    if(root!=NULL){
        printf("%d\n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\n",root->data);
    }
}

void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}

int main(){
    // --------Better Way--------
    struct Node *p = createNode(2);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(4);

    
    p->left = p1;
    p->right = p2;

    p1->left = createNode(2);
    p1->right = createNode(1);

    p2->left = createNode(2);
    p2->right = createNode(2);

    //         2
    //       /   \
    //      1     4
    //     / \   / \ 
    //    2   1  2  2

    printf("PreOrder Traversal\n");
    preorder(p); // 2 1 2 1 4 2 2
    printf("PostOrder Traversal\n");
    postorder(p); // 2 1 1 2 2 4 2 
    printf("InOrder Traversal\n");
    inorder(p); // 2 1 1 2 2 4 2 
    // --------Better Way--------

    //--------Hectic Way-----------
    // struct Node *p;
    // p = (struct Node *) malloc(sizeof(struct Node));
    // p->data =2;
    // p->left = NULL;
    // p->right = NULL;

    // struct Node *p1;
    // p1 = (struct Node *) malloc(sizeof(struct Node));
    // p1->data =1;
    // p1->left = NULL;
    // p1->right = NULL;

    // struct Node *p2;
    // p2 = (struct Node *) malloc(sizeof(struct Node));
    // p2->data =4;
    // p2->left = NULL;
    // p2->right = NULL;

    // p->left = p1;
    // p->right = p2;
    //--------Hectic Way-----------

    return 0;
}
