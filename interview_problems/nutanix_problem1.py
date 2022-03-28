def find_maximum_liquid(arr):
    n = len(arr)
    left_max = []
    curr = float('-inf')
    for i in range(n):
        left_max.append((curr, i))
        curr = max(curr, arr[i])
    curr = float('-inf')
    result = 0
    for i in range(n-1, -1, -1):
        result = max(result, max(min(left_max[i][0], curr), 0) * (curr - left_max[i][1]))
    return result
    

print(find_maximum_liquid([1,6,5,2]))
print(find_maximum_liquid([1,3,2,2,4,4]))
