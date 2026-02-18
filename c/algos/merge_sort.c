#include <stdio.h>
#include <stdlib.h>

void merge_sort(int*, int*, int, int);
void merge(int*, int*, int, int, int);

int main()
{
    // test merge sort
    int length = 5;
    int * buffer = (int *)malloc(sizeof(int)*length);
    int arrs[3][5] = { {1,2,3,4,5}, {5,4,3,2,1}, {10,5,2,4,9} };
    merge_sort(arrs[0], buffer, 0, length);
    for (int c=0, *p=arrs[0]; c<length; c++, p++)
        printf("%d - ", *p);
    printf("\n");
    merge_sort(arrs[1], buffer, 0, length);
    for (int c=0,  *p=arrs[1]; c<length; c++,p++)
        printf("%d - ", *p); 
    printf("\n");
    merge_sort(arrs[2], buffer, 0, length);
    for (int c=0, *p=arrs[2]; c<length; c++,p++)
        printf("%d - ", *p);
    printf("\n");
    free(buffer);
}

// sorting algorithm that implements recursion
void merge_sort(int * arr, int * buffer, int left, int right)
{
    // base case (only one element)
    if (right-left < 2)
        return;
    // find mid value
    int mid = left + (right-left) / 2;
    // split case to 2 smaller with indexes
    // recursive calls
    merge_sort(arr, buffer, left, mid);
    merge_sort(arr, buffer, mid, right);
    // merge
    merge(arr, buffer, left, mid, right);
}


void merge(int* arr, int* buffer, int left, int mid, int right)
{
    int i, j, k, r, l;
    i = left;
    j = mid;
    k = left;

    // paste lowest value to the new merged arr
    while (i < mid && j < right)
    {
        l = arr[i];
        r = arr[j];
        if (l < r)
        {
            buffer[k] = l;
            i++;
        }
        else
        {
            buffer[k] = r;
            j++;
        }
        k++;
    }
    while (i < mid)
    {
        buffer[k] = arr[i++];
        k++;
    }
    while (j < right)
    {
        buffer[k] = arr[j++];
        k++;
    }

    for (int i=left; i<right; i++)
    {
        arr[i] = buffer[i];
    }
}

/*
    // display arrays
    for (int *l = left_arr; *l; l++)
        printf("left - %d\n", *l);
    for (int *r = right_arr; *r; r++)
        printf("right - %d\n", *r);
*/

