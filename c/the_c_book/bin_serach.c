#include <stdio.h>
/*Binary search, but with only 1 comparison inside loop*/
int binary_search(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n-1;
	while(low < high)
	{
		// no integer oveflow
		mid = low + (high-low) / 2;
		if (x <= v[mid])
			high = mid;
		else
			low = mid + 1;
	}
	if (low < n && v[low] == x)
		return low;
	else
		return -1;
}


int main()
{
	int arr[] =  {1, 3, 5, 7, 10, 15};
	int len = sizeof(arr) / sizeof(arr[0]);
	int target = 5;
	int result = binary_search(target, arr, len);

	if (result != -1)
		printf("Found target %d at pos %d \n", target, result);
	else
		printf("Target %d not found\n");
	return 0;
}
