# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l1 = self.reverse(l1)
        l2 = self.reverse(l2)
        return self.reverse(self.addTwoNumbers_recursive(l1, l2, 0))
    
    def reverse(self, head: ListNode):
        if head == None or head.next == None:
            return head
        p = self.reverse(head.next)
        head.next.next = head
        head.next = None
        return p
 
 
    def addTwoNumbers_recursive(self, l1: ListNode, l2: ListNode, carry: int):
        if l1 == None and l2 == None:
            if carry > 0:
                return ListNode(carry)
            else:
                return None
        elif l1 == None:    
            curr_sum = l2.val + carry
        elif l2 == None:
            curr_sum = l1.val + carry
        else:
            curr_sum = l1.val + l2.val + carry
        node = ListNode(curr_sum % 10)
        node.next = self.addTwoNumbers_recursive(l1.next if l1 != None else l1, l2.next if l2 != None else l2, curr_sum // 10)
        return node
 
