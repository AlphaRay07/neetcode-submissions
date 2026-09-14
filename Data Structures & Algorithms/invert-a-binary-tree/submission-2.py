# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root==None: return None
        q=deque()
        q.append(root)
        while q:
            x=q.popleft()
            x.left,x.right=x.right,x.left
            if(x.left):
                q.append(x.left)
            if(x.right):
                q.append(x.right)
        return root