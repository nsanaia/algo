"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        
        curr = head
        while curr:
            tmp = Node(curr.val, curr.next, curr.random)
            curr.next = tmp
            curr = tmp.next
        
        new_curr = head.next
        while new_curr:
            new_curr.random = new_curr.random.next if new_curr.random else None
            new_curr = new_curr.next.next if new_curr.next else None
        
        copy = Node(1)
        curr_copy = copy
        
        curr = head
        while curr:
            curr_copy.next = curr.next
            curr_copy = curr_copy.next
            
            curr.next = curr_copy.next
            curr = curr.next
            
        return copy.next