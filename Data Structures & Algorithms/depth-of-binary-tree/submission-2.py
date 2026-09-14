# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root==None:
            return 0
        ldepth=rdepth=0
        
        ldepth= self.maxDepth(root.left)
        rdepth= self.maxDepth(root.right)
        if ldepth>rdepth:
            print(1+ldepth)
            return 1+ldepth
        else:
            print(1+rdepth)
            return 1+rdepth