# Definition for singly-linked list with a random pointer.
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        if head is None:
            return None
        old2new = {}
        newhead = RandomListNode(head.label)
        old2new[head]=newhead
        old,new = head,newhead
        while old is not None:
            if old.next is None:
                new.next = None
            elif old.next in old2new:
                new.next = old2new[old.next]
            else:
                new.next = RandomListNode(old.next.label)
                old2new[old.next]=new.next

            if old.random is None:
                new.random = None
            elif old.random in old2new:
                new.random = old2new[old.random]
            else:
                new.random = RandomListNode(old.random.label)
                old2new[old.random]=new.random
            old = old.next
            new = new.next
        return newhead

if __name__=="__main__":
    s=Solution()
    N = RandomListNode
    l = s.copyRandomList(N(1))
