from typing import List
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        return self.DFS(arr, start)
        
    def DFS(self, arr, start):
        if arr[start] == 0:
            return True
        elif arr[start] < 0:
            return False
        else:
            right = None
            left = None
            arr[start] = arr[start]*-1
            if start - arr[start] < len(arr):
                right = self.DFS(arr, start - arr[start])
            if start + arr[start] > -1:
                left = self.DFS(arr, start + arr[start])
            if right == None:
                return left
            if left == None:
                return right
            return left or right