from collections import deque

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        h=defaultdict(lambda: None)
        if node==None:
            return None
        if len(node.neighbors)==0:
            return Node(1)
        q= deque()
        q.append(node)
        while q:
            x=q.popleft()
            if h[x]==None:
                clone= Node(x.val)
                h[x]=clone
            for i in x.neighbors:
                if h[i]!=None:
                    h[x].neighbors.append(h[i])
                else:
                    c= Node(i.val)
                    h[i]=c
                    h[x].neighbors.append(h[i])
                    q.append(i)
        return h[node]