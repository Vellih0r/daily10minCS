#include <stdio.h>
#include <stdlib.h>

int * merge_sort(int []);
int * merge(int*, int*, int, int);

int main()
{
    // test merge sort
    printf("Hello\n");
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    merge_sort(arr);
}

// sorting algorithm that implements recursion
int * merge_sort(int arr[])
{
    // split array into two sub arrays
    int low = 0;
    int high = (int)sizeof(&arr);
    // fix high index
    high++;
    // find mid valu
    int mid = low + (high-low)/2;
    // base case (only one element)
    if (low == high)
        return arr;
    // loggin
    printf("low=%d high=%d mid=%d\n", low, high, mid);
    int * left_arr = (int *)malloc(mid); 
    // right arr is everething after mid (including mid)
    int * right_arr = (int *)malloc(high-mid-1);
    for (int i = 0; i < mid; i++)
        left_arr[i] = arr[i];
    for (int c = 0, i = mid; i < high; i++, c++)
        right_arr[c] = arr[i];
    // display arrays
    for (int i = 0; i < mid; i++)
        printf("left - %d\n", left_arr[i]);
    for (int j = 0; j <= high-mid-1; j++)
        printf("right - %d\n", right_arr[j]);
    // free memory
    free(left_arr);
    free(right_arr);
    /* recursive calls
    merge sort left
    merge sort right
    */
    // merge
    // return merge left, right
    return arr;
}


int * merge(int * left, int * right, int mid, int high)
{
    /*
    merged = (int *)malloc(high)
    for (int i = 0, l=0, r=0; i < high; i++)
    min = compare left[l] right[r]
    if (min == left[l]) l++
    if (min == right[r]) r++
    merged[i] = min
    */
    // return merged
    return left;
}
