from typing import List
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        cur_max = 0
        m = len(matrix)
        n = len(matrix[0])
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == "0":
                    continue
                else:
                    if j > n-cur_max:
                        break
                    x = 1
                    while i + x <= m and j + x <= n:
                        flg = False
                        for row in matrix[i:i+x]:
                            for idx in row[j:j+x]:
                                if idx == "0":
                                    flg = True
                                    break
                            if flg:
                                break
                        if not flg:
                            cur_max = max(cur_max, x)
                            x += 1
                        else:
                            break
            if i > m-cur_max:
                break
        return cur_max*cur_max