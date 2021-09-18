# kredx interview
# sorted and rotated array


#  0  1  2  3  4  5  6
# [6, 7, 1, 2, 3, 4, 5]

# [3, 4, 5, 6, 7, 1, 2]


# ele = 3

# if ele > arr[mid]:
#     if arr[0] > arr[mid]:
#         high = mid - 1
#     else:
#         low = mid + 1
# elif ele < arr[mid]:
#     if arr[mid] > arr[high]:
#         low = mid + 1
#     else:
#         high = mid - 1
# else:
#     return mid

# [3, 4, 5, 6, 7, 1, 2]

# ele = 2

# ele = 6

# arr[0] > arr[mid]

# ele > arr[mid]


# [1, 2, 3, 4, 5, 6, 7]

# arr[0] < arr[mid]

# 6

# binary search


# search a given element in O(logn) time


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return self.search_loop(nums, target)
    
    def search_recursive(self, nums: List[int], target: int) -> int:
        min_index = self.find_min_index(nums)
        print(min_index)
        if min_index != -1:
            if target == nums[min_index]:
                return min_index
            if target >= nums[min_index] and target <= nums[len(nums) - 1]:
                return self.binary_search(nums, min_index + 1, len(nums) - 1, target)
            else:
                return self.binary_search(nums, 0, min_index - 1, target)
        return -1
    
    def search_loop(self, nums: List[int], target: int) -> int:
        n = len(nums)
        low = 0
        high = n-1
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] > nums[high]: # in rotated sub-array
                if nums[low] <= target <= nums[mid]:
                    high = mid - 1
                else:
                    low = mid + 1
            else: # in non-rotated sub-array
                if nums[mid] <= target <= nums[high ]:
                    low = mid + 1
                else:
                    high = mid - 1
        return -1
    
    def search_big_on(self, nums: List[int], target: int) -> int:
        n = len(nums)
        low = 0
        high = n-1
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] > nums[high]: # in rotated sub-array
                if target < nums[low]:
                    low = mid + 1
                elif target > nums[low]:
                    if target < nums[mid]:
                        high = mid - 1
                    elif target > nums[mid]:
                        low = mid + 1
                    else:
                        return mid
                else:
                    return low
            else: # in non-rotated sub-array
                if target < nums[mid]:
                    high = mid - 1
                elif target > nums[mid]:
                    if target > nums[high]:
                        high = mid - 1
                    elif target < nums[high]:
                        low = mid + 1
                    else:
                        return high
                else:
                    return mid
        return -1
    
    def find_min_index2(self, nums):
        n = len(nums)
        low = 0
        high = n - 1
        while low <= high:
            mid = low + (high - low) // 2
            if mid < high and nums[mid] < nums[mid-1] and nums[mid] < nums[mid+1]:
                return mid
            if nums[low] < nums[mid]:
                low = mid + 1
            else:
                high = mid - 1
        return -1
    
    def find_min_index(self, nums):
        n = len(nums)
        low = 0
        high = n - 1
        while low < high:
            mid = low + (high - low) // 2
            if nums[mid] > nums[high]:
                low = mid + 1
            else:
                high = mid
        return low
    
    def binary_search(self, nums, start, end, target):
        if start > end:
            return -1
        low = start
        high = end
        while low <= high:
            mid = low + (high - low) // 2
            if target == nums[mid]:
                return mid
            elif target < nums[mid]:
                high = mid - 1
            else:
                low = mid + 1
        return -1
