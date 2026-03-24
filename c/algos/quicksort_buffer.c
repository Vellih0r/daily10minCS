#include <stdio.h>
#include <stdlib.h>

int partition(int * arr, int * buffer, int low, int high)
{
    int pivot = arr[low];
    int k = low;

    // [ i for i in arr if i < pivot ]
    for (int i = low+1; i <= high; i++)
    {
        if (arr[i] < pivot)
            buffer[k++] = arr[i];
    }
    int pivot_index = k;
    buffer[k++] = pivot;
    // [ i for i in arr if i >= pivot ]
    for (int i = low+1; i <= high; i++)
    {
        if (arr[i] >= pivot)
            buffer[k++] = arr[i];
    }
    // copy back to arr
    for (int i = low; i <= high; i++)
    {
        arr[i] = buffer[i];
    }
    return pivot_index;
}

void quicksort(int* arr, int* buffer, int low, int high)
{
    if (low >= high)
        return;

    int mid = partition(arr, buffer, low, high);

    quicksort(arr, buffer, low, mid-1);
    quicksort(arr, buffer, mid+1, high);    
}

int main()
{
    int arr[] = {4,1,3,2,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int* buffer = malloc(sizeof(arr[0]) * n);
    quicksort(arr, buffer, 0, n-1);
    for (int i=0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(buffer);
    return 0;
}
