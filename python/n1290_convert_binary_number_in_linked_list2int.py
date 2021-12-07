# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        res = 0
        node = head
        while node != None:
            res *= 2
            res += node.val
            node = node.next
        return res