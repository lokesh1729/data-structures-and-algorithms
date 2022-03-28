def upper_bound(arr, val):
    n = len(arr)
    low = 0
    high = n-1
    while low < high:
        mid = low + (high - low) // 2
        if arr[mid] == val:
            low = mid + 1
        elif val < arr[mid]:
            high = mid - 1
        else:
            low = mid + 1
    if arr[low] == val:
        return low + 1
    return low

def lower_bound(arr, val):
    """
        1, 2, 2, 2, 2, 3
    """
    n = len(arr)
    low = 0
    high = n-1
    while low < high:
        mid = low + (high - low) // 2
        if arr[mid] == val:
            high = mid - 1
        elif val < arr[mid]:
            high = mid - 1
        else:
            low = mid + 1
    if arr[low] == val:
        return low - 1
    return low


def find_elements(arr, m):
    """
         0  1  2  3  4  5  6  7
        [2, 2, 3, 3, 4, 5, 5, 5, 6]
        
        
    """
    arr.sort()
    result = []
    for val in m:
        l = lower_bound(arr, val[0])
        r = upper_bound(arr, val[1])
        # print("value of l is %s" % l)
        # print("value of r is %s" % r)
        result.append(r-l-1)
    return result


print(find_elements([4,3,2,2,3,5,5,5,6], [[2,3], [4,6], [5,5], [3, 4]]))



