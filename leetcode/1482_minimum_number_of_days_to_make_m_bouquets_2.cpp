class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if len(bloomDay) < m * k:
            return -1
        low = 1
        high = 1000000000
        while low < high:
            mid = low + (high - low) // 2
            flowers = 0
            bouquets = 0
            for val in bloomDay:
                if mid >= val:
                    flowers += 1
                else:
                    flowers = 0
                if flowers == k:
                    bouquets += 1
                    flowers = 0
            if bouquets >= m:
                high = mid
            else:
                low = mid + 1
        return low
