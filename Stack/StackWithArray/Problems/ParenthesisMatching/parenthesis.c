#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    char *arr;
};

int isFull(struct Stack *ptr){
    if(ptr->size == (ptr->size)-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct Stack *ptr){
    if(ptr->top == -1){
        return 1;
    }else{
        return 0;
    }
}

int push(struct Stack *ptr,char a){
    if(isFull(ptr)==1){
        return 1;
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = a;
    }   

}

char pop(struct Stack *ptr){
    if(isEmpty(ptr)==1){
        return 1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

void traverse(struct Stack *ptr){
    for(int i=0; i<=ptr->top; i++){
        printf("%c\n",ptr->arr[i]);
    }
}

int checkExp(char *exp){
    struct Stack *sp;
    sp = (struct Stack *)malloc(sizeof(struct Stack));

    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size *sizeof(char));

    for(int i=0; exp[i]!='\0'; i++){
       
        if(exp[i] == '{'){
            push(sp,'{');
        }
        else if(exp[i] == '}'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }

    if(isEmpty(sp)){
        return 1;
    }
}

void main(){
    char *exp = "int func()a+b}";
    if(checkExp(exp)){
        printf("The parenthesis is matching\n");
    }else{
        printf("The parenthesis is not mathing\n");
    }
}