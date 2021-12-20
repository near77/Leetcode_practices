from typing import List
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        n = len(arr)
        res = []
        min_diff = 2000000
        for i in range(1, n):
            diff = arr[i] - arr[i-1]
            if diff < min_diff:
                res = [[arr[i-1], arr[i]]]
                min_diff = diff
            elif diff == min_diff:
                res.append([arr[i-1], arr[i]])
            else:
                continue
        return res