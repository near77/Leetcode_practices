from typing import Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        return max(self.DFS(root))
    def DFS(self, node):
        if node.left == None and node.right == None:
            return (0, node.val)
        elif node.left == None:
            rob_right = self.DFS(node.right)
            return (max(rob_right), node.val+rob_right[0])
        elif node.right == None:
            rob_left = self.DFS(node.left)
            return (max(rob_left), node.val+rob_left[0])
        else:
            rob_left = self.DFS(node.left)
            rob_right = self.DFS(node.right)
            return (max(rob_left)+max(rob_right), node.val+rob_left[0]+rob_right[0])
            