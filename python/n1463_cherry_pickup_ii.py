from typing import List

# TLE
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        self.n = len(grid)
        self.m = len(grid[0])
        self.res = 0
        self.traversed_idx = {}
        self.dfs(grid, 0, 0, self.m-1, 0)
        return self.res
    
    def dfs(self, grid, row, col_1, col_2, cur_val):
        if col_1 == col_2:
            cur_val += grid[row][col_1]
        else:
            cur_val += grid[row][col_1] + grid[row][col_2]
        key = f"{row}_{col_1}_{col_2}_{cur_val}"
        if self.traversed_idx.get(key, False):
            return
        self.traversed_idx[key] = True
        self.res = max(self.res, cur_val)
        if row == self.n-1:
            return
        else:
            for nc1 in range(max(0, col_1-1), min(self.m-1, col_1+1)+1):
                for nc2 in range(max(0, col_2-1), min(self.m-1, col_2+1)+1):
                    self.dfs(grid, row+1, nc1, nc2, cur_val)