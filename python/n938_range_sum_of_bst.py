from typing import Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.res = 0
        self.low = low
        self.high = high
        self.DFS(root)
        return self.res
    def DFS(self, node):
        if node == None:
            return
        else:
            if node.val >= self.low and node.val <= self.high:
                self.res += node.val
            if node.val >= self.low:
                self.DFS(node.left)
            if node.val <= self.high:
                self.DFS(node.right)