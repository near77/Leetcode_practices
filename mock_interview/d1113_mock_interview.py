# Your interview score of 5.36/10 beats 53% of all users.
# Time Spent: 48 minutes 49 seconds
# Time Allotted: 1 hour
from typing import *
# n859. Buddy Strings
# 34 / 34 Testcases Passed
class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        diff_chr_s = []
        diff_chr_g = []
        s_chr_cnt = {}
        s_has_dup_char = False
        for chr_s, chr_g in zip(s, goal):
            s_chr_cnt[chr_s] = s_chr_cnt.get(chr_s, 0) + 1
            if s_chr_cnt[chr_s] > 1:
                s_has_dup_char = True
            if chr_s != chr_g:
                diff_chr_s.append(chr_s)
                diff_chr_g.append(chr_g)
        if len(diff_chr_s) == 2 and len(diff_chr_s) == len(diff_chr_g):
            for char in diff_chr_s:
                if char not in diff_chr_g:
                    return False
            return True
        else:
            if s == goal and s_has_dup_char:
                return True
            return False

# n1329. Sort the Matrix Diagonally
# 15 / 15 Testcases Passed
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])
        l = max(m, n)
        s = 0
        for i in range(-m+1, n):
            tmp = []
            if i < 0:
                s = abs(i)
            else:
                s = 0
            for j in range(0, l):
                if j < m and j + i < n and j + i >= 0:
                    tmp.append(mat[j][j+i])
            tmp.sort()
            idx = 0
            for j in range(0, l):
                if j < m and j + i < n and j + i >= 0:
                    mat[j][j+i] = tmp[idx]
                    idx += 1
        return mat