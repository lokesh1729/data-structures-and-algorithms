class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        n = len(s)
        l = 0
        r = 0
        last_partition_idx = 0
        result = []
        idx_mapping = {}
        for idx in range(n):
            idx_mapping[s[idx]] = idx
        while r < n and l < n:
            curr_idx = idx_mapping[s[l]]
            if curr_idx > r:
                r = curr_idx
            if l == r:
                result.append(r - last_partition_idx + 1)
                last_partition_idx = l + 1
            l += 1
        return result
