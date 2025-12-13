#include <stdio.h>


void ArrayTraversal(int *A, int size){
    for(int i=0; i < size-1; i++){
        printf("%d\n",A[i]);
    }
    printf("\n");
}

int partition(int *A, int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] < pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }

        if(i < j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void QuickSort(int *A, int low, int high){
    int partitionIndex;//Index of pivot after partition
    
    if(low < high){
        partitionIndex = partition(A,low,high);
        QuickSort(A, low, partitionIndex-1);
        QuickSort(A, partitionIndex+1, high);
    }
}

int main(){
    int A[] = {3, 5, 2, 13, 12};
    int size = sizeof(A)/sizeof(int);

    printf("Before Quick Sort\n");
    ArrayTraversal(A,size);

    printf("After Quick Sort\n");
    QuickSort(A,0,size-1);
    ArrayTraversal(A,size);
}