class Solution:
    def maxPower(self, s: str) -> int:
        cur_char = "1"
        res = 0
        cnt = 0
        for char in s:
            if char != cur_char:
                res = max(res, cnt)
                cnt = 1
                cur_char = char
            else:
                cnt += 1
        res = max(res, cnt)
        return res
        