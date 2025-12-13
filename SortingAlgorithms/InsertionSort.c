#include <stdio.h>

void ArrayTraversal(int *A, int size){
    for(int i=0; i < size-1; i++){
        printf("%d\n",A[i]);
    }
    printf("\n");
}

void InsertionSort(int *A, int size){
    // key: Element which may or may not be shifted to its sorted position (key = A[i])
    // j: Element before key (j = i-1)
    int key, j;
    for(int i=1; i<=size-1; i++){
        key = A[i];
        j = i-1;

        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main(){
    //         0  1 2 3 4 
    int A[] = {10,4,3,1,30};
    int size = sizeof(A)/sizeof(int);

    printf("Array Size: %d\n", size);
    printf("Before Insertion Sort\n");
    ArrayTraversal(A,size);
    printf("After Insertion Sort\n");
    InsertionSort(A,size);
    ArrayTraversal(A,size);
}