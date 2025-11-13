#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    char *arr;
};

int isFull(struct Stack *s){
    if(s->size == s->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Stack *s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

int push(struct Stack *s, char exp){
    if(isFull(s)){
        return 0;
    }
    s->top++;
    s->arr[s->top] = exp;
    return 1;
}

char pop(struct Stack *s){
    if(isEmpty(s)){
        return 0;
    }
    char val = s->arr[s->top];
    s->top--;
    return val;
}

int match(char openBracket, char closeBracket){
    if(openBracket=='{' && closeBracket=='}'){
        return 1;
    }
    if(openBracket=='(' && closeBracket==')'){
        return 1;
    }
    if(openBracket=='[' && closeBracket==']'){
        return 1;
    }
    return 0;
}

int checkExp(struct Stack *s,char *exp){
    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]=='{' || exp[i]=='(' || exp[i]=='['){
            push(s,exp[i]);
        }
        else if(exp[i]=='}' || exp[i]==')' || exp[i]==']' ){
            if(isEmpty(s)){
                return 0;
            }
            char popped_ch = pop(s);
            if(!match(popped_ch,exp[i])){
                return 0;
            }
        }
    }

    if(isEmpty(s)){
        return 1;
    }

    return 0;
}

void main(void){
    struct Stack *s;
    s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = -1;
    s->size = 10;
    s->arr = (char *)malloc(s->size * sizeof(char));

    char *exp = "[4[+{(3*1)-(4-3)}]";

    if(checkExp(s,exp)){
        printf("The parenthesis is balanced\n");
    }
    else{
        printf("The parenthesis is not balanced\n");
    }

    free(s);
    free(s->arr);
}