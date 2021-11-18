from typing import List
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for num in nums:
            if num < 0:
                idx = num * -1 - 1
            else:
                idx = num - 1
            if nums[idx] > 0:
                nums[idx] *= -1
        ans = []
        for i in range(len(nums)):
            if nums[i] > 0:
                ans.append(i+1)
        return ans