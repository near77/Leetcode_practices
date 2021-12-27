class Solution:
    def findComplement(self, num: int) -> int:
        res = 0
        cnt = 0
        while num != 0:
            if num % 2 == 0:
                res += 2**cnt
            else:
                pass
            num //= 2
            cnt += 1
        return res
            