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

# swap elenents in array
def swap(arr, a, b):
    arr[a], arr[b] = arr[b], arr[a]

# sort array by pivot and return mid position
def partition(arr, low, high):
    pivot = arr[high]
    wall = low-1

    for i in range(low, high+1):
        if arr[i] < pivot:
            wall +=1; swap(arr, i, wall)
    
    wall += 1
    swap(arr, wall, high)
    return wall

# split in halfs and sort each half
def quick_sort2(arr, low, high):
    if low < high:
        wall = partition(arr, low, high)

        quick_sort2(arr, low, wall-1)
        quick_sort2(arr, wall, high)


arr = [10,4,2,7,1,0,3,8,5,6]
quick_sort2(arr, 0, len(arr)-1)
print(arr)

def merge_sort(arr):
    # basic case
    if len(arr) < 2: return arr
    length = len(arr)
    mid = length // 2
    # recursevly split arr to 2 halfs
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left, right)
def merge(left, right):
    result = []
    i = 0; j = 0
    mid = len(left)
    high = len(right)
    while (i < mid and j < high):
        if left[i] < right[j]:
            result.append(left[i]); i+=1
        else: result.append(right[j]); j+=1
    # merge ramainder
    while (i < mid): result.append(left[i]); i+=1
    while (j < high): result.append(right[j]); j+=1
    return result

