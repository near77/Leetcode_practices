# Your interview score of 7.06/10 beats 72% of all users.
# Time Spent: 16 minutes 31 seconds
# Time Allotted: 1 hour
from typing import List
# Best Time to Buy and Sell Stock
# 211 / 211 Testcases Passed
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_cost = 10000
        res = 0
        for price in prices:
            if price-min_cost > res:
                res = price-min_cost
            if price < min_cost:
                min_cost = price
        return res

# Product of Array Except Self
# 20 / 20 Testcases Passed
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix_product = [0]*n
        surfix_product = [0]*n
        for i in range(n):
            if i == 0:
                prefix_product[i] = 1
            else:
                prefix_product[i] = prefix_product[i-1]*nums[i-1]
        for i in range(n-1, -1, -1):
            if i == n-1:
                surfix_product[i] = 1
            else:
                surfix_product[i] = surfix_product[i+1]*nums[i+1]
        res = []
        for i in range(n):
            res.append(prefix_product[i]*surfix_product[i])
        return res