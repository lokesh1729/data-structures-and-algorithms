"""
Question-1 : Given an array nums with n objects colored red, white, or blue, sort them
in-place so that objects of the same color are adjacent,
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.


Input: nums = [2,0,2,1,1,0]


               |         |
            [0, 0, 2, 1, 1, 2]

        [0, 1, 1, 1, 1, 1, 0, 2, 2, 2]
            |        |     |
            l        k     r    

O(nlogn)

O(2n) -> O(n)


0... l-1 -> make sure all are 0

r...n-1 -> make sure all are 2

l....r -> make sure all are 1

* if arr[l] is 2 and arr[r] is 0, swap them, move l and r

* if arr[l] is 2 and arr[r] is 1


Output: [0,0,1,1,2,2]

* order ? -> no

"""
def rearrange_array(arr):
    n = len(arr)
    l = 0
    r = n-1
    k = 0
    while k < r:
        if arr[k] == 2:
            arr[k], arr[r] = arr[r], arr[k]
            r -= 1
        elif arr[k] == 0:
            arr[k], arr[l] = arr[l], arr[k]
            l += 1
        k += 1
    return arr

"""

when k is at 2, 
    -> l can be at 1, 2
    -> r can be at 0, 1

[0,0,1,1,2,2]
   |   |
   l   r
     k
"""

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        l = 0
        r = n-1
        k = 0
        while k <= r:
            if nums[k] == 2:
                nums[k], nums[r] = nums[r], nums[k]
                r -= 1
            elif nums[k] == 0:
                nums[k], nums[l] = nums[l], nums[k]
                l += 1
                k += 1
            elif nums[k] == 1:
                k += 1
        return nums



if __name__ == "__main__":
    print(rearrange_array([2,0,2,1,1,0]))
