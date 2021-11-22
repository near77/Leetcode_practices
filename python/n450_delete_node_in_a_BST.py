from typing import Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        node = root
        tprev_node = None
        while node != None:
            if node.val == key:
                if node.right != None:
                    # traverse right tree find the smallest element
                    prev_node = node
                    replace_node = node.right
                    while replace_node.left != None:
                        prev_node = replace_node
                        replace_node = replace_node.left
                    if prev_node == node:
                        prev_node.right = replace_node.right
                    else:
                        prev_node.left = replace_node.right
                    node.val = replace_node.val
                elif node.left != None:
                    # traverse left tree find the biggest element
                    prev_node = node
                    replace_node = node.left
                    while replace_node.right != None:
                        prev_node = replace_node
                        replace_node = replace_node.right
                    if prev_node == node:
                        prev_node.left = replace_node.left
                    else:
                        prev_node.right = replace_node.left
                    node.val = replace_node.val
                else:
                    if node == root:
                        root = None
                    else:
                        if tprev_node.left != None:
                            if tprev_node.left.val == key:
                                tprev_node.left = None
                        if tprev_node.right != None:
                            if tprev_node.right.val == key:
                                tprev_node.right = None      
                    node = None
            elif node.val > key:
                tprev_node = node
                node = node.left
            else:
                tprev_node = node
                node = node.right
        return root
