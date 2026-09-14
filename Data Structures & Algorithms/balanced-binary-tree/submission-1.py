# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root==None:
            return True
        isB= True
        def recur(root):
            nonlocal isB
            if root==None:
                return 0
            ldepth=rdepth=0

            ldepth= recur(root.left)
            rdepth= recur(root.right)
            print(ldepth,rdepth)
            if ldepth-rdepth not in (-1,0,1):
                isB= False
            if ldepth>rdepth:
                return 1+ldepth
            else:
                return 1+rdepth
        # diff=recur(root.left)-recur(root.right)
        # return diff==-1 or diff==1 or diff==0 
        recur(root)
        return isB