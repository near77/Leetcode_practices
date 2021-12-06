# Your interview score of 7.11/10 beats 76% of all users.
# Time Spent: 14 minutes 53 seconds
# Time Allotted: 1 hour
from typing import Optional, List
# n345 Reverse Vowels of a String
# 480 / 480 Testcases Passed
class Solution:
    def reverseVowels(self, s: str) -> str:
        vow_idx = []
        vow_stack = []
        vows = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
        idx = 0
        for char in s:
            if char in vows:
                vow_stack.append(char)
                vow_idx.append(idx)
            idx += 1
        
        n = len(s)
        v_idx = 0
        res = ""
        m = len(vow_idx)
        for i in range(n):
            if v_idx < m:
                if i == vow_idx[v_idx]:
                    res += vow_stack.pop()
                    v_idx += 1
                else:
                    res += s[i]
            else:
                res += s[i]
        return res

# n515 Find Largest Value in Each Tree Row
# 78 / 78 Testcases Passed
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        else:
            current_layer = [root]
            res = [root.val]
            next_layer = []
            while len(current_layer) != 0:
                node = current_layer.pop(0)
                if node.left != None:
                    next_layer.append(node.left)
                if node.right != None:
                    next_layer.append(node.right)
                if len(current_layer) == 0:
                    current_layer = next_layer.copy()
                    if len(next_layer) != 0:
                        res.append(max([n.val for n in next_layer]))
                    next_layer = []
            return res