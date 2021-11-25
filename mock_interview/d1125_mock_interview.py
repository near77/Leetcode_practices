# Your interview score of 4.95/10 beats 70% of all users.
# Time Spent: 50 minutes 56 seconds
# Time Allotted: 1 hour
from typing import List
# n1 Two Sum
# 57 / 57 Testcases Passed
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {}
        for idx in range(len(nums)):
            if num_map.get(target - nums[idx], -1) != -1:
                return [num_map[target - nums[idx]], idx]
            num_map[nums[idx]] = idx
# n957 Prison Cells After N Days
# 267 / 267 Testcases Passed
class Solution:
    def prisonAfterNDays(self, cells: List[int], n: int) -> List[int]:
        old_state = cells.copy()
        new_state = cells.copy()
        new_state[0] = 0
        new_state[-1] = 0
        n = n % 14
        n += 14
        for i in range(n):
            for j in range(0, 6):
                new_state[j + 1] = int(not (old_state[j]^old_state[j + 2]))
            old_state = new_state.copy()
        return new_state