# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None:
            return
        p=None
        c=head
        n=head.next
        while c!=None:
            c.next=p
            p=c
            c=n
            if n!=None:
                n=n.next
            else: 
                n=None
        return p