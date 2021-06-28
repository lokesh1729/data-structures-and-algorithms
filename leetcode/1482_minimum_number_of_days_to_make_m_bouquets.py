class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if len(bloomDay) < m * k:
            return -1
        min_blooming_day = float('inf')
        max_blooming_day = float('-inf')
        for day in bloomDay:
            min_blooming_day = min(day, min_blooming_day)
            max_blooming_day = max(day, max_blooming_day)
        low = min_blooming_day
        high = max_blooming_day
        result = float('inf')
        while low <= high:
            mid = low + (high - low) // 2
            flowers = 0
            bouquets = 0
            for val in bloomDay:a
                if mid >= val:
                    flowers += 1
                else:
                    flowers = 0
                if flowers == k:
                    bouquets += 1
                    flowers = 0
            if bouquets >= m:
                result = min(result, mid)
                high = mid - 1
            else:
                low = mid + 1
        return result
