from typing import *
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        l = len(nums)
        if l < 3:
            return []
        nums.sort()
        answer = []
        for i in range(l-2):
            if i > 0:
                if nums[i] == nums[i-1]:
                    continue
            j = i + 1
            k = l - 1
            while j < k:
                if nums[j] + nums[k] == -nums[i]:
                    if j-1 > i and nums[j] == nums[j-1]:
                        pass
                    else:
                        answer.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                elif nums[j] + nums[k] > -nums[i]:
                    k -= 1
                else:
                    j += 1
        return answer

if __name__ == "__main__":
    s = Solution()
    print(s.threeSum([-2,0,0,2,2]))