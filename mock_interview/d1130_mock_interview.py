# Your interview score of 6.60/10 beats 72% of all users.
# Time Spent: 22 minutes 54 seconds
# Time Allotted: 1 hour
from typing import List
# n1051 Height Checker
# 81 / 81 Testcases Passed
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        sorted_heights = sorted(heights)
        n = len(heights)
        res = 0
        for i in range(n):
            if sorted_heights[i] != heights[i]:
                res += 1
        return res
# n925 Long Pressed Name
# 94 / 94 Testcases Passed
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        n = len(name)
        m = len(typed)
        if n > m:
            return False
        i = 0
        j = 0
        while i < n:
            name_cnt = 0
            typed_cnt = 0
            current_char = name[i]
            while name[i] == current_char:
                name_cnt += 1
                i += 1
                if i == n:
                    break
            if j >= m:
                return False
            while typed[j] == current_char:
                typed_cnt += 1
                j += 1
                if j == m:
                    break
            if typed_cnt < name_cnt:
                return False
        if j == m:
            return True
        else:
            return False