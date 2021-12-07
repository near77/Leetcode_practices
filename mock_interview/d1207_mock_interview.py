# Your interview score of 5.75/10 beats 59% of all users.
# Time Spent: 26 minutes 48 seconds
# Time Allotted: 1 hour
from typing import List
# n788 Rotated Digits
# 50 / 50 Testcases Passed
class Solution:
    def rotatedDigits(self, n: int) -> int:
        valid_digit = [0, 1, 2, 5, 6, 8, 9]
        rotate_digit = [2, 5, 6, 9]
        res = 0
        for i in range(n):
            num = i+1
            valid = True
            rotate = False
            while num != 0:
                if num%10 not in valid_digit:
                    valid = False
                    break
                else:
                    if num%10 in rotate_digit:
                        rotate = True
                num = num//10
            if valid and rotate:
                res += 1
        return res
# n849 Maximize Distance to Closest Person
# 81 / 81 Testcases Passed
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        non_empty_seats = []
        n = len(seats)
        for i in range(n):
            if seats[i] == 1:
                non_empty_seats.append(i)
        m = len(non_empty_seats)
        if m == 1:
            return max(n-1-non_empty_seats[0], non_empty_seats[0])
        else:
            front_end_dist = max(n-1-non_empty_seats[-1], non_empty_seats[0])
            max_distance = front_end_dist
            for i in range(1, m):
                max_distance = max(max_distance,non_empty_seats[i]-non_empty_seats[i-1])
            return max(max_distance//2, front_end_dist)