class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        occurrences = {}
        for c in s1:
            if c not in occurrences:
                occurrences[c] = 1
            else:
                occurrences[c] += 1
        l = 0
        r = 0
        n = len(s2)
        while r < n:
            counter = 0
            while r < n and occurrences.get(s2[r], 0) > 0:
                occurrences[s2[r]] -= 1
                counter += 1
                r += 1
            if counter == len(s1):
                return True
            if r >= n:
                break
            if l == r:
                r += 1
                l += 1
            else:
                occurrences[s2[l]] += 1
                l += 1
        if (r-l == len(s1)):
            return True
        return False
