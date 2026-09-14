# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        max=0
        def height(root):
            nonlocal max
            if root==None:
                return 0
            ldepth=rdepth=0

            ldepth= height(root.left)
            rdepth= height(root.right)
            if (1+ldepth+rdepth)>max:
                max=ldepth+rdepth
            if ldepth>rdepth:
                return 1+ldepth
            else:
                return 1+rdepth
        height(root)
        return max