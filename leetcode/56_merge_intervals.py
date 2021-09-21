class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return intervals
        intervals.sort(key=lambda item: item[0])
        START = 0
        END = 1
        curr_max_start = intervals[0][START]
        curr_max_end = intervals[0][END]
        result = []
        for i in range(1, len(intervals)):
            if intervals[i][START] > curr_max_end:
                result.append([curr_max_start, curr_max_end])
                curr_max_start = intervals[i][START]
                curr_max_end = intervals[i][END]
            else:
                curr_max_end = max(curr_max_end, intervals[i][END])
        result.append([curr_max_start, curr_max_end])
        return result
