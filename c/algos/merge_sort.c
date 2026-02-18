#include <stdio.h>
#include <stdlib.h>

int * merge_sort(int [], int);
int * merge(int*, int*, int, int);

int main()
{
    // test merge sort
    int arr[] = {5,3,1,2,6,4,9,8,10,7};
    int length = sizeof(arr) / sizeof(int);
    int * newarr = merge_sort(arr, length);
    for (int i = 0; i<length; i++)
        printf("%d\n", newarr[i]);
}

// sorting algorithm that implements recursion
int * merge_sort(int * arr, int length)
{
    int low = 0;
    // base case (only one element)
    if (length <= 1)
        return arr;
    // find mid value
    int mid = low + (length-low)/2;
    // loggin
    printf("low=%d length=%d mid=%d\n", low, length, mid);
    int * left_arr = (int *)malloc(sizeof(int)*mid); 
    // right arr is everething after mid (including mid)
    int * right_arr = (int *)malloc(sizeof(int)*(length-mid));
    for (int i = 0; i < mid; i++)
        left_arr[i] = arr[i];
    for (int c = 0, i = mid; i < length; i++, c++)
        right_arr[c] = arr[i];
        
    // recursive calls
    left_arr = merge_sort(left_arr, mid);
    right_arr = merge_sort(right_arr, length-mid);
    // merge
    arr = merge(left_arr, right_arr, mid, length);
    // free memory
    //free(left_arr);
    //free(right_arr);
    // return merge left, right
    return arr;
}


int * merge(int * left, int * right, int mid, int length)
{
    int count_r, count_l, len_r, len_l;
    count_r = count_l = 0;
    len_l = mid;
    len_r = length-mid;

    int * merged = (int *)malloc(sizeof(int)*length);
    
    int * m = merged;
    int r = 0;
    int l = 0;
    // paste lowest value to the new merged arr
    while (count_r < len_r && count_l < len_l)
    {
        r = right[count_r];
        l = left[count_l];
        if (r < l)
        {
            *m = r;
            count_r++;
        }
        else
        {
            *m = l;
            count_l++;
        }
        m++;
    }
    while (count_r < len_r)
    {
        *m = right[count_r++];
        m++;
    }
    while (count_l < len_l)
    {
        *m = left[count_l++];
        m++;
    }
    return merged;
}

/*
    // display arrays
    for (int *l = left_arr; *l; l++)
        printf("left - %d\n", *l);
    for (int *r = right_arr; *r; r++)
        printf("right - %d\n", *r);
*/

