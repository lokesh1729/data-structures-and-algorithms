class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        result = 0
        prev_res = 0
        l = 0
        r = 0
        n = len(nums)
        while r < n:
            if nums[r] <= right and nums[r] >= left:
                prev_res = r - l + 1
                result += prev_res
            elif nums[r] < left:
                result += prev_res
            else:
                l = r + 1
                prev_res = 0
            r += 1
        return result
