#include <stdio.h>

int LinearSearch(int arr[], int size, int element)
{
    for (int i = 0; i <= size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int arr[], int size, int element){
    int low,mid,high;
    low = 0;
    high = size-1;

    while(low <= high){
        mid = (low + high)/2;
        
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        
    }
    return -1;
}

int main()
{
    // int arr[100] = {1, 4, 7, 2, 3, 6};//unsorted
    int arr[] = {100,201,300,444,888}; //sorted

    int size = sizeof(arr)/sizeof(int), element = 100;
    // int ans = LinearSearch(arr, size, element);
    int ans = BinarySearch(arr,size,element);

    // if(ans == -1){
    //     printf("Not Found");
    // }else{
    // }
    
    printf("%d", ans);
}