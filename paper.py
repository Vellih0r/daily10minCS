def sum(arr):
    if len(arr) == 0:
        return 0
    if len(arr) == 1:
        return arr[0]

    return arr[0] + sum(arr[1:])

def max(arr):
    if len(arr) == 0:
        return 0
    if len(arr) == 1:
        return arr[0]
    
    res = max(arr[1:])
    return arr[0] if arr[0] > res else res

def bin_s(arr, key, low=0, high=None):
    if not high: high = len(arr)-1
    # base case if arr is empty
    if low > high: return -1
    mid = (low+high)//2
    guess = arr[mid]
    # base case if found
    if guess == key: return mid
    # define new low and high
    if guess > key: high = mid-1
    else: low = mid+1
    # recursive case
    return bin_s(arr, key, low, high)

def quick_sort(arr):
    if len(arr) < 2: return arr

    pivot = arr[0]
    left = [i for i in arr[1:] if i < pivot]
    right = [i for i in arr[1:] if i > pivot]
    return quick_sort(left) + [pivot] + quick_sort(right)
arr = [10,4,2,7,1,0,3,8,5,6]
print(quick_sort(arr))

# arr = [4,6,2]
# print(sum(arr))


# print(max(arr))