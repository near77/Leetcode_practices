# Your interview score of 8.87/10 beats 91% of all users.
# Time Spent: 6 minutes 21 seconds
# Time Allotted: 1 hour
from typing import List
# Fibonacci Number
# 31 / 31 Testcases Passed
class Solution:
    def fib(self, n: int) -> int:
        if n < 2:
            return n
        else:
            return self.fib(n-1) + self.fib(n-2)
# Distribute Candies
# 206 / 206 Testcases Passed
class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        candy_cnt = {}
        cnt = 0
        for candy in candyType:
            if candy_cnt.get(candy, 0) == 0:
                candy_cnt[candy] = 1
                cnt += 1
        return min(len(candyType)//2, cnt)