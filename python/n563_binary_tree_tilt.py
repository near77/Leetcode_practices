# Definition for a binary tree node.
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        self.DFS(root)
        node_q = [root]
        res = 0
        while len(node_q) != 0:
            node = node_q.pop(0)
            left_val = 0
            right_val = 0
            if node.left != None:
                left_val = node.left.val
                node_q.append(node.left)
            if node.right != None:
                right_val = node.right.val
                node_q.append(node.right)
            res += abs(left_val-right_val)
        return res
        
    def DFS(self, node):
        if node == None:
            return 0
        left_val = 0
        right_val = 0
        if node.left != None:
            left_val = self.DFS(node.left)
        if node.right != None:
            right_val = self.DFS(node.right)
        node.val = node.val + left_val + right_val
        return node.val