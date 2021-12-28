from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        one_step_node = head
        two_step_node = head
        while two_step_node != None and two_step_node.next != None:
            one_step_node = one_step_node.next
            two_step_node = two_step_node.next.next
        return one_step_node