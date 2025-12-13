#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void ArrayTraversal(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", A[i]);
    }
    printf("\n");
}

//finding maximum number in the main array
int maximum(int A[], int size){
    int max = INT_MIN;

    for(int i=0; i<size; i++){
        if(max<A[i]){
            max = A[i];
        }
    }
    return max;
}

void countSort(int *A,int size){
    int i,j;

    int max = maximum(A,size);

    int * count = (int *)malloc((max+1) * sizeof(int));
    
    //Initialize the count array elements to 0
    for(i=0; i<max+1; i++){
        count[i] = 0;
    } 

    // Increment correspondng index as the elemtns in main array in the count array
    for(i=0; i<size; i++){
        count[A[i]] = count[A[i]]+1;
    }

    i=0;
    j=0;

    while(i <= max){
        if(count[i]>0){
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }else{
            i++;
        }
    }

}

int main(){
    int A[] = {3, 1, 9, 7, 1, 2, 4};
    int size = sizeof(A)/sizeof(int);

    printf("Before Count Sort\n");
    ArrayTraversal(A,size);

    printf("After Count Sort");
    countSort(A,size);
    ArrayTraversal(A,size);

    // printf("%d",maximum(A,size));
}