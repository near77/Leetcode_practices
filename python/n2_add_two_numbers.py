from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        node1 = l1
        node2 = l2
        pls = False
        while node1 != None and node2 != None:
            node1.val += node2.val
            if pls:
                node1.val += 1
                pls = False
            if node1.val > 9:
                node1.val -= 10
                pls = True
            if node1.next == None:
                if node2.next != None:
                    node1.next = node2.next
                    node1 = node1.next
                    print(node1.val)
                else:
                    if pls:
                        tmp = ListNode(0, None)
                        node1.next = tmp
                        node1 = node1.next
                break
            node1 = node1.next
            node2 = node2.next
        while node1 != None:
            if pls:
                node1.val += 1
                pls = False
            if node1.val > 9:
                node1.val -= 10
                pls = True
            if node1.next == None and pls:
                tmp = ListNode(0, None)
                node1.next = tmp
            node1 = node1.next
        return l1

if __name__ == "__main__":
    s = Solution()