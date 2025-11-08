#include <stdio.h>

void display(int arr[], int size){
    for(int i=0; i<size;i++){
        printf("%d\n",arr[i]);
    }
}

int indDeletion(int arr[], int size, int index){
                //  1      4             
    for(int i = index; i < size-1; i++){
        arr[i] = arr[i+1];
    }
   
    return 1;
}

int main(){
    //              0 1 2 3 4 
    //              1 3 4 5
    int arr[100] = {1,2,3,4,5};
    int size = 5, element=45, index=1;

    indDeletion(arr,size,index);
    size -=1;
    printf("Size is: %d\n",size);
    display(arr,size);
}