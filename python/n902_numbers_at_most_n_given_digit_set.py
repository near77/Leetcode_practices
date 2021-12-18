from typing import List
class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        tmp = n
        n_digit_stack = []
        while tmp != 0:
            n_digit_stack.append(tmp % 10)
            tmp //= 10
        n_digits = len(n_digit_stack)
        m = len(digits)
        res = 0
        for i in range(n_digits):
            res += m**(i+1)
        flg = True
        while len(n_digit_stack) > 0:
            cur_digit = n_digit_stack.pop()
            idx = -1
            next_flg = False
            for i in range(m):
                if int(digits[i]) == cur_digit:
                    next_flg = True
                if int(digits[i]) > cur_digit:
                    idx = i
                    break
            if flg and idx != -1:
                res -= (m-idx)*(m**len(n_digit_stack))
            flg = flg and next_flg
            
        return res