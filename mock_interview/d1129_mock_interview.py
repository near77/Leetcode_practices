# Your interview score of 4.88/10 beats 55% of all users.
# Time Spent: 38 minutes 16 seconds
# Time Allotted: 1 hour
from typing import List
# Remove Element
# 113 / 113 Testcases Passed
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        j = len(nums)
        while i < j:
            if nums[i] == val:
                nums.pop(i)
                nums.append(val)
                j -= 1
            else:
                i += 1
        return j
# Combination Sum
# 170 / 170 Testcases Passed
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.res = []
        self.target = target
        for i in range(len(candidates)):
            if candidates[i] == target:
                self.res.append([candidates[i]])
            else:
                self.dfs(candidates[i], [candidates[i]], candidates[i:])
        return self.res
    
    def dfs(self, cur_sum, cur_candidate, candidates):
        for i in range(len(candidates)):
            candidate = candidates[i]
            tmp_candidate = cur_candidate.copy()
            tmp_candidate.append(candidate)
            if cur_sum + candidate == self.target:
                self.res.append(tmp_candidate)
            elif cur_sum + candidate < self.target:
                self.dfs(cur_sum + candidate, tmp_candidate, candidates[i:])
            else:
                continue