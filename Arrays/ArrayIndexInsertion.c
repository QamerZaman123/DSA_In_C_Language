#include <stdio.h>

void display(int arr[], int size){
    for(int i=0; i<size;i++){
        printf("%d\n",arr[i]);
    }
}

int indInsertion(int arr[], int size, int element, int index, int capacity){
    if(size>=capacity){
        return -1;
    }
    for(int i = size-1; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    
    return 1;
}


int main(){
    int arr[100] = {1,2,3,4,5};
    int size = 5, element=45, index=3;

    indInsertion(arr,size,element,index,100);
    size +=1;
    printf("Size is: %d\n",size);
    display(arr,size);
}