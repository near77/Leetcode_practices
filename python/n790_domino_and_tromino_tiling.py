class Solution:
    def numTilings(self, n: int) -> int:
        if n < 3:
            return n
        else:
            if n == 3:
                return 5
            a = [0]*n
            a[0] = 1
            a[1] = 2
            a[2] = 5
            for i in range(3, n):
                a[i] = (a[i-1]*2 + a[i-3])%(10**9+7)
            return a[n-1]