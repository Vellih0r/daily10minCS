#include <stdio.h>

void swap(int * a, int * b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    // numbers less then pivot goes to the right of the wall
    int wall = low-1;
    for (int i=low; i<high; i++)
        if (arr[i] < pivot)
            swap(&arr[++wall], &arr[i]);
    swap(&arr[++wall], &arr[high]);
    return wall;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = partition(arr, low, high);

        quicksort(arr, low, mid-1);
        quicksort(arr, mid, high);
    }
}

int main()
{
    int arr[] = {4,10,3,7,0,2,6,9,1};
    int length = sizeof(arr) / sizeof(int);
    quicksort(arr, 0, length-1);
    for (int i=0; i<length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

