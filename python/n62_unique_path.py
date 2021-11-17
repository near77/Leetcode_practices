class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        x = 1
        y = 1
        z = 1
        for i in range(1, m+n-1):
            x *= i
        for i in range(1, m):
            y *= i
        for i in range(1, n):
            z *= i
        return int(x/(y*z))