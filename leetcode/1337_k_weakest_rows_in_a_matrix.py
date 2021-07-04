class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        heap = []
        for idx, row in enumerate(mat):
            curr_count = 0
            for idx2, col in enumerate(row):
                if col == 1:
                    curr_count += 1
                else:
                    break
            heapq.heappush(heap, (-1 * curr_count, -1 * idx))
            if len(heap) > k:
                heapq.heappop(heap)
        heap = sorted(heap, key=lambda item: (-1 * item[0], -1 * item[1]))
        return list(map(lambda item: item[1] * -1, heap))
