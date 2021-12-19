class Solution:
    def decodeString(self, s: str) -> str:
        res = self.dfs(s, 0, len(s))
        return res
                
    def dfs(self, s, start, end):
        res = ""
        num = ""
        numeric_flg = False
        tmp = -1
        for i in range(start, end):
            if tmp != -1 and i <= tmp:
                continue
            tmp = -1
            if s[i].isnumeric():
                num += s[i]
            else:
                if s[i] == "[":
                    quote_stack = ["["]
                    tmp = i
                    while len(quote_stack) != 0:
                        tmp += 1
                        if s[tmp] == "]":
                            quote_stack.pop()
                        elif s[tmp] == "[":
                            quote_stack.append("[")
                    res += int(num)*self.dfs(s, i+1, tmp)
                    num = ""
                else:
                    res += s[i]
        return res