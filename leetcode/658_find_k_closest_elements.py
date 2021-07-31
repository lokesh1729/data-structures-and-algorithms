class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        mx_heap = []
        res = []
        for i in range(len(arr)):
            heapq.heappush(mx_heap, (-abs(arr[i] - x), -arr[i]))
            if len(mx_heap) > k:
                heapq.heappop(mx_heap)
        
        for i in range(len(mx_heap)):
            res.append(-heapq.heappop(mx_heap)[1])
            
        return sorted(res)

