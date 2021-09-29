'''
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:
                         F         F
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
                       |
                       l
                         r
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:
                       F F       F
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length


[0,0,0,1]
4

[0,0,0,0]
0
'''

def max_number_of_consecutive_ones(arr, k):
    n = len(arr)
    l = 0
    r = 0
    curr_k = 0
    result = float('-inf')
    while r < n:
        while r < n and arr[r] == 1:
            r += 1
        while r < n and arr[r] == 0 and curr_k < k:
            r += 1
            curr_k += 1
        result = max(result, r-l)
        while r < n and arr[r] == 0 and curr_k >= k:
            if arr[l] == 0:
                curr_k -= 1
            l += 1
    return result


if __name__ == "__main__":
    print(max_number_of_consecutive_ones([1,1,1,0,0,0,1,1,1,1,0], 2))
    print(max_number_of_consecutive_ones([0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], 3))
    print(max_number_of_consecutive_ones([0,0,0,1], 4))
    print(max_number_of_consecutive_ones([0,0,0,0], 0))
 
