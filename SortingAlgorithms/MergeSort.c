#include <stdio.h>

void ArrayTraversal(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", A[i]);
    }
    printf("\n");
}

void merge_procedure(int A[], int mid, int low, int high)
{
    int i, j, k;
    int B[100];

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    for(int i=low; i<=high; i++){
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge_procedure(A,mid,low,high);
    }
}

int main()
{
    int A[] = {3, 5, 2, 13, 12};
    int size = sizeof(A) / sizeof(int);

    printf("Before Quick Sort\n");
    ArrayTraversal(A, size);

    printf("After Quick Sort\n");
    mergeSort(A,0,size-1);
    ArrayTraversal(A, size);
}