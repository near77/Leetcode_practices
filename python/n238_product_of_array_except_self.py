from typing import List
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix_products = [0]*n
        surfix_products = [0]*n
        answer = []
        for i in range(n):
            if i == 0:
                prefix_products[i] = 1
            else:
                prefix_products[i] = prefix_products[i-1]*nums[i-1]
        for i in range(n):
            if i == 0:
                surfix_products[n-1-i] = 1
            else:
                surfix_products[n-1-i] = surfix_products[n-i]*nums[n-i]
        for i in range(n):
            answer.append(prefix_products[i]*surfix_products[i])
        
        return answer
        
        