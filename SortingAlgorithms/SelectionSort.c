#include <stdio.h>

void ArrayTraversal(int *A, int size){
    for(int i=0; i < size-1; i++){
        printf("%d\n",A[i]);
    }
    printf("\n");
}

void SelectionSort(int *A, int size){
    int temp, indexOfMin;

    for(int i=0; i<size; i++){
        indexOfMin = i; //0 1 2
        printf("indexOfMin:%d\n",indexOfMin);

        for(int j=i+1; j<size; j++){
            printf("j:%d\n",j);//1 2 3

            if(A[j] < A[indexOfMin]){ // 5 < 3 | 2 < 5 | 13 < 5
                indexOfMin = j; // 2
                printf("indexOfMin:%d if A[j]:%d is less then A[indexOfMin]:%d\n",indexOfMin,A[j],A[indexOfMin]);
            }
        }
        temp = A[i]; // 3 | 5
        A[i] = A[indexOfMin]; // 3 = 3 | 5 = 2
        A[indexOfMin] = temp; // 3 = 3 | 2 = 5
    }
}

int main(){
    int A[] = {3, 5, 2, 13, 12};
    int size = sizeof(A)/sizeof(int);

    printf("Before Selection Sort\n");
    ArrayTraversal(A,size);

    printf("After Selection Sort\n");
    SelectionSort(A,size);
    ArrayTraversal(A,size);

}