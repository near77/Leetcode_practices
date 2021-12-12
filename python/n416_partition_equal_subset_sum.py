from typing import List
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sum_of_nums = sum(nums)
        if sum_of_nums%2 != 0:
            return False
        else:
            target = sum_of_nums/2
            possible_sums = {0:True}
            for num in nums:
                possible_sums |= {num+i:True for i in possible_sums}
            return target in possible_sums

# Recursion TLE
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sum_of_nums = sum(nums)
        if sum_of_nums%2 != 0:
            return False
        else:
            self.half_sum = sum_of_nums/2
            return self.DFS(nums, 0, 0)
    def DFS(self, nums, idx, cur_sum):
        if idx >= len(nums):
            return False
        if cur_sum + nums[idx] == self.half_sum:
            return True
        else:
            return self.DFS(nums, idx+1, cur_sum) or self.DFS(nums, idx+1, cur_sum+nums[idx])