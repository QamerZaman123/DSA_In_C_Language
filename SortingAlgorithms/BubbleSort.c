#include <stdio.h>

void printArray(int* A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubble_sort(int* A, int n){
    int temp;
    for(int i=0; i < n-1; i++){
        
        printf("Pass No %d\n",i+1);
        int isSorted = 1;
        
        for (int j = 0; j < n-1-i; j++)
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        }
    if(isSorted==1){
        return;
    }    
        
    }

}

int main() {
    // int A[] = {12, 54, 65, 7, 23, 9};
    int A[] = {1, 2, 3, 4, 5, 6,7};
    int n = sizeof(A)/sizeof(int); 
    // int n = 6;

    // printf("%d",arr_len);
    printArray(A, n);
    bubble_sort(A,n);
    printArray(A, n);


    return 0;
}
