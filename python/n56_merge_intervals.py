from typing import List
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        n = len(intervals)
        start = -1
        end = -1
        res = []
        for i in range(n):
            if start == -1:
                start = intervals[i][0]
                end = intervals[i][1]
            else:
                if intervals[i][0] <= end:
                    end = max(end, intervals[i][1])
                else:
                    res.append([start, end])
                    start = intervals[i][0]
                    end = intervals[i][1]
        res.append([start, end])
        return res