from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        node_stack = []
        ptr1 = head
        ptr2 = head
        while ptr2 != None and ptr2.next != None:
            ptr2 = ptr2.next.next
            ptr1 = ptr1.next
        mid_node = ptr1
        while ptr1 != None:
            node_stack.append(ptr1)
            ptr1 = ptr1.next
        node = head
        while len(node_stack):
            new_node = node_stack.pop()
            next_node = node.next
            node.next = new_node
            if new_node == mid_node:
                node.next.next = None
            else:
                node.next.next = next_node
            node = next_node
        return head