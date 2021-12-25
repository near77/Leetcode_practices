def calculate(self, s: str) -> int:
        res = []
        cur_int = 0
        sign = "+"
        s.replace(" ", "")
        n = len(s)
        for i in range(n):
            if s[i].isdigit():
                cur_int *= 10
                cur_int += int(s[i])
            if s[i] in "+-*/" or i == n-1:
                if sign == "+":
                    res.append(cur_int)
                elif sign == "-":
                    res.append(-cur_int)
                elif sign == "*":
                    cur_int *= res.pop()
                    res.append(cur_int)
                else:
                    cur_int = int(res.pop()/cur_int)
                    res.append(cur_int)
                sign = s[i]
                cur_int = 0
        return sum(res)