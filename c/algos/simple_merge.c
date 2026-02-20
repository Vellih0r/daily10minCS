#include <stdio.h>
#include <stdlib.h>
int * merge_sort(int*, int);
int * merge(int *, int*, int, int);

int main() {
    int arr[] = {10,4,2,7,1,0,3,8,5,6};
    int length = sizeof(arr) / sizeof(arr[0]);
    int *sorted = merge_sort(arr, length);
    for (int i = 0; i < length; i++)
        printf("%d ", sorted[i]);
    printf("\n");
}

int * merge_sort(int * arr, int length) {
    if (length < 2) {return arr;}
    int mid = length / 2;
    // get memory
    int *left = malloc(sizeof(int) * mid);
    int *right = malloc(sizeof(int) * (length - mid));
    // slice to left and right
    for (int i = 0; i < mid; i++) {left[i] = arr[i];}
    for (int i = mid; i < length; i++) {right[i - mid] = arr[i];}
    // recursive calls
    left = merge_sort(left, mid);
    right = merge_sort(right, length - mid);
    // merge
    int *merged = merge(left, right, mid, length - mid);
    free(left);
    free(right);
    return merged;
}

int * merge(int * left, int * right, int left_len, int right_len) {
    int *merged = malloc(sizeof(int) * (left_len + right_len));
    int i = 0, j = 0, k = 0;
    while (i < left_len && j < right_len) {
        if (left[i] < right[j]) {merged[k++] = left[i++];}
        else {merged[k++] = right[j++];}
    }
    // merge remaining
    while (i < left_len) {merged[k++] = left[i++];}
    while (j < right_len) {merged[k++] = right[j++];}
    return merged;
}
