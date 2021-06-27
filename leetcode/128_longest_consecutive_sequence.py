class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        a = set(nums)
        res = 0
        for e in nums:
            if e-1 not in a:
                c = 1
                num = e + 1
                while num in a:
                    num += 1
                    c += 1
                res = max(res, c)
        return res
