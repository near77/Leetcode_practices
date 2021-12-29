from typing import Optional
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return root
        current_floor = [root]
        next_floor= []
        previous_node = None
        while len(current_floor) > 0:
            node = current_floor.pop(0)
            if previous_node != None:
                previous_node.next = node
            previous_node = node
            if node.left:
                next_floor.append(node.left)
            if node.right:
                next_floor.append(node.right)
            if len(current_floor) == 0:
                previous_node = None
                node.next = None
                current_floor = next_floor
                next_floor = []
        return root
                